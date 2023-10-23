/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2023 Audiokinetic Inc.
*******************************************************************************/

/// \file
/// Software source plug-in and effect plug-in interfaces.

#ifndef _IAK_PLUGIN_H_
#define _IAK_PLUGIN_H_

#include <AK/SoundEngine/Common/AkCommonDefs.h>
#include <AK/SoundEngine/Common/IAkRTPCSubscriber.h>
#include <AK/SoundEngine/Common/IAkPluginMemAlloc.h>
#include <AK/SoundEngine/Common/AkFPUtilities.h>
#include <AK/Tools/Common/AkLock.h>
#include <AK/Tools/Common/AkPlatformFuncs.h>
#include <AK/Tools/Common/AkMonitorError.h>
#include <AK/Tools/Common/AkRng.h>
#include <AK/SoundEngine/Common/AkSoundEngineExport.h>
#include <AK/SoundEngine/Common/IAkProcessorFeatures.h>
#include <AK/SoundEngine/Common/IAkPlatformContext.h>
#include <AK/SoundEngine/Common/AkMidiTypes.h>
#include <AK/SoundEngine/Common/AkCallback.h>
#include <AK/AkWwiseSDKVersion.h>

#include <math.h>

#if defined AK_CPU_X86  || defined AK_CPU_X86_64 || defined (AK_CPU_WASM)
#include <xmmintrin.h>
#endif

/// Plug-in information structure.
/// \remarks The bIsInPlace field is only relevant for effect plug-ins.
/// \sa
/// - \ref iakeffect_geteffectinfo
struct AkPluginInfo
{
	/// Constructor for default values
	AkPluginInfo()
		: eType(AkPluginTypeNone)
		, uBuildVersion( 0 )
		, bIsInPlace(true)
		, bCanChangeRate(false)
		, bReserved(false)
		, bCanProcessObjects(false)
		, bIsDeviceEffect(false)
		, bCanRunOnObjectConfig(true)
		, bUsesGainAttribute(false)
	{}

	AkPluginType eType;            ///< Plug-in type
	AkUInt32	 uBuildVersion;	   ///< Plug-in build version, must match the AK_WWISESDK_VERSION_COMBINED macro from AkWwiseSDKVersion.h.  Prevents usage of plugins compiled for other versions, avoiding crashes or data issues.
	bool         bIsInPlace; 	   ///< Buffer usage (in-place or not). If true, and the plug-in is an insert effect, it should implement IAkInPlaceEffectPlugin, otherwise it should implement IAkOutOfPlaceEffectPlugin. If it is an object processor (see CanProcessObjects, below), it should implement IAkInPlaceObjectPlugin or IAkOutOfPlaceObjectPlugin respectively.
	bool         bCanChangeRate;   ///< True for effects whose sample throughput is different between input and output. Effects that can change rate need to be out-of-place (!bIsInPlace), and cannot exist on busses.
	bool         bReserved;        ///< Legacy bIsAsynchronous plug-in flag, now unused. Preserved for plug-in backward compatibility. bReserved should be false for all plug-in.
	bool         bCanProcessObjects;    ///< Plug-in can process audio objects. They must implement IAkInPlaceObjectPlugin or IAkOutOfPlaceObjectPlugin, depending on if they work in-place or out-of-place. Out-of-place object processors only work on busses.
	bool         bIsDeviceEffect;		///< Plug-in can process final mixes and objects right before sending them to the audio device for output. Plug-ins that process the main mix, passthrough mix and objects directly at the end of the pipeline must implement IAkAudioDeviceEffectPlugin. Audio device effect plug-ins must be in place (bIsInPlace = true) and must be able to process objects (bCanProcessObjects = true).
	bool         bCanRunOnObjectConfig; ///< Plug-in can run on bus with Audio Object configuration. Effect plug-ins are instantiated once per Audio Objects on those busses. While this may be fine for effects such as EQs, it is an user error for effects such as reverbs, or for any effect that is non-linear. Effects that return false will fail to initialize when created on busses with Audio Object Configuration. 
	bool         bUsesGainAttribute;    ///< Plug-in knows how to process objects separately from the cumulativeGain of the object (or the processing of the object's audio is independent of the overall object gain). bCanProcessObjects must also be true, as this relies on Object Metadata.
};

//Forward declarations.
namespace AK
{
	class PluginRegistration;
}
extern "C" AK_DLLEXPORT AK::PluginRegistration * g_pAKPluginList;

struct AkAcousticTexture;

namespace AK
{
	class IAkStreamMgr;
	class IAkGlobalPluginContext;

	/// Game object information available to plugins.
	class IAkGameObjectPluginInfo
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkGameObjectPluginInfo(){}

	public:

		/// Get the ID of the game object.
		virtual AkGameObjectID GetGameObjectID() const = 0;

		/// Retrieve the number of emitter-listener pairs (rays) of the game object.
		/// A game object may have more than one position, and be listened to more than one listener.
		/// The returned value is the product of these two numbers. Use the returned value as a higher
		/// bound for the index of GetEmitterListenerPair().
		/// Note that rays whose listener is irrelevant to the current context are ignored. For example,
		/// if the calling plug-in exists on a bus, only listeners that are routed to the end point's
		/// device are considered.
		/// \sa
		/// - AK::SoundEngine::SetPosition()
		/// - AK::SoundEngine::SetMultiplePositions()
		/// - AK::SoundEngine::SetListeners()
		/// - AK::IAkGameObjectPluginInfo::GetEmitterListenerPair()
		virtual AkUInt32 GetNumEmitterListenerPairs() const = 0;

		/// Retrieve the emitter-listener pair (ray) of the game object at index in_uIndex.
		/// Call GetNumEmitterListenerPairs() prior to this function to get the total number of
		/// emitter-listener pairs of the game object.
		/// The emitter-listener pair is expressed as the game object's position relative to the
		/// listener, in spherical coordinates.
		/// \note
		/// - The distance takes game object and listener scaling factors into account.
		/// - Returned distance and angles are those of the game object, and do not necessarily correspond
		/// to any sound's positioning data.
		/// \return AK_Fail if the index is invalid, AK_Success otherwise.
		/// \sa
		/// - AK::SoundEngine::SetScalingFactor()
		/// - AK::IAkGameObjectPluginInfo::GetNumEmitterListenerPairs()
		virtual AKRESULT GetEmitterListenerPair(
			AkUInt32 in_uIndex,				///< Index of the pair, [0, GetNumEmitterListenerPairs()[
			AkEmitterListenerPair & out_emitterListenerPair	///< Returned relative source position in spherical coordinates.
			) const = 0;

		/// Get the number of positions of the game object. Use this value to determine the indices to be
		/// passed to GetGameObjectPosition().
		/// \sa
		/// - AK::SoundEngine::SetPosition()
		/// - AK::SoundEngine::SetMultiplePositions()
		/// - AK::IAkGameObjectPluginInfo::GetGameObjectPosition();
		virtual AkUInt32 GetNumGameObjectPositions() const = 0;

		/// Get the raw position of the game object at index in_uIndex.
		/// Use GetNumGameObjectPositions() prior to this function to get the total number of positions
		/// of that game object.
		/// \return AK_Fail if the index is out of bounds, AK_Success otherwise.
		/// \sa
		/// - AK::SoundEngine::SetPosition()
		/// - AK::SoundEngine::SetMultiplePositions()
		/// - AK::IAkGameObjectPluginInfo::GetNumGameObjectPositions()
		virtual AKRESULT GetGameObjectPosition(
			AkUInt32 in_uIndex,				///< Index of the position, [0, GetNumGameObjectPositions()[
			AkSoundPosition & out_position	///< Returned raw position info.
			) const = 0;

		/// Get the multi-position type assigned to the game object.
		/// \return MultiPositionType_MultiSources when the effect is instantiated on a bus.
		/// \sa
		/// - AK::SoundEngine::SetPosition()
		/// - AK::SoundEngine::SetMultiplePositions()
		virtual SoundEngine::MultiPositionType GetGameObjectMultiPositionType() const = 0;

		/// Get the distance scaling factor of the associated game object.
		/// \sa
		/// - AK::SoundEngine::SetScalingFactor()
		virtual AkReal32 GetGameObjectScaling() const = 0;

		/// Get the game object IDs of listener game objects that are listening to the emitter game object.
		/// Note that only listeners relevant to the current context are considered. For example,
		/// if the calling plug-in exists on a bus, only listeners that are routed to the end point's
		/// device are added to the returned array.
		/// \return True if the call succeeded, false if all the listeners could not fit into the array,
		/// \sa
		/// - AK::SoundEngine::SetListeners()
		virtual bool GetListeners( 
			AkGameObjectID* out_aListenerIDs,	///< Array of listener IDs to fill, or NULL to query the size needed.
			AkUInt32& io_uSize					///< In: max size of the array, out: number of valid elements returned in out_aListenerIDs.
			) const = 0;

		/// Get information about a listener. Use GetListeners() prior to this function
		/// in order to know which listeners are listening to the associated game object. 
		/// \return AK_Fail if the listener ID is invalid. AK_Success otherwise.
		/// \sa
		/// - AK::SoundEngine::SetListeners()
		/// - AK::IAkGameObjectPluginInfo::GetListeners()
		virtual AKRESULT GetListenerData(
			AkGameObjectID in_uListener,		///< Bit field identifying the listener for which you desire information.
			AkListener & out_listener			///< Returned listener info.
			) const = 0;

		/// Get the position of a distance probe associated with the given listener.
		/// Use GetListeners() prior to this function
		/// in order to know which listeners are listening to the associated game object. 
		/// Returns AK_Success if a distance probe is associated with the specified listener.
		/// If no distance probe game object is associated with the specified listener,
		/// or the listener is not valid, AK_Fail is returned.
		/// - AK::SoundEngine::SetDistanceProbe()
		/// - AK::SoundEngine::SetListeners()
		/// - AK::IAkGameObjectPluginInfo::GetListeners()
		virtual AKRESULT GetDistanceProbe(
			AkGameObjectID in_uListener, ///< Listener Game Object
			AkWorldTransform& out_position	 ///< Returned raw position info.
			) const = 0;
	};

	/// Voice-specific information available to plug-ins. 
	class IAkVoicePluginInfo
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkVoicePluginInfo(){}

	public:

		/// Retrieve the Playing ID of the event corresponding to this voice (if applicable).
		virtual AkPlayingID GetPlayingID() const = 0;

		/// Get priority value associated to this voice. When priority voice is modified by distance, the minimum distance among emitter-listener pairs is used.
		/// \return The priority between AK_MIN_PRIORITY and AK_MAX_PRIORITY inclusively.
		virtual AkPriority GetPriority() const = 0;

		/// Get priority value associated to this voice, for a specified distance, which may differ from the minimum distance that is used by default.
		/// \return The priority between AK_MIN_PRIORITY and AK_MAX_PRIORITY inclusively.
		virtual AkPriority ComputePriorityWithDistance(
			AkReal32 in_fDistance				///< Distance.
			) const = 0;
	};

	/// Interface to retrieve contextual information available to all types of plugins.
	class IAkPluginContextBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkPluginContextBase(){}

	public:

		/// \return The global sound engine context.
		/// \sa IAkGlobalPluginContext
		virtual IAkGlobalPluginContext* GlobalContext() const = 0;

		/// Obtain the interface to access the game object on which the plugin is instantiated.
		/// \return The interface to GameObject info, nullptr if undefined.
		virtual IAkGameObjectPluginInfo * GetGameObjectInfo() = 0;

		/// Identify the output device into which the data processed by this plugin will end up.
		/// Applicable to plug-ins instantiated as bus effects and to sink plugins.
		/// Plug-ins instantiated in the Actor-Mixer hierarchy (i.e. on voices) return AK_NotCompatible.
		/// \sa integrating_secondary_outputs
		/// \return The device type and unique identifier. AK_Success if successful, AK_NotCompatible otherwise.
		virtual AKRESULT GetOutputID(
			AkUInt32 &			out_uOutputID,		///< Device identifier, when multiple devices of the same type are possible.
			AkPluginID &		out_uDevicePlugin	///< Device plugin ID.
			) const = 0;

		/// Return the pointer and size of the plug-in media corresponding to the specified index.
		/// The pointer returned will be NULL if the plug-in media is either not loaded or inexistant.
		/// When this function is called and returns a valid data pointer, the data can only be used by this
		/// instance of the plugin and is guaranteed to be valid only during the plug-in lifespan.
		virtual void GetPluginMedia(
			AkUInt32 in_dataIndex,		///< Index of the plug-in media to be returned.
			AkUInt8* &out_rpData,		///< Pointer to the data
			AkUInt32 &out_rDataSize		///< size of the data returned in bytes.
			) = 0;

		/// Return the pointer and size of the game data corresponding to the specified index, sent by the game using AK::SoundEngine::SendPluginCustomGameData().
		/// The pointer returned will be NULL if the game data is inexistent.
		/// When this function is called and returns a valid data pointer, the data can only be used by this 
		/// instance of the plugin and is guaranteed to be valid only during the frame.
		virtual void GetPluginCustomGameData( 
			void* &out_rpData,			///< Pointer to the data
			AkUInt32 &out_rDataSize		///< size of the data returned in bytes.
			) = 0;

		/// Post a custom blob of data to the UI counterpart of this plug-in.
		/// Data is sent asynchronously through the profiling system.
		/// Notes:
		/// - You may call CanPostMonitorData() to determine if your plug-in can send data to the UI.
		/// - Data is copied into the communication buffer within this method,
		///		so you may discard it afterwards.
		/// - Sending data to the UI is only possible in Debug and Profile. Thus, you should
		///		enclose your calls to package and send that data within !AK_OPTIMIZED preprocessor flag.
		/// \return AK_Success if the plug-in exists on a bus, AK_Fail otherwise.
		virtual AKRESULT PostMonitorData(
			void *		in_pData,		///< Blob of data.
			AkUInt32	in_uDataSize	///< Size of data.
			) = 0;

		/// Query the context to know if it is possible to send data to the UI counterpart of this plug-in.
		/// \return True if the authoring tool is connected and monitoring the game, false otherwise.
		/// \sa PostMonitorData()
		virtual bool CanPostMonitorData() = 0;

		/// Post a monitoring message or error string. This will be displayed in the Wwise capture
		/// log.
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is
		///			called in the optimized/release configuration and return AK_NotCompatible.
		virtual AKRESULT PostMonitorMessage(
			const char* in_pszError,				///< Message or error string to be displayed
			AK::Monitor::ErrorLevel in_eErrorLevel	///< Specifies whether it should be displayed as a message or an error
			) = 0;

		/// Get the cumulative gain of all mixing stages, from the host audio node down to the device end point.
		/// Returns 1.f when the node is an actor-mixer (voice), because a voice may be routed to several mix chains.
		/// \return The cumulative downstream gain.
		virtual AkReal32 GetDownstreamGain() = 0;

		/// Return the channel configuration of the parent node that this plug-in will mix into.  GetParentChannelConfig() may be used to set the output configuration of an
		/// out-of-place effect to avoid additional up/down mixing stages.  Please note however that it is possible for out-of-place effects later in the chain to change
		/// this configuration.
		/// Returns not out_channelConfig.IsValid() when the node is an actor-mixer (voice), because a voice may be routed to several mix chains.
		/// \return AK_Success if the channel config of the primary, direct parent bus could be determined, AK_Fail otherwise.
		virtual AKRESULT GetParentChannelConfig(
			AkChannelConfig& out_channelConfig	///< Channel configuration of parent node (downstream bus).
			) const = 0;

		/// Return an interface to query processor specific features.
		virtual IAkProcessorFeatures * GetProcessorFeatures() = 0;

		/// Get internal ID of hosting sound structure (actor-mixer of bus).
		/// In the case of a voice, the ID is internal but corresponds to what you would get from the duration
		/// callback (see AkDurationCallbackInfo::audioNodeID). In the case of a bus, it can be matched with the bus name converted
		/// to a unique ID using AK::SoundEngine::GetIDFromString().
		/// In the case if an audio device (sink), it is AK_INVALID_UNIQUE_ID.
		/// \return ID of input.
		/// \sa
		///	- AkDurationCallbackInfo
		/// - AK::SoundEngine::PostEvent()
		/// - AK::SoundEngine::GetIDFromString()
		virtual AkUniqueID GetAudioNodeID() const = 0;

		/// Get the expected input of the audio device (sink) at the end of the bus pipeline from the caller's perspective.
		/// When called from a bus, the bus hierarchy is traversed upward until the master bus is reached. The audio device connected to this master bus is the sink consulted.
		/// When called from a source, the source's output bus is the starting point of the traversal.
		/// When called from a sink, that sink is consulted.
		/// \return AK_Success if the bus hierarchy traversal was successful and a sink was found, AK_Fail otherwise.
		virtual AKRESULT GetSinkChannelConfig(
			AkChannelConfig& out_sinkConfig,           // The channel config of the sink; if set to "Objects", then the sink is in 3D audio mode. Any other config means 3D audio is not active.
			Ak3DAudioSinkCapabilities& out_3dAudioCaps // When out_sinkConfig is set to Objects, inspect this struct to learn which 3D audio features are supported by the sink
		) const = 0;
	};

	/// Interface to retrieve contextual information for an effect plug-in.
	/// \sa
	/// - \ref iakmonadiceffect_init
	class IAkEffectPluginContext : public IAkPluginContextBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkEffectPluginContext(){}

	public:

		/// Determine whether the effect is to be used in Send Mode or not.
		/// Effects used in auxiliary busses are always used in Send Mode.
		/// \return True if the effect is in Send Mode, False otherwise
		virtual bool IsSendModeEffect() const = 0;

		/// Obtain the interface to access the voice in which the plugin is inserted.
		/// \return The interface to voice info. NULL if the plugin is instantiated on a bus.
		virtual IAkVoicePluginInfo * GetVoiceInfo() = 0;

		/// Obtain the interface to access services available on busses.
		/// \return The interface to mixing context if the plugin is instantiated on a bus. NULL if it is instantiated on a voice.
		virtual IAkMixerPluginContext* GetMixerCtx() = 0;

		/// \name For object processors:
		/// Output object management.
		//@{

		/// Create new objects on the output side. Only out-of-place object processors (plugins implementing AK::IAkOutOfPlaceObjectPlugin) may create output objects.
		/// If successful, the newly constructed objects will be available in out_ppBuffer/out_ppObjects. 
		/// To obtain all the output objects in a single array after having created objects using this function, use GetOutputObjects, or wait for the next call to AK::IAkOutOfPlaceObjectPlugin::Execute 
		/// where output objects are passed via the in_pObjectBuffersOut/in_pObjectsOut arguments.
		/// Object processors inform the host that an output object may be disposed of by setting its state to AK_NoMoreData from within AK::IAkOutOfPlaceObjectPlugin::Execute.
		/// \aknote You should never store the pointers returned by out_ppBuffer/out_ppObjects, as the location of pointed objects may change at each frame, or after subsequent calls to CreateOutputObjects.\endaknote
		/// \return AK_Success if all objects were created successfully, AK_Fail otherwise. 
		/// The optional arguments out_ppBuffer and out_ppObjects may be used to obtain the output objects newly created.
		/// \sa 
		/// - GetOutputObjects
		/// - AK::IAkOutOfPlaceObjectPlugin::Execute
		virtual AKRESULT CreateOutputObjects(
			AkChannelConfig in_channelConfig,	///< Desired channel configuration for all new objects.
			AkAudioObjects& io_objects		///< AkAudioObjects::uNumObjects, the number of objects to create.
												///< AkAudioObjects::ppObjectBuffers, Returned array of pointers to the object buffers newly created, allocated by the caller. Pass nullptr if they're not needed.
												///< AkAudioObjects::ppObjects, Returned array of pointers to the objects newly created, allocated by the caller. Pass nullptr if they're not needed.
		) = 0;

		/// Access the output objects. This function is helpful when CreateOutputObjects is called from within AK::IAkOutOfPlaceObjectPlugin::Execute.
		/// You need to allocate the array of pointers. You may prealably obtain the number of objects by calling this function with io_numObjects = 0.
		/// \aknote You should never store the pointers returned by GetOutputObjects, as the location of pointed objects may change at each frame, or after calls to CreateOutputObjects.\endaknote
		virtual void GetOutputObjects(
			AkAudioObjects& io_objects	///< AkAudioObjects::uNumObjects, The number of objects. If 0 is passed, io_objects::numObjects returns with the total number of objects.
											///< AkAudioObjects::ppObjectBuffers, Returned array of pointers to object buffers, allocated by the caller. The number of objects is the smallest between io_numObjects and the total number of objects.
											///< AkAudioObjects::ppObjects, Returned array of pointers to objects, allocated by the caller. The number of objects is the smallest between io_numObjects and the total number of objects.
		) = 0;

		//@}
	};

	/// Interface to retrieve contextual information for a source plug-in.
	/// \sa
	/// - \ref iaksourceeffect_init
	class IAkSourcePluginContext : public IAkPluginContextBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkSourcePluginContext(){}

	public:

		/// Retrieve the number of loops the source should produce.
		/// \return The number of loop iterations the source should produce (0 if infinite looping)
		virtual AkUInt16 GetNumLoops() const = 0;

		/// Obtain the interface to access the voice in which the plugin is inserted.
		/// \return The interface to voice info.
		virtual IAkVoicePluginInfo * GetVoiceInfo() = 0;

		/// Obtain the MIDI event info associated to the source.
		/// \return The MIDI event info.
		/// 
		virtual AkMIDIEvent GetMidiEvent() const = 0;

		/// Retrieve Cookie information for a Source Plugin
		/// \return the void pointer of the Cookie passed to the PostEvent 
		virtual void* GetCookie() const = 0;	

	};

	/// Interface to retrieve contextual information for a mixer.
	class IAkMixerPluginContext : public IAkPluginContextBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkMixerPluginContext(){}

	public:

		/// DEPRECATED.  
		/// Get the type of the bus on which the mixer plugin is instantiated.
		/// AkBusHierachyFlags is a bit field, indicating whether the bus is the master (top-level) bus or not,
		/// and whether it is in the primary or secondary mixing graph.
		/// \return The bus type.
		virtual AkUInt32 GetBusType() = 0;

		/// Get speaker angles of the specified device.
		/// The speaker angles are expressed as an array of loudspeaker pairs, in degrees, relative to azimuth ]0,180].
		/// Supported loudspeaker setups are always symmetric; the center speaker is always in the middle and thus not specified by angles.
		/// Angles must be set in ascending order.
		/// You may call this function with io_pfSpeakerAngles set to NULL to get the expected number of angle values in io_uNumAngles,
		/// in order to allocate your array correctly. You may also obtain this number by calling
		/// AK::GetNumberOfAnglesForConfig( AK_SPEAKER_SETUP_DEFAULT_PLANE ).
		/// If io_pfSpeakerAngles is not NULL, the array is filled with up to io_uNumAngles.
		/// Typical usage:
		/// - AkUInt32 uNumAngles;
		/// - GetSpeakerAngles( NULL, uNumAngles );
		/// - AkReal32 * pfSpeakerAngles = AkAlloca( uNumAngles * sizeof(AkReal32) );
		/// - GetSpeakerAngles( pfSpeakerAngles, uNumAngles );
		/// \warning Call this function only after the sound engine has been properly initialized.
		/// \return AK_Success if the end point device is properly initialized, AK_Fail otherwise.
		/// \sa AK::SoundEngine::GetSpeakerAngles()
		virtual AKRESULT GetSpeakerAngles(
			AkReal32 *			io_pfSpeakerAngles,			///< Returned array of loudspeaker pair angles, in degrees relative to azimuth [0,180]. Pass NULL to get the required size of the array.
			AkUInt32 &			io_uNumAngles,				///< Returned number of angles in io_pfSpeakerAngles, which is the minimum between the value that you pass in, and the number of angles corresponding to the output configuration, or just the latter if io_pfSpeakerAngles is NULL.
			AkReal32 &			out_fHeightAngle			///< Elevation of the height layer, in degrees relative to the plane.
			) = 0;

		/// \name Services.
		//@{

		/// Compute a direct speaker assignment volume matrix with proper downmixing rules between two channel configurations.
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// \aknote ComputePositioning is more general than this one, as it can also compute speaker gains for non-3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT ComputeSpeakerVolumesDirect(
			AkChannelConfig		in_inputConfig,				///< Channel configuration of the input.
			AkChannelConfig		in_outputConfig,			///< Channel configuration of the mixer output.
			AkReal32			in_fCenterPerc,				///< Center percentage. Only applies to mono inputs with standard output configurations that have a center channel.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes		///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
			) = 0;

		/// Compute a volume matrix given the position of the panner (Wwise 2D panner).
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// \aknote ComputePositioning is more general than this one, as it can also compute speaker gains for 3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT ComputeSpeakerVolumesPanner(
			AkSpeakerPanningType in_ePannerType,			///< Panner type
			const AkVector &	in_position,				///< x,y,z panner position [-1,1]. Note that z has no effect at the moment.
			AkReal32			in_fCenterPct,				///< Center percentage.
			AkChannelConfig		in_inputConfig,				///< Channel configuration of the input.
			AkChannelConfig		in_outputConfig,			///< Channel configuration of the mixer output.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes		///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
			) = 0;

		/// Compute panning gains on the plane given an incidence angle and channel configuration.
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// \aknote ComputePositioning is more general than this one, as it can also compute speaker gains for non-3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT ComputePlanarVBAPGains(
			AkReal32			in_fAngle,					///< Incident angle, in radians [-pi,pi], where 0 is the azimuth (positive values are clockwise)
			AkChannelConfig		in_outputConfig,			///< Desired output configuration.
			AkReal32			in_fCenterPerc,				///< Center percentage. Only applies to mono inputs to outputs that have no center.
			AK::SpeakerVolumes::VectorPtr out_vVolumes		///< Returned volumes (see AK::SpeakerVolumes::Vector services). Must be allocated prior to calling this function with the size returned by AK::SpeakerVolumes::Vector::GetRequiredSize() for the desired configuration.
			) = 0;

		/// Initialize spherical VBAP
		/// \return AK_Success if successful, AK_Fail otherwise.
		virtual AKRESULT InitSphericalVBAP(
			AK::IAkPluginMemAlloc* in_pAllocator,			///< Memory allocator
			const AkSphericalCoord* in_SphericalPositions, 	///< Array of points in spherical coordinate, representign the virtual position of each channels.
			const AkUInt32 in_NbPoints,						///< Number of points in the position array
			void *& out_pPannerData							///< Contains data relevant to the 3D panner that shoud be re-used accross plugin instances.
			) = 0;

		/// Compute panning gains on the plane given an incidence angle and channel configuration.
		/// \aknote ComputePositioning is more general than this one, as it handles spread and focus, and can also compute speaker gains for non-3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		virtual AKRESULT ComputeSphericalVBAPGains(
			void*				in_pPannerData,				///< Contains data relevant to the 3D panner that shoud be re-used accross plugin instances.
			AkReal32			in_fAzimuth,				///< Incident angle, in radians [-pi,pi], where 0 is the azimuth (positive values are clockwise)
			AkReal32			in_fElevation,				///< Incident angle, in radians [0,pi], where 0 is the elevation (positive values are clockwise)
			AkUInt32			in_uNumChannels,			///< Number of output channels.
			AK::SpeakerVolumes::VectorPtr out_vVolumes		///< Returned volumes (see AK::SpeakerVolumes::Vector services). Must be allocated prior to calling this function with the size returned by AK::SpeakerVolumes::Vector::GetRequiredSize() for the desired configuration.
			) = 0;

		/// Clear panner data obtained from InitSphericalVBAP().
		/// \return AK_Success if successful, AK_Fail otherwise.
		virtual AKRESULT TermSphericalVBAP(
			AK::IAkPluginMemAlloc*	in_pAllocator,			///< Memory allocator
			void*					in_pPannerData			///< Contains data relevant to the 3D panner that shoud be re-used accross plugin instances.
			) = 0;

		/// Compute standard 3D positioning.
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// \aknote The cartesian counterpart of Compute3DPositioning, that uses emitter and listener transforms, should be used instead of this function.
		/// It is more complete and more efficient. \endaknote
		/// \aknote ComputePositioning is more general than this one, as it can also compute speaker gains for non-3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT Compute3DPositioning(
			AkReal32			in_fAngle,					///< Incident angle, in radians [-pi,pi], where 0 is the azimuth (positive values are clockwise).
			AkReal32			in_fElevation,				///< Incident elevation angle, in radians [-pi/2,pi/2], where 0 is the horizon (positive values are above the horizon).
			AkReal32			in_fSpread,					///< Spread ([0,1]).
			AkReal32			in_fFocus,					///< Focus ([0,1]).
			AkChannelConfig		in_inputConfig,				///< Channel configuration of the input.
			AkChannelMask		in_uInputChanSel,			///< Mask of input channels selected for panning (excluded input channels don't contribute to the output).
			AkChannelConfig		in_outputConfig,			///< Desired output configuration.
			AkReal32			in_fCenterPerc,				///< Center percentage. Only applies to mono inputs to outputs that have a center.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes		///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
			) = 0;

		/// Compute standard 3D positioning.
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// \aknote This function is more complete and more efficient than the Compute3DPositioning service that uses spherical coordinates, and should be favored.\endaknote
		/// \aknote ComputePositioning is more general than this one, as it can also compute speaker gains for non-3D spatialization, and should be favored.\endaknote
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT Compute3DPositioning(
			const AkWorldTransform & in_emitter,        ///< Emitter transform.
			const AkWorldTransform & in_listener,       ///< Listener transform.
			AkReal32                 in_fCenterPerc,    ///< Center percentage. Only applies to mono inputs to outputs that have a center.
			AkReal32                 in_fSpread,        ///< Spread ([0,1]).
			AkReal32                 in_fFocus,         ///< Focus ([0,1]).
			AkChannelConfig          in_inputConfig,    ///< Channel configuration of the input.
			AkChannelMask            in_uInputChanSel,  ///< Mask of input channels selected for panning (excluded input channels don't contribute to the output).
			AkChannelConfig          in_outputConfig,   ///< Desired output configuration.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes ///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
			) = 0;

		/// Compute the speaker volume matrix of built-in positioning in Wwise from given positioning data and input and output channel configurations. 
		/// You may use the returned volume matrix with IAkGlobalPluginContext::MixNinNChannels.
		/// Any known (non-anonymous) combination of configurations will work. For example, ambisonics will be decoded or encoded if needed. 
		/// \aknote The function will fail if the input or output configuration is object-based, as the speaker volume matrix would be undefined.\endaknote
		/// All panning or spatialization types are honored.
		/// 3D Spatialization is performed relative to the default listener position (0,0,0) and orientation, where the front vector is (0,0,1) and the top vector is (0,1,0), left handed.
		/// \return AK_Success if succeeded, AK_InvalidParameter if the input or output configuration is object-based, or AK_Fail if the channel configurations are unknown or unhandled.
		/// \sa IAkGlobalPluginContext
		virtual AKRESULT ComputePositioning(
			const AkPositioningData& in_posData,            ///< Positioning data. The field "threeD" is ignored if in_posData.behavioral.spatMode is AK_SpatializationMode_None.
			AkChannelConfig     in_inputConfig,             ///< Channel configuration of the input.
			AkChannelConfig     in_outputConfig,            ///< Channel configuration of the output.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes     ///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
		) = 0;


		//@}

		/// \name Metering.
		//@{

		/// Set flags for controlling computation of metering values on the mix buffer.
		/// Pass AK_NoMetering to disable metering.
		/// \sa
		/// - AK::AkMetering
		virtual void EnableMetering( AkMeteringFlags in_eFlags ) = 0;

		//@}
	};

	/// Parameter node interface, managing access to an enclosed parameter structure.
	/// \aknote The implementer of this interface should also expose a static creation function
	/// that will return a new parameter node instance when required (see \ref se_plugins_overview). \endaknote
	/// \sa
	/// - \ref shared_parameter_interface
	class IAkPluginParam : public IAkRTPCSubscriber
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkPluginParam(){}

	public:
		/// Create a duplicate of the parameter node instance in its current state.
		/// \aknote The allocation of the new parameter node should be done through the AK_PLUGIN_NEW() macro. \endaknote
		/// \return Pointer to a duplicated plug-in parameter node interface
		/// \sa
		/// - \ref iakeffectparam_clone
		virtual IAkPluginParam * Clone(
			IAkPluginMemAlloc * in_pAllocator 	///< Interface to memory allocator to be used
			) = 0;

		/// Initialize the plug-in parameter node interface.
		/// Initializes the internal parameter structure to default values or with the provided parameter
		/// block if it is valid. \endaknote
		/// \aknote If the provided parameter block is valid, use SetParamsBlock() to set all parameters at once. \endaknote
		/// \return Possible return values are: AK_Success, AK_Fail, AK_InvalidParameter
		/// \sa
		/// - \ref iakeffectparam_init
		virtual AKRESULT Init(
			IAkPluginMemAlloc *	in_pAllocator,		///< Interface to the memory allocator to be used
			const void *		in_pParamsBlock,	///< Pointer to a parameter structure block
			AkUInt32        	in_uBlockSize		///< Size of the parameter structure block
			) = 0;

		/// Called by the sound engine when a parameter node is terminated.
		/// \aknote The self-destruction of the parameter node must be done using the AK_PLUGIN_DELETE() macro. \endaknote
		/// \return AK_Success if successful, AK_Fail otherwise
		/// \sa
		/// - \ref iakeffectparam_term
		virtual AKRESULT Term(
			IAkPluginMemAlloc * in_pAllocator		///< Interface to memory allocator to be used
			) = 0;

		/// Set all plug-in parameters at once using a parameter block.
		/// \return AK_Success if successful, AK_InvalidParameter otherwise
		/// \sa
		/// - \ref iakeffectparam_setparamsblock
		virtual AKRESULT SetParamsBlock(
			const void *in_pParamsBlock, 	///< Pointer to a parameter structure block
			AkUInt32	in_uBlockSize		///< Size of the parameter structure block
			) = 0;

		/// Update a single parameter at a time and perform the necessary actions on the parameter changes.
		/// \aknote The parameter ID corresponds to the AudioEnginePropertyID in the plug-in XML description file. \endaknote
		/// \return AK_Success if successful, AK_InvalidParameter otherwise
		/// \sa
		/// - \ref iakeffectparam_setparam
		virtual AKRESULT SetParam(
			AkPluginParamID	in_paramID,		///< ID number of the parameter to set
			const void *	in_pValue, 		///< Pointer to the value of the parameter to set
			AkUInt32    	in_uParamSize	///< Size of the value of the parameter to set
			) = 0;

		/// Use this constant with AK::Wwise::IPluginPropertySet::NotifyInternalDataChanged,
		/// AK::Wwise::IAudioPlugin::GetPluginData and IAkPluginParam::SetParam. This tells
		/// that the whole plugin data needs to be saved/transferred.
		///\sa
		/// - AK::Wwise::IPluginPropertySet::NotifyInternalDataChanged
		/// - AK::Wwise::IAudioPlugin::GetPluginData
		/// - AK::IAkPluginParam::SetParam
		static const AkPluginParamID ALL_PLUGIN_DATA_ID = 0x7FFF;
	};

	/// Wwise sound engine plug-in interface. Shared functionality across different plug-in types.
	/// \aknote The implementer of this interface should also expose a static creation function
	/// that will return a new plug-in instance when required (see \ref soundengine_plugins). \endaknote
	class IAkPlugin
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkPlugin(){}

	public:
		/// Release the resources upon termination of the plug-in.
		/// \return AK_Success if successful, AK_Fail otherwise
		/// \aknote The self-destruction of the plug-in must be done using AK_PLUGIN_DELETE() macro. \endaknote
		/// \sa
		/// - \ref iakeffect_term
		virtual AKRESULT Term(
			IAkPluginMemAlloc * in_pAllocator 	///< Interface to memory allocator to be used by the plug-in
			) = 0;

		/// The reset action should perform any actions required to reinitialize the state of the plug-in
		/// to its original state (e.g. after Init() or on effect bypass).
		/// \return AK_Success if successful, AK_Fail otherwise.
		/// \sa
		/// - \ref iakeffect_reset
		virtual AKRESULT Reset() = 0;

		/// Plug-in information query mechanism used when the sound engine requires information
		/// about the plug-in to determine its behavior.
		/// \warning This function can be called before Init. Implementation of this function should not rely on internal state initialized in Init.
		/// \return AK_Success if successful.
		/// \sa
		/// - \ref iakeffect_geteffectinfo
		virtual AKRESULT GetPluginInfo(
			AkPluginInfo & out_rPluginInfo	///< Reference to the plug-in information structure to be retrieved
			) = 0;

		/// Some plug-ins are accessing Media from the Wwise sound bank system.
		/// If the IAkPlugin object is not using media, this function will not be used and should simply return false.
		/// If the IAkPlugin object is using media, the RelocateMedia feature can be optionally implemented.
		/// To implement correctly the feature, the plugin must be able to "Hot swap" from a memory location to another one in a single blocking call (AK::IAkPlugin::RelocateMedia)
		///
		/// \sa
		/// - AK::IAkPlugin::RelocateMedia
		virtual bool SupportMediaRelocation() const
		{
			return false;
		}

		/// Some plug-ins are accessing Media from the Wwise sound bank system.
		/// If the IAkPlugin object is not using media, this function will not be used.
		/// If the IAkPlugin object is using media, the RelocateMedia feature can be optionally implemented.
		/// When this function is being called, the IAkPlugin object must make the required changes to remove all
		/// referenced from the old memory pointer (previously obtained by GetPluginMedia() (and offsets to) to not access anymore the content of the old memory data and start using the newly provided pointer instead.
		/// The change must be done within the function RelocateMedia().
		/// After this call, the memory space in in_pOldInMemoryData will be invalidated and cannot be used safely anymore.
		///
		/// This function will not be called if SupportMediaRelocation returned false.
		///
		/// \sa
		/// - AK::IAkPlugin::SupportMediaRelocation
		virtual AKRESULT RelocateMedia(
			AkUInt8* /*in_pNewMedia*/,
			AkUInt8* /*in_pOldMedia*/
			)
		{
			return AK_NotImplemented;
		}

	};

	/// Software effect plug-in interface (see \ref soundengine_plugins_effects).
	class IAkEffectPlugin : public IAkPlugin
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkEffectPlugin(){}

	public:
		/// Software effect plug-in initialization. Prepares the effect for data processing, allocates memory and sets up the initial conditions.
		/// \aknote Memory allocation should be done through appropriate macros (see \ref fx_memory_alloc). \endaknote
		/// \sa
		/// - \ref iakmonadiceffect_init
		virtual AKRESULT Init(
			IAkPluginMemAlloc *			in_pAllocator,				///< Interface to memory allocator to be used by the effect
			IAkEffectPluginContext *	in_pEffectPluginContext,	///< Interface to effect plug-in's context
			IAkPluginParam *			in_pParams,					///< Interface to plug-in parameters
			AkAudioFormat &				io_rFormat					///< Audio data format of the input/output signal. Only an out-of-place plugin is allowed to change the channel configuration. Object processors always receive a channel configuration with type "object". They may however change it to any other kind, in which case the host bus will automatically create an output object with the desired channel configuration.
			) = 0;
	};

	/// Software effect plug-in interface for in-place processing (see \ref soundengine_plugins_effects).
	class IAkInPlaceEffectPlugin : public IAkEffectPlugin
	{
	public:
		/// Software effect plug-in DSP execution for in-place processing.
		/// \aknote The effect should process all the input data (uValidFrames) as long as AK_DataReady is passed in the eState field.
		/// When the input is finished (AK_NoMoreData), the effect can output more sample than uValidFrames up to MaxFrames() if desired.
		/// All sample frames beyond uValidFrames are not initialized and it is the responsibility of the effect to do so when outputting an effect tail.
		/// The effect must notify the pipeline by updating uValidFrames if more frames are produced during the effect tail.
		/// \aknote The effect will stop being called by the pipeline when AK_NoMoreData is returned in the the eState field of the AkAudioBuffer structure.
		/// See \ref iakmonadiceffect_execute_general.
		virtual void Execute(
				AkAudioBuffer *							io_pBuffer		///< In/Out audio buffer data structure (in-place processing)
				) = 0;

		/// Skips execution of some frames, when the voice is virtual playing from elapsed time.
		/// This can be used to simulate processing that would have taken place (e.g. update internal state).
		/// Return AK_DataReady or AK_NoMoreData, depending if there would be audio output or not at that point.
		virtual AKRESULT TimeSkip(
			AkUInt32 in_uFrames	///< Number of frames the audio processing should advance.
			) = 0;
	};


	/// Software effect plug-in interface for out-of-place processing (see \ref soundengine_plugins_effects).
	class IAkOutOfPlaceEffectPlugin : public IAkEffectPlugin
	{
	public:
		/// Software effect plug-in for out-of-place processing.
		/// \aknote An input buffer is provided and will be passed back to Execute() (with an advancing offset based on uValidFrames consumption by the plug-in).
		/// The output buffer should be filled entirely by the effect (at which point it can report AK_DataReady) except on last execution where AK_NoMoreData should be used.
		/// AK_DataNeeded should be used when more input data is necessary to continue processing.
		/// \aknote Only the output buffer eState field is looked at by the pipeline to determine the effect state.
		/// See \ref iakmonadiceffect_execute_outofplace.
		virtual void Execute(
				AkAudioBuffer *							in_pBuffer,		///< Input audio buffer data structure
				AkUInt32								in_uInOffset,	///< Offset position into input buffer data
				AkAudioBuffer *							out_pBuffer		///< Output audio buffer data structure
				) = 0;

		/// Skips execution of some frames, when the voice is virtual playing from elapsed time.
		/// This can be used to simulate processing that would have taken place (e.g. update internal state).
		/// Return AK_DataReady or AK_NoMoreData, depending if there would be audio output or not at that point.
		virtual AKRESULT TimeSkip(
			AkUInt32 &io_uFrames	///< Number of frames the audio processing should advance.  The output value should be the number of frames that would be consumed to output the number of frames this parameter has at the input of the function.
			) = 0;
	};

	/// In-place Object Processor plug-in interface. Implement this interface when your plugin returns both AkPluginInfo::bCanProcessObjects 
	/// and AkPluginInfo::bIsInPlace set to true. 
	/// In-place object processors just modify objects' audio or metadata, but do not destroy objects create additional output objects.
	/// An object processor may be initialized with an Object configuration, or any channel configuration, depending on the configuration of its input.
	/// It is not allowed to change the channel configuration in Init.
	class IAkInPlaceObjectPlugin : public IAkEffectPlugin
	{
	public:
		
		/// In-place object processor plug-in DSP execution.
		/// \aknote The effect should process all the input data (uValidFrames) of each input object in in_pObjectsIn as long as AK_DataReady is passed in their corresponding eState field. 
		/// When an input object is finished (eState is AK_NoMoreData), the effect can output more samples than uValidFrames, up to MaxFrames() if desired.
		/// The effect must notify the pipeline by updating uValidFrames of a given object if more frames are produced, and by setting its eState to AK_DataReady as long as more samples will be produced.\endaknote.
		/// \sa AK::IAkEffectPlugin::Init.
		virtual void Execute(
			const AkAudioObjects& io_objects		///< Input/Output objects and object buffers.
		) = 0;
	};

	/// Out-of-place Object Processor plug-in interface. Implement this interface when your plugin returns AkPluginInfo::bCanProcessObjects set to true
	/// and AkPluginInfo::bIsInPlace set to false. 
	/// With out-of-place object processors, the set of output objects is different than that of the input objects. Out-of-place object processors typically create
	/// their own output objects using IAkEffectPluginContext::CreateObject. Alternatively, an output object is created by the host bus if the channel configuration 
	/// returned from Init is not of type AK_ChannelConfigType_Objects.
	/// Only out-of-place object processors may create output objects or change the output channel configuration. 
	class IAkOutOfPlaceObjectPlugin : public IAkEffectPlugin
	{
	public:

		/// Out-of-place object processor plug-in DSP execution.
		/// \aknote When running out-of-place, the effect must only update uValidFrames and eState fields of output objects.
		/// When the object processor sets an output object's eState field to AK_NoMoreData, the host will garbage collect them afterwards. \endaknote
		/// \akwarning If an out-of-place object processor calls AK::IAkEffectPluginContext::CreateOutputObjects from within Execute, it must not access the output objects passed in out_objects, as the pointed objects may have moved elsewhere in memory.
		/// In that case it must use AK::IAkEffectPluginContext::GetOutputObjects. Arguments in_pObjectBuffersOut and in_pObjectsOut can only be safely used if the plugin creates objects during Init, either via 
		/// AK::IAkEffectPluginContext::CreateOutputObjects, or by setting the channelConfig field of io_rFormat to a normal channel configuration (i.e. whose eConfigType is not AK_ChannelConfigType_Objects). \endakwarning
		/// \sa AK::IAkEffectPlugin::Init.
		virtual void Execute(
			const AkAudioObjects& in_objects,	///< Input objects and object audio buffers.
			const AkAudioObjects& out_objects	///< Output objects and object audio buffers.
		) = 0;
	};

	class IAkAudioDeviceEffectPluginContext : public IAkPluginContextBase
	{
	public:
		/// Compute the speaker volume matrix of built-in positioning in Wwise from given positioning data and input and output channel configurations. 
		/// Any known (non-anonymous) combination of configurations will work. For example, ambisonics will be decoded or encoded if needed. 
		/// \aknote The function will fail if the input or output configuration is object-based, as the speaker volume matrix would be undefined.\endaknote
		/// All panning or spatialization types are honored.
		/// 3D Spatialization is performed relative to the default listener position (0,0,0) and orientation, where the front vector is (0,0,1) and the top vector is (0,1,0), left handed.
		/// \return AK_Success if succeeded, AK_InvalidParameter if the input or output configuration is object-based, or AK_Fail if the channel configurations are unknown or unhandled.
		virtual AKRESULT ComputePositioning(
			const AkPositioningData& in_posData,            ///< Positioning data. The field "threeD" is ignored if in_posData.behavioral.spatMode is AK_SpatializationMode_None.
			AkChannelConfig     in_inputConfig,             ///< Channel configuration of the input.
			AkChannelConfig	    in_outputConfig,            ///< Channel configuration of the output.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes     ///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
		) = 0;
	};

	/// Audio device effect plug-in interface. Implement this interface for in-place effects that must be applied at the very end of the pipeline.
	/// Audio device effects are applied right before sending audio buffers (main mix, passthrough and objects) to the audio device output through IAkSinkPlugin/IAk3DAudioSinkPlugin.
	/// The format of the audio buffers passed to the effect matches the format requested by the sink plug-in. This means that audio device effects must be in-place; they cannot change io_rFormat in Init().
	class IAkAudioDeviceEffectPlugin : public IAkPlugin
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkAudioDeviceEffectPlugin() {}

	public:
		/// Audio device effect plug-in initialization. Prepares the effect for data processing, allocates memory and sets up the initial conditions.
		/// \aknote Memory allocation should be done through appropriate macros (see \ref fx_memory_alloc). \endaknote
		virtual AKRESULT Init(
			IAkPluginMemAlloc* in_pAllocator,							///< Interface to memory allocator to be used by the effect
			IAkAudioDeviceEffectPluginContext* in_pEffectPluginContext,	///< Interface to audio effect's plug-in context
			IAkPluginParam* in_pParams,									///< Interface to plug-in parameters
			const AkAudioFormat& in_rFormat,							///< Audio data format of the input/output signal. Matches the channel configuration of the audio device sink plug-in. If format is object-based (AkChannelConfig::eConfigType is Ak_ChannelConfigType_Objects), the plug-in should verify Ak3DAudioSinkCapabilities to determine which inputs it can expect in Execute (main mix, passthrough, objects).
			const Ak3DAudioSinkCapabilities& in_3dCapabilities			///< 3D capabilities of the output device sink plug-in. If io_rFormat is not object-based, this can be ignored and only the main mix will be submitted to Execute().
		) = 0;

		virtual void Execute(
			AkAudioBuffer* io_pMainMix,				///< Audio buffer data structure for the main mix (binauralized or not, depending on if binauralization is supported and enabled).
			AkAudioBuffer* io_pPassthroughMix,		///< The stereo mix to send out to the system in passthrough fashion (no binauralization). NULL if the channel configuration of the device is not object-based or does not have a passthrough.
			const AkAudioObjects& io_objects,		///< 3D Audio objects and object audio buffers to be consumed. The audio buffers are in the native format of the sound engine (typically float, deinterleaved), as specified by io_rFormat passed to Init(). It is up to the plugin to transform it into a format that is compatible with its output.
			AkRamp& io_gain							///< Volume gain to apply to all inputs. If the effect applies the gain, it must reset the gain to 1.0f so that it's not applied a second time in the sink plug-in.
		) = 0;
	};

	/// Interface to retrieve information about an input of a mixer.
	/// DEPRECATED. 
	class IAkMixerInputContext
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkMixerInputContext(){}

	public:

		/// Obtain the parameter blob for the mixer plugin that were attached to this input.
		/// \return The parameter blob, which can be safely cast into the plugin's implementation.
		/// If all parameters are default value, NULL is returned. It is up to the plugin's implementation to know
		/// what the default values are.
		virtual IAkPluginParam * GetInputParam(
			AkPluginID in_attachmentPluginID ///< Full plugin ID of the attachment plug-in, including company ID and plug-in type. See AKMAKECLASSID macro. Attachment plug-ins' type is always AkPluginTypeEffect.
		) = 0;

		/// Obtain the interface to access the voice info of this input.
		/// \return The interface to voice info. NULL when the input is not a voice but the output of another bus instead.
		virtual IAkVoicePluginInfo * GetVoiceInfo() = 0;

		/// Obtain the interface to access the game object on which the plugin is instantiated.
		/// \return The interface to GameObject info.
		virtual IAkGameObjectPluginInfo* GetGameObjectInfo() = 0;

		/// Query the nature of the connection between this input and the mixer.
		/// \return The connection type (direct/dry, user-defined auxiliary send, game-defined auxiliary send). Bus inputs are always "direct".
		virtual AkConnectionType GetConnectionType() = 0;

		/// Use this method to retrieve user data to this context. It is always initialized to NULL until you decide to set it otherwise.
		/// \return Attached user data.
		/// \sa SetUserData()
		virtual void* GetUserData() = 0;

		/// Use this method to attach user data to this context. It is always initialized to NULL until you decide to set it otherwise.
		/// \sa GetUserData()
		virtual void SetUserData(void* in_pUserData) = 0;

		/// \name Default positioning information.
		/// \akwarning
		/// The methods of this group are deprecated.
		/// \endakwarning
		//@{

		/// Retrieve center percentage of this input.
		/// \return Center percentage, between 0 and 1.
		virtual AkReal32 GetCenterPerc() = 0;

		/// Retrieve the speaker panning type: type of panning logic when object is not 3D spatialized.
		/// Note that the returned value is only relevant when the object is not 3D spatialized,
		/// that is Get3DSpatializationMode returns AK_SpatializationMode_None.
		/// \sa
		/// - Get3DSpatializationMode()
		virtual AkSpeakerPanningType GetSpeakerPanningType() = 0;

		/// Speaker panning:
		/// Retrieve the panner position (each vector component is between -1 and 1) of this input.
		/// Note that the returned value is only relevant when the object is not 3D spatialized,
		/// (Get3DSpatializationMode returns AK_SpatializationMode_None), and if speaker panning is not direct assignment
		/// (GetSpeakerPanningType does not return AK_DirectSpeakerAssignment).
		/// \sa
		/// - GetSpeakerPanningType()
		/// - Get3DSpatializationMode()
		virtual void GetPannerPosition(
			AkVector & out_position			///< Returned sound position.
			) = 0;

		/// Get the value of this input's Listener Relative Routing option, that is, if the emitter-listener relative 
		/// association is calculated at this node. Listener Relative Routing needs to be calculated in order for a node
		/// to be spatialized or attenuated with respect to in-game emitter and listener positions. Otherwise it can only
		/// be panned.
		/// \sa
		/// - Get3DSpatializationMode()
		/// - Get3DPositionType()
		/// - GetNum3DPositions()
		virtual bool HasListenerRelativeRouting() = 0;

		/// Get whether the emitter position is defined by the game alone (AK_3DPositionType_Emitter), or if it is further automated 
		/// (AK_3DPositionType_EmitterWithAutomation, AK_3DPositionType_ListenerWithAutomation).
		/// The resulting 3D position(s) may be obtained by Get3DPosition(), and used for 3D spatialization or attenuation.
		/// \sa
		/// - Get3DPosition()
		/// - GetNum3DPositions()
		/// - HasListenerRelativeRouting()
		virtual Ak3DPositionType Get3DPositionType() = 0;

		/// 3D spatialization:
		/// Retrieve the number of emitter-listener pairs (rays) of this input.
		/// Note that the returned value is always 0 unless the input has listener relative routing (see HasListenerRelativeRouting()).
		/// Use this function with Get3DPosition().
		/// \sa
		/// - Get3DPosition()
		/// - HasListenerRelativeRouting()
		virtual AkUInt32 GetNum3DPositions() = 0;

		/// 3D spatialization:
		/// Retrieve the spherical coordinates of the desired emitter-listener pair (ray) corresponding to this
		/// input, as automated by the engine. Applicable only when the input has listener relative routing (see HasListenerRelativeRouting()).
		/// Returned rays are those that result from engine automation, if applicable.
		/// \return AK_Success if the pair index is valid, AK_Fail otherwise.
		/// \sa
		/// - HasListenerRelativeRouting()
		/// - GetNum3DPositions()
		virtual AKRESULT Get3DPosition(
			AkUInt32 in_uIndex,							///< Index of the pair, [0, GetNum3DPositions()[
			AkEmitterListenerPair & out_soundPosition	///< Returned sound position, in spherical coordinates.
			) = 0;

		/// 3D spatialization:
		/// Evaluate spread value at the distance of the desired emitter-listener pair for this input.
		/// Applicable only when the input has listener relative routing (see HasListenerRelativeRouting()).
		/// \return The spread value, between 0 and 1. 0 if the pair index is invalid.
		/// \sa
		/// - HasListenerRelativeRouting()
		/// - GetNum3DPositions()
		/// - Get3DPosition()
		virtual AkReal32 GetSpread(
			AkUInt32 in_uIndex								///< Index of the pair, [0, GetNum3DPositions()[
			) = 0;

		/// 3D spatialization:
		/// Evaluate focus value at the distance of the desired emitter-listener pair for this input.
		/// Applicable only when the input has listener relative routing (see HasListenerRelativeRouting()).
		/// \return The focus value, between 0 and 1. 0 if the pair index is invalid.
		/// \sa
		/// - HasListenerRelativeRouting()
		/// - GetNum3DPositions()
		/// - Get3DPosition()
		virtual AkReal32 GetFocus(
			AkUInt32 in_uIndex								///< Index of the pair, [0, GetNum3DPositions()[
			) = 0;

		/// Get the max distance as defined in the attenuation editor.
		/// Applicable only when the input has listener relative routing (see HasListenerRelativeRouting()).
		/// \return True if this input has attenuation, false otherwise.
		virtual bool GetMaxAttenuationDistance(
			AkReal32 & out_fMaxAttenuationDistance	///< Returned max distance.
			) = 0;

		/// Get next volumes as computed by the sound engine for this input.
		/// You may use the returned volume matrices with IAkGlobalPluginContext::MixNinNChannels.
		/// \sa IAkGlobalPluginContext
		virtual void GetSpatializedVolumes(
			AK::SpeakerVolumes::MatrixPtr out_mxPrevVolumes,	///< Returned in/out channel volume distribution corresponding to the beginning of the buffer. Must be preallocated (see AK::SpeakerVolumes::Matrix services).
			AK::SpeakerVolumes::MatrixPtr out_mxNextVolumes		///< Returned in/out channel volume distribution corresponding to the end of the buffer. Must be preallocated (see AK::SpeakerVolumes::Matrix services).
			) = 0;

		/// Query the 3D spatialization mode used by this input.
		/// Applicable only when the input has listener relative routing (see HasListenerRelativeRouting()).
		/// \return The 3D spatialization mode (see Ak3DSpatializationMode). AK_SpatializationMode_None if not set, or if the input is not a node where the game object is evaluated against its listener.
		/// \sa
		/// - HasListenerRelativeRouting()
		virtual Ak3DSpatializationMode Get3DSpatializationMode() = 0;

		//@}
	};

	/// Interface to retrieve contextual information for a sink plugin.
	/// \sa
	/// - AK::IAkSinkPlugin
	class IAkSinkPluginContext : public IAkPluginContextBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkSinkPluginContext(){}

	public:

		/// Query if the sink plugin is instantiated on the main output device (primary tree).
		/// \return True if the sink plugin is instantiated on the main output device (primary tree), false otherwise.
		/// \sa
		/// - AK::IAkSinkPlugin::IsDataNeeded()
		/// - AK::IAkSinkPlugin::Consume()
		virtual bool IsPrimary() = 0;

		/// Sink plugins may need to call this function to notify the audio thread that it should wake up
		/// in order to potentially process an audio frame. Note that the audio thread may wake up for other
		/// reasons, for example following calls to AK::SoundEngine::RenderAudio().
		/// Once the audio thread is awaken, it will ask the sink plugin how many audio frames need to be
		/// processed and presented to the plugin. This is done through AK::IAkSinkPlugin::IsDataNeeded()
		/// and AK::IAkSinkPlugin::Consume() respectively.
		/// Note that only the sink plugin that is instantiated on the main output device (primary tree) may control
		/// the audio thread synchronization.
		/// \return AK_Success if the calling plugin is instantiated on the main output device (primary tree),
		/// AK_Fail otherwise.
		/// \sa
		/// - AK::IAkSinkPluginContext::IsPrimary()
		/// - AK::IAkSinkPlugin::IsDataNeeded()
		/// - AK::IAkSinkPlugin::Consume()
		virtual AKRESULT SignalAudioThread() = 0;

		/// Query engine's user-defined sink queue depth (AkPlatformInitSettings::uNumRefillsInVoice).
		/// \return The engine's AkPlatformInitSettings::uNumRefillsInVoice value on platforms for which it exists, 0 otherwise.
		virtual AkUInt16 GetNumRefillsInVoice() = 0;

		/// Compute the speaker volume matrix of built-in positioning in Wwise from given positioning data and input and output channel configurations. 
		/// Any known (non-anonymous) combination of configurations will work. For example, ambisonics will be decoded or encoded if needed. 
		/// \aknote The function will fail if the input or output configuration is object-based, as the speaker volume matrix would be undefined.\endaknote
		/// All panning or spatialization types are honored.
		/// 3D Spatialization is performed relative to the default listener position (0,0,0) and orientation, where the front vector is (0,0,1) and the top vector is (0,1,0), left handed.
		/// \return AK_Success if succeeded, AK_InvalidParameter if the input or output configuration is object-based, or AK_Fail if the channel configurations are unknown or unhandled.
		virtual AKRESULT ComputePositioning(
			const AkPositioningData& in_posData,            ///< Positioning data. The field "threeD" is ignored if in_posData.behavioral.spatMode is AK_SpatializationMode_None.
			AkChannelConfig     in_inputConfig,             ///< Channel configuration of the input.
			AkChannelConfig	    in_outputConfig,            ///< Channel configuration of the output.
			AK::SpeakerVolumes::MatrixPtr out_mxVolumes     ///< Returned volumes matrix. Must be preallocated using AK::SpeakerVolumes::Matrix::GetRequiredSize() (see AK::SpeakerVolumes::Matrix services).
		) = 0;
	};

	enum AkSinkPluginType
	{
		AkSinkPluginType_Sink,
		AkSinkPluginType_3DAudioSink
	};

	/// Software interface for sink (audio endpoint) plugins.
	/// This interface should not be implemented directly,
	/// Plug-ins should either implement:
	///   - IAkSinkPlugin: for audio endpoint that do not support 3D audio, or
	///   - IAk3DAudioSinkPlugin: for audio endpoints that support 3D audio features.
	class IAkSinkPluginBase : public IAkPlugin
	{
	public:
		/// Initialization of the sink plugin.
		///
		/// This method prepares the audio device plug-in for data processing, allocates memory, and sets up initial conditions.
		/// The plug-in is passed in a pointer to a memory allocator interface (AK::IAkPluginMemAlloc).You should perform all dynamic memory allocation through this interface using the provided memory allocation macros(refer to \ref fx_memory_alloc).For the most common memory allocation needs, namely allocation at initialization and release at termination, the plug-in does not need to retain a pointer to the allocator.It will also be provided to the plug-in on termination.
		///	The AK::IAkSinkPluginContext interface allows to retrieve information related to the context in which the audio device plug-in is operated.
		///	The plug-in also receives a pointer to its associated parameter node interface (AK::IAkPluginParam).Most plug-ins will want to keep a reference to the associated parameter node to be able to retrieve parameters at runtime. Refer to \ref iakeffectparam_communication for more details.
		///	All of these interfaces will remain valid throughout the plug-in's lifespan so it is safe to keep an internal reference to them when necessary.
		///	Plug-ins also receive the output audio format(which stays the same during the lifespan of the plug-in) to be able to allocate memory and setup processing for a given channel configuration.
		///	Note that the channel configuration is suggestive and may even be specified as not AkChannelConfig::IsValid().The plugin is free to determine the true channel configuration(this is an io parameter).
		///
		/// \return AK_Success if successful.
		/// \return AK_NotCompatible if the system doesn't support this sink type.  Return this if you want to fall back to the default sinks.  This sink will never be requested again.  Do not return this code if the device is simply unplugged.
		/// \return AK_DeviceNotCompatible if the requested output device doesn't support this sink type. Return this if you want to fall back to the dummy audio sink, which will result in no audio for the associated bus hierarchy. This sink will never be requested again.
		/// All other return codes will be treated as temporary failures conditions and the sink will be requested again later.

		virtual AKRESULT Init(
			IAkPluginMemAlloc *		in_pAllocator,			///< Interface to memory allocator to be used by the effect.
			IAkSinkPluginContext *	in_pSinkPluginContext,	///< Interface to sink plug-in's context.
			IAkPluginParam *		in_pParams,				///< Interface to plug-in parameters.
			AkAudioFormat &			io_rFormat				///< Audio data format of the input signal. Note that the channel configuration is suggestive and may even be specified as not AkChannelConfig::IsValid(). The plugin is free to determine the true channel configuration.
		) = 0;

		/// Obtain the number of audio frames that should be processed by the sound engine and presented
		/// to this plugin via AK::IAkSinkPlugin::Consume(). The size of a frame is determined by the sound engine and
		/// obtainable via AK::IAkPluginContextBase::GetMaxBufferLength().
		/// \return AK_Success if successful, AK_Fail if there was a critical error.
		/// \sa
		/// - AK::IAkSinkPlugin::Consume()
		/// - AK::IAkSinkPluginContext::SignalAudioThread()
		virtual AKRESULT IsDataNeeded(
			AkUInt32& out_uNumFramesNeeded	///< Returned number of audio frames needed.
		) = 0;

		/// Called at the end of the audio frame. If no Consume calls were made prior to OnFrameEnd, this means no audio was sent to the device.  Assume silence.  
		/// \sa
		/// - AK::IAkSinkPlugin::Consume()
		virtual void OnFrameEnd() = 0;

		/// Ask the plug-in whether starvation occurred.
		/// \return True if starvation occurred, false otherwise.
		virtual bool IsStarved() = 0;

		/// Reset the "starvation" flag after IsStarved() returned true.
		virtual void ResetStarved() = 0;

		virtual AkSinkPluginType GetSinkPluginType() const = 0;
	};

	/// Software interface for sink (audio endpoint) plugins.
	class IAkSinkPlugin : public IAkSinkPluginBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkSinkPlugin() {}

	public:
		/// Present an audio buffer to the sink. The audio buffer is in the native format of the sound engine
		/// (typically float, deinterleaved), as specified by io_rFormat passed to Init(). It is up to the
		/// plugin to transform it into a format that is compatible with its output.
		/// Note that Consume() is not called if the output for this frame consists of silence. Plugins should
		/// detect this in OnFrameEnd().
		/// \sa
		/// - AK::IAkSinkPlugin::IsDataNeeded()
		/// - AK::IAkSinkPlugin::OnFrameEnd()
		virtual void Consume(
			AkAudioBuffer *	in_pInputBuffer, ///< Input audio buffer data structure. Plugins should avoid processing data in-place.
			AkRamp			in_gain          ///< Volume gain to apply to this input (prev corresponds to the beginning, next corresponds to the end of the buffer).
		) = 0;

		virtual AkSinkPluginType GetSinkPluginType() const override final { return AkSinkPluginType_Sink; }
	};

	/// Software plug-in interface for sink (audio end point) which supports 3D audio features.
	class IAk3DAudioSinkPlugin : public IAkSinkPluginBase
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAk3DAudioSinkPlugin() {}

	public:
		/// Returns the capabilities of the sink's 3D audio system
		virtual void Get3DAudioCapabilities(
			Ak3DAudioSinkCapabilities& out_rCapabilities     ///< Capabilities of the 3D Audio system
		) = 0;

		/// Same as AK::IAkSinkPlugin::Consume(), but receives 3 inputs: the main mix,the stereo passthrough and 3d audio objects.
		/// \sa
		/// - AK::IAkSinkPlugin::Consume()
		/// - AK::IAkSinkPlugin::IsDataNeeded()
		/// - AK::IAkSinkPlugin::OnFrameEnd()
		virtual void Consume(
			AkAudioBuffer* in_pMainMix,				///< Audio buffer data structure for the main mix (binauralized or not, depending on if binauralization is supported and enabled).
			AkAudioBuffer* in_pPassthroughMix,		///< The stereo mix to send out to the system in passthrough fashion (no binauralization). NULL if the channel configuration of the device is not object-based or does not have a passthrough.
			const AkAudioObjects& in_objects,		///< 3D Audio objects and object audio buffers to be consumed. The audio buffers are in the native format of the sound engine (typically float, deinterleaved), as specified by io_rFormat passed to Init(). It is up to the plugin to transform it into a format that is compatible with its output.
			AkRamp in_gain							///< Volume gain to apply to all inputs.
		) = 0;

		virtual AkSinkPluginType GetSinkPluginType() const override final { return AkSinkPluginType_3DAudioSink; }
	};

	/// Wwise sound engine source plug-in interface (see \ref soundengine_plugins_source).
	class IAkSourcePlugin : public IAkPlugin
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkSourcePlugin(){}

	public:
		/// Source plug-in initialization. Gets the plug-in ready for data processing, allocates memory and sets up the initial conditions.
		/// \aknote Memory allocation should be done through the appropriate macros (see \ref fx_memory_alloc). \endaknote
		/// \sa
		/// - \ref iaksourceeffect_init
		virtual AKRESULT Init(
			IAkPluginMemAlloc *			in_pAllocator,					///< Interface to the memory allocator to be used by the plug-in
			IAkSourcePluginContext *	in_pSourcePluginContext,		///< Interface to the source plug-in's context
			IAkPluginParam *			in_pParams,						///< Interface to the plug-in parameters
			AkAudioFormat &				io_rFormat						///< Audio format of the output data to be produced by the plug-in (mono native by default)
			) = 0;

		/// This method is called to determine the approximate duration of the source.
		/// \return The duration of the source, in milliseconds.
		/// \sa
		/// - \ref iaksourceeffect_getduration
		virtual AkReal32 GetDuration() const = 0;

		/// This method is called to determine the estimated envelope of the source.
		/// \return The estimated envelope of the data that will be generated in the next call to
		/// Execute(). The envelope value should be normalized to the highest peak of the entire
		/// duration of the source. Expected range is [0,1]. If envelope and peak value cannot be
		/// predicted, the source should return 1 (no envelope).
		/// \sa
		/// - \ref iaksourceeffect_getenvelope
		virtual AkReal32 GetEnvelope() const
		{
			return 1.f;
		}

		/// This method is called to tell the source to stop looping.
		/// This will typically be called when an action of type "break" will be triggered on the playing source.
		/// Break (or StopLooping) means: terminate gracefully... if possible. In most situations it finishes the current loop and plays the sound release if there is one.
		///
		/// \return
		/// - \c AK_Success if the source ignores the break command and plays normally till the end or if the source support to stop looping and terminates gracefully.
		/// - \c AK_Fail if the source cannot simply stop looping, in this situation, the break command will end up stopping this source.
		/// \sa
		/// - \ref iaksourceeffect_stoplooping
		virtual AKRESULT StopLooping(){ return AK_Success; }

		/// This method is called to tell the source to seek to an arbitrary sample.
		/// This will typically be called when the game calls AK::SoundEngine::SeekOnEvent() where the event plays
		/// a sound that wraps this source plug-in.
		/// If the plug-in does not handle seeks, it should return AK_Success. If it returns AK_Fail, it will
		/// be terminated by the sound engine.
		///
		/// \return
		/// - \c AK_Success if the source handles or ignores seek command.
		/// - \c AK_Fail if the source considers that seeking requests should provoke termination, for example, if
		///		the desired position is greater than the prescribed source duration.
		/// \sa
		/// - AK::SoundEngine::SeekOnEvent()
		virtual AKRESULT Seek(
			AkUInt32 /* in_uPosition */	///< Position to seek to, in samples, at the rate specified in AkAudioFormat (see AK::IAkSourcePlugin::Init()).
			) { return AK_Success; }

		/// Skips execution when the voice is virtual playing from elapsed time to simulate processing that would have taken place (e.g. update internal state) while
		/// avoiding most of the CPU hit of plug-in execution.
		/// Given the number of frames requested adjust the number of frames that would have been produced by a call to Execute() in the io_uFrames parameter and return and
		/// return AK_DataReady or AK_NoMoreData, depending if there would be audio output or not at that point.
		/// Returning AK_NotImplemented will trigger a normal execution of the voice (as if it was not virtual) thus not enabling the CPU savings of a proper from elapsed time behavior.
		/// Note that returning AK_NotImplemeted for a source plug-ins that support asynchronous processing will produce a 'resume' virtual voice behavior instead.
		virtual AKRESULT TimeSkip(
			AkUInt32 & /*io_uFrames	*/ ///< (Input) Number of frames that the audio buffer processing can advance (equivalent to MaxFrames()). The output value should be the number of frames that would be produced this execution.
			) { return AK_NotImplemented; }

		/// Software effect plug-in DSP execution.
		/// \aknote The effect can output as much as wanted up to MaxFrames(). All sample frames passed uValidFrames at input time are
		/// not initialized and it is the responsibility of the effect to do so. When modifying the number of valid frames within execution
		/// (e.g. to flush delay lines) the effect should notify the pipeline by updating uValidFrames accordingly.
		/// \aknote The effect will stop being called by the pipeline when AK_NoMoreData is returned in the the eState field of the AkAudioBuffer structure.
		virtual void Execute(
				AkAudioBuffer *							io_pBuffer		///< In/Out audio buffer data structure (in-place processing)
				) = 0;
	};


	/// This function can be useful to convert from normalized floating point audio samples to HW-pipeline format samples.
	#define AK_FLOAT_TO_SAMPLETYPE( __in__ ) (__in__)
	/// This function can be useful to convert from normalized floating point audio samples to HW-pipeline format samples when the input is not not to exceed (-1,1) range.
	#define AK_FLOAT_TO_SAMPLETYPE_NOCLIP( __in__ ) (__in__)
	/// This function can be useful to convert from HW-pipeline format samples to normalized floating point audio samples.
	#define AK_SAMPLETYPE_TO_FLOAT( __in__ ) (__in__)

	#define AK_DBTOLIN( __db__ ) (powf(10.f,(__db__) * 0.05f))
}

/// Registered plugin creation function prototype.
AK_CALLBACK( AK::IAkPlugin*, AkCreatePluginCallback )( AK::IAkPluginMemAlloc * in_pAllocator );
/// Registered plugin parameter node creation function prototype.
AK_CALLBACK( AK::IAkPluginParam*, AkCreateParamCallback )( AK::IAkPluginMemAlloc * in_pAllocator );
/// Registered plugin device enumeration function prototype, used for providing lists of devices by plug-ins.
AK_CALLBACK( AKRESULT, AkGetDeviceListCallback)(
	AkUInt32& io_maxNumDevices,					///< In: The length of the out_deviceDescriptions array, or zero is out_deviceDescriptions is null. Out: If out_deviceDescriptions is not-null, this should be set to the number of entries in out_deviceDescriptions that was populated (and should be less-than-or-equal to the initial value). If out_deviceDescriptions is null, this should be set to the maximum number of devices that may be returned by this callback.
	AkDeviceDescription* out_deviceDescriptions	///< The output array of device descriptions. If this is not-null, there will be a number of entries equal to the input value of io_maxNumDevices.
	);

struct AkPlatformInitSettings;
struct AkInitSettings;

namespace AK
{
	enum AkPluginServiceType
	{
		PluginServiceType_Mixer = 0,
		PluginServiceType_RNG = 1,
		PluginServiceType_AudioObjectAttenuation = 2,
		PluginServiceType_AudioObjectPriority = 3,
		PluginServiceType_MAX,
	};

	/// Common interface for plug-in services accessed through the global plug-in context
	class IAkPluginService
	{
	protected:
		virtual ~IAkPluginService() {}
	};
	
	/// Global plug-in context used for plug-in registration/initialization. 
	/// Games query this interface from the sound engine, via AK::SoundEngine::GetGlobalPluginContext. Plug-ins query it via IAkPluginContextBase::GlobalContext.
	class IAkGlobalPluginContext
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkGlobalPluginContext(){}

	public:

		/// Retrieve the streaming manager access interface.
		virtual IAkStreamMgr * GetStreamMgr() const = 0;

		/// Retrieve the maximum number of frames that Execute() will be called with for this effect.
		/// Can be used by the effect to make memory allocation at initialization based on this worst case scenario.
		/// \return Maximum number of frames.
		virtual AkUInt16 GetMaxBufferLength() const = 0;

		/// Query whether sound engine is in real-time or offline (faster than real-time) mode.
		/// \return true when sound engine is in offline mode, false otherwise.
		virtual bool IsRenderingOffline() const = 0;

		/// Retrieve the core sample rate of the engine. This sample rate applies to all effects except source plugins, which declare their own sample rate.
		/// \return Core sample rate.
		virtual AkUInt32 GetSampleRate() const = 0;

		/// Post a monitoring message or error string. This will be displayed in the Wwise capture
		/// log.
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is
		///			called in the optimized/release configuration and return AK_NotCompatible.
		virtual AKRESULT PostMonitorMessage(
			const char* in_pszError,				///< Message or error string to be displayed
			AK::Monitor::ErrorLevel in_eErrorLevel	///< Specifies whether it should be displayed as a message or an error
			) = 0;

		/// Register a plug-in with the sound engine and set the callback functions to create the
		/// plug-in and its parameter node.
		/// \sa
		/// - \ref register_effects
		/// - \ref plugin_xml
		/// \return AK_Success if successful, AK_InvalidParameter if invalid parameters were provided or Ak_Fail otherwise. Possible reasons for an AK_Fail result are:
		/// - Insufficient memory to register the plug-in
		/// - Plug-in ID already registered
		/// \remarks
		/// Codecs and plug-ins must be registered before loading banks that use them.\n
		/// Loading a bank referencing an unregistered plug-in or codec will result in a load bank success,
		/// but the plug-ins will not be used. More specifically, playing a sound that uses an unregistered effect plug-in
		/// will result in audio playback without applying the said effect. If an unregistered source plug-in is used by an event's audio objects,
		/// posting the event will fail.
		virtual AKRESULT RegisterPlugin(
			AkPluginType in_eType,						///< Plug-in type (for example, source or effect)
			AkUInt32 in_ulCompanyID,					///< Company identifier (as declared in the plug-in description XML file)
			AkUInt32 in_ulPluginID,						///< Plug-in identifier (as declared in the plug-in description XML file)
			AkCreatePluginCallback in_pCreateFunc,		///< Pointer to the plug-in's creation function
			AkCreateParamCallback in_pCreateParamFunc	///< Pointer to the plug-in's parameter node creation function
			) = 0;

		/// Register a codec type with the sound engine and set the callback functions to create the
		/// codec's file source and bank source nodes.
		/// \sa
		/// - \ref register_effects
		/// \return AK_Success if successful, AK_InvalidParameter if invalid parameters were provided, or Ak_Fail otherwise. Possible reasons for an AK_Fail result are:
		/// - Insufficient memory to register the codec
		/// - Codec ID already registered
		/// \remarks
		/// Codecs and plug-ins must be registered before loading banks that use them.\n
		/// Loading a bank referencing an unregistered plug-in or codec will result in a load bank success,
		/// but the plug-ins will not be used. More specifically, playing a sound that uses an unregistered effect plug-in
		/// will result in audio playback without applying the said effect. If an unregistered source plug-in is used by an event's audio objects,
		/// posting the event will fail.
		virtual AKRESULT RegisterCodec(
			AkUInt32 in_ulCompanyID,						///< Company identifier (as declared in XML)
			AkUInt32 in_ulPluginID,							///< Plugin identifier (as declared in XML)
			AkCreateFileSourceCallback in_pFileCreateFunc,  ///< Factory for streaming sources.
			AkCreateBankSourceCallback in_pBankCreateFunc   ///< Factory for in-memory sources.
			) = 0;

		/// Register a global callback function. This function will be called from the audio rendering thread, at the
		/// location specified by in_eLocation. This function will also be called from the thread calling
		/// AK::SoundEngine::Term with in_eLocation set to AkGlobalCallbackLocation_Term.
		/// For example, in order to be called at every audio rendering pass, and once during teardown for releasing resources, you would call
		/// RegisterGlobalCallback(AkPluginTypeEffect, MY_COMPANY_ID , MY_PLUGIN_ID, myCallback, AkGlobalCallbackLocation_BeginRender | AkGlobalCallbackLocation_Term, myCookie);
		/// \remarks
		/// A valid (not AkPluginTypeNone) Plugin Type, Company ID and valid (non-zero) Plug-in ID of the plug-in registering the callback must be provided to this function.
		/// The timing of the callback function will contribute to the timing of the plug-in registered (Total Plug-in CPU and Advanced Profiler Plug-in tab).
		/// Timers will be registered to callbacks at all locations except for \c AkGlobalCallbackLocation::AkGlobalCallbackLocation_Register and \c AkGlobalCallbackLocation::AkGlobalCallbackLocation_Term.
		/// It is only legal to call this function from inside the plug-in registration callback, exclusively when receiving \c AkGlobalCallbackLocation::AkGlobalCallbackLocation_Register.
		/// This function should not be called from inside the plug-in instance (e.g. in Init, Execute, etc.) to prevent deadlocks when processing plug-ins in parallel.
		/// It is illegal to call this function while already inside of a registered global callback.
		/// This function might stall for several milliseconds before returning.
		/// \sa
		/// - \ref fx_global_hooks
		/// - AK::IAkGlobalPluginContext::UnregisterGlobalCallback()
		/// - AkGlobalCallbackFunc
		/// - AkGlobalCallbackLocation
		virtual AKRESULT RegisterGlobalCallback(
			AkPluginType in_eType,							///< A valid Plug-in type (for example, source or effect).
			AkUInt32 in_ulCompanyID,						///< Company identifier (as declared in the plug-in description XML file). 
			AkUInt32 in_ulPluginID,							///< Plug-in identifier (as declared in the plug-in description XML file).
			AkGlobalCallbackFunc in_pCallback,				///< Function to register as a global callback.
			AkUInt32 in_eLocation = AkGlobalCallbackLocation_BeginRender, ///< Callback location defined in AkGlobalCallbackLocation. Bitwise OR multiple locations if needed.
			void * in_pCookie = NULL						///< User cookie.
			) = 0;

		/// Unregister a global callback function, previously registered using RegisterGlobalCallback.
		/// \remarks
		/// It is only legal to call this function from inside the plug-in registration global callback, exclusively when receiving \c AkGlobalCallbackLocation::AkGlobalCallbackLocation_Term.
		/// This function should not be called from inside the plug-in instance (e.g. in Init, Execute, etc.) to prevent deadlocks when processing plug-ins in parallel.
		/// It is illegal to call this function while already inside of a registered global callback.
		/// This function might stall for several milliseconds before returning.
		/// \sa
		/// - \ref fx_global_hooks
		/// - AK::IAkGlobalPluginContext::RegisterGlobalCallback()
		/// - AkGlobalCallbackFunc
		/// - AkGlobalCallbackLocation
		virtual AKRESULT UnregisterGlobalCallback(
			AkGlobalCallbackFunc in_pCallback,				///< Function to unregister as a global callback.
			AkUInt32 in_eLocation = AkGlobalCallbackLocation_BeginRender ///< Must match in_eLocation as passed to RegisterGlobalCallback for this callback.
			) = 0;

		/// Get the default allocator for plugins. This is useful for performing global initialization tasks shared across multiple plugin instances.
		virtual AK::IAkPluginMemAlloc * GetAllocator() = 0;

		/// \sa SetRTPCValue
		virtual AKRESULT SetRTPCValue(
			AkRtpcID in_rtpcID, 									///< ID of the game parameter
			AkRtpcValue in_value, 									///< Value to set
			AkGameObjectID in_gameObjectID = AK_INVALID_GAME_OBJECT,///< Associated game object ID
			AkTimeMs in_uValueChangeDuration = 0,					///< Duration during which the game parameter is interpolated towards in_value
			AkCurveInterpolation in_eFadeCurve = AkCurveInterpolation_Linear,	///< Curve type to be used for the game parameter interpolation
			bool in_bBypassInternalValueInterpolation = false		///< True if you want to bypass the internal "slew rate" or "over time filtering" specified by the sound designer. This is meant to be used when for example loading a level and you dont want the values to interpolate.
			) = 0;

		/// Send custom game data to a plugin that resides on a bus (insert effect or mixer plugin).
		/// Data will be copied and stored into a separate list.
		/// Previous entry is deleted when a new one is sent.
		/// Set the data pointer to NULL to clear item from the list.
		/// This means that you cannot send different data to various instances of the plugin on a same bus.\endaknote
		/// \return AK_Success if data was sent successfully.
		virtual AKRESULT SendPluginCustomGameData(
			AkUniqueID in_busID,			///< Bus ID
			AkGameObjectID in_busObjectID,	///< Bus Object ID
			AkPluginType in_eType,			///< Plug-in type (for example, source or effect)
			AkUInt32 in_uCompanyID,		///< Company identifier (as declared in the plug-in description XML file)
			AkUInt32 in_uPluginID,			///< Plug-in identifier (as declared in the plug-in description XML file)
			const void* in_pData,			///< The data blob
			AkUInt32 in_uSizeInBytes		///< Size of data
			) = 0;

		/// Computes gain vector for encoding a source with angles in_fAzimuth and in_fElevation to full-sphere ambisonics with order in_uOrder.
		/// Ambisonic channels are ordered by ACN and use the SN3D convention.
		virtual void ComputeAmbisonicsEncoding(
			AkReal32			in_fAzimuth,				///< Incident angle, in radians [-pi,pi], where 0 is the front (positive values are clockwise).
			AkReal32			in_fElevation,				///< Incident angle, in radians [-pi/2,pi/2], where 0 is the azimuthal plane.
			AkChannelConfig		in_cfgAmbisonics,			///< Determines number of gains in vector out_vVolumes.
			AK::SpeakerVolumes::VectorPtr out_vVolumes		///< Returned volumes (see AK::SpeakerVolumes::Vector services). Must be allocated prior to calling this function with the size returned by AK::SpeakerVolumes::Vector::GetRequiredSize() for the desired number of channels.
			) = 0;

		/// Computes gain matrix for decoding an SN3D-normalized ACN-ordered ambisonic signal of order sqrt(in_cfgAmbisonics.uNumChannels)-1, with max-RE weighting function, on a (regularly) sampled sphere whose samples in_samples are 
		/// expressed in left-handed cartesian coordinates, with unitary norm.
		/// This decoding technique is optimal for regular sampling.
		/// The returned matrix has in_cfgAmbisonics.uNumChannels inputs (rows) and in_uNumSamples outputs (columns), and is normalized by the number of samples. 
		/// You may use the returned volume matrix with IAkPluginServiceMixer::MixNinNChannels.
		/// Supported ambisonic configurations are full-sphere 1st to 5th order.
		/// \return 
		/// - \c AK_InvalidParameter if in_cfgAmbisonics is not an ambisonic configuration. 
		/// - \c AK_InvalidParameter if in_cfgAmbisonics does not have enough channel for a valid ambisonic configuration of the specified order.
		/// - \c AK_InvalidParameter if in_samples contains non-normalized vectors (not unity length).
		/// - \c AK_Success otherwise.
		virtual AKRESULT ComputeWeightedAmbisonicsDecodingFromSampledSphere(
			const AkVector      in_samples[],             ///< Array of vector samples expressed in left-handed cartesian coordinates, where (1,0,0) points towards the right and (0,1,0) points towards the top. Vectors must be normalized.
			AkUInt32            in_uNumSamples,           ///< Number of points in in_samples.
			AkChannelConfig     in_cfgAmbisonics,         ///< Ambisonic configuration. Supported configurations are 1st to 5th order. Determines number of rows (input channels) in matrix out_mxVolume.
			AK::SpeakerVolumes::MatrixPtr out_mxVolume    ///< Returned volume matrix of in_cfgAmbisonics.uNumChannels rows x in_uNumSamples colums. Must be allocated prior to calling this function with the size returned by AK::SpeakerVolumes::Matrix::GetRequiredSize() for the desired number of channels.
			) = 0;

		/// Return an acoustic texture.
		/// \return The pointer to an acoustic texture if successful, NULL otherwise.
		virtual const AkAcousticTexture* GetAcousticTexture(
			AkAcousticTextureID in_AcousticTextureID		///< Acoustic Texture's ID
			) = 0;

		/// Given an emitter-listener pair, compute the azimuth and elevation angles of the emitter relative to the listener.
		/// \return AK_Success if the listener referenced in the emitter-listener pair was found; azimuth and elevation.
		virtual AKRESULT ComputeSphericalCoordinates(
			const AkEmitterListenerPair & in_pair,			///< Emitter-listener pair for which to compute azimuth and elevation angles.
			AkReal32 & out_fAzimuth,						///< Returned azimuthal angle, in radians.
			AkReal32 & out_fElevation						///< Returned elevation angle, in radians.
			) const = 0;

		/// Get the platform init settings that the wwise sound engine has been initialized with.
		/// This function returns a null pointer if called with an instance of RenderFXGlobalContext.
		virtual const AkPlatformInitSettings* GetPlatformInitSettings() const = 0;
		
		/// Get the init settings that the wwise sound engine has been initialized with
		/// This function returns a null pointer if called with an instance of RenderFXGlobalContext.
		virtual const AkInitSettings* GetInitSettings() const = 0;

		/// Gets the configured audio settings.
		/// Call this function to get the configured audio settings.
		/// 
		/// \warning This function is not thread-safe.
		/// \warning Call this function only after the sound engine has been properly initialized.
		virtual AKRESULT GetAudioSettings(
			AkAudioSettings &	out_audioSettings  	///< Returned audio settings
			) const = 0;

		/// Universal converter from string to ID for the sound engine.
		/// Calls AK::SoundEngine::GetIDFromString.
		/// \sa
		/// - <tt>AK::SoundEngine::GetIDFromString</tt>
		virtual AkUInt32 GetIDFromString(const char* in_pszString) const = 0;

		/// Synchronously posts an Event to the sound engine (by event ID).
		/// The callback function can be used to be noticed when markers are reached or when the event is finished.
		/// An array of wave file sources can be provided to resolve External Sources triggered by the event. 
		/// \return The playing ID of the event launched, or AK_INVALID_PLAYING_ID if posting the event failed
		/// \remarks
		/// This function executes the actions contained in the event without going through the message queue.
		/// In order to do so it acquires the global Wwise sound engine lock. It should therefore only be called from one of the 
		/// global engine hooks (see AK::IAkGlobalPluginContext::RegisterGlobalCallback).
		/// Use AK::IAkGlobalPluginContext::GetIDFromString() if you use event names (strings).
		/// \sa 
		/// - <tt>AK::SoundEngine::PostEvent</tt>
		/// - <tt>AK::IAkGlobalPluginContext::RegisterGlobalCallback</tt>
		/// - <tt>AK::IAkGlobalPluginContext::GetIDFromString</tt>
		virtual AkPlayingID PostEventSync(
			AkUniqueID in_eventID,							///< Unique ID of the event
			AkGameObjectID in_gameObjectID,					///< Associated game object ID
			AkUInt32 in_uFlags = 0,							///< Bitmask: see \ref AkCallbackType
			AkCallbackFunc in_pfnCallback = NULL,			///< Callback function
			void * in_pCookie = NULL,						///< Callback cookie that will be sent to the callback function along with additional information
			AkUInt32 in_cExternals = 0,						///< Optional count of external source structures
			AkExternalSourceInfo *in_pExternalSources = NULL,///< Optional array of external source resolution information
			AkPlayingID	in_PlayingID = AK_INVALID_PLAYING_ID///< Optional (advanced users only) Specify the playing ID to target with the event. Will Cause active actions in this event to target an existing Playing ID. Let it be AK_INVALID_PLAYING_ID or do not specify any for normal playback.
			) = 0;
		
		/// Executes a number of MIDI Events on all nodes that are referenced in the specified Event in an Action of type Play.
		/// Each MIDI event will be posted in AkMIDIPost::uOffset samples from the start of the current frame. The duration of
		/// a sample can be determined from the sound engine's audio settings, via a call to AK::IAkGlobalPluginContext::GetAudioSettings.
		/// \remarks
		/// This function executes the MIDI Events without going through the message queue.
		/// In order to do so it acquires the global Wwise sound engine lock. It should therefore only be called from one of the 
		/// global engine hooks (see AK::IAkGlobalPluginContext::RegisterGlobalCallback).
		/// Use AK::IAkGlobalPluginContext::GetIDFromString() if you use event names (strings).
		/// \sa 
		/// - <tt>AK::SoundEngine::PostMIDIOnEvent</tt>
		/// - <tt>AK::IAkGlobalPluginContext::GetAudioSettings</tt>
		/// - <tt>AK::IAkGlobalPluginContext::StopMIDIOnEventSync</tt>
		/// - <tt>AK::IAkGlobalPluginContext::RegisterGlobalCallback</tt>
		/// - <tt>AK::IAkGlobalPluginContext::GetIDFromString</tt>
		virtual AkPlayingID PostMIDIOnEventSync(
			AkUniqueID in_eventID,											///< Unique ID of the Event
			AkGameObjectID in_gameObjectID,									///< Associated game object ID
			AkMIDIPost* in_pPosts,											///< MIDI Events to post
			AkUInt16 in_uNumPosts,											///< Number of MIDI Events to post
			bool in_bAbsoluteOffsets = false,								///< Whether AkMIDIPost::uOffset values are relative to current frame or absolute
			AkUInt32 in_uFlags = 0,											///< Bitmask: see \ref AkCallbackType
			AkCallbackFunc in_pfnCallback = NULL,							///< Callback function
			void * in_pCookie = NULL,										///< Callback cookie that will be sent to the callback function along with additional information
			AkPlayingID in_playingID = AK_INVALID_PLAYING_ID				///< Target playing ID
			) = 0;

		/// Stops MIDI notes on all nodes that are referenced in the specified event in an action of type play,
		/// with the specified Game Object. Invalid parameters are interpreted as wildcards. For example, calling
		/// this function with in_eventID set to AK_INVALID_UNIQUE_ID will stop all MIDI notes for Game Object
		/// in_gameObjectID.
		/// \remarks
		/// This function stops the MIDI notes without going through the message queue.
		/// In order to do so it acquires the global Wwise sound engine lock. It should therefore only be called from one of the 
		/// global engine hooks (see AK::IAkGlobalPluginContext::RegisterGlobalCallback).
		/// Use AK::IAkGlobalPluginContext::GetIDFromString() if you use event names (strings).
		/// \sa
		/// - <tt>AK::IAkGlobalPluginContext::PostMIDIOnEvent</tt>
		/// - <tt>AK::IAkGlobalPluginContext::GetIDFromString</tt>
		virtual AKRESULT StopMIDIOnEventSync(
			AkUniqueID in_eventID = AK_INVALID_UNIQUE_ID,					///< Unique ID of the Event
			AkGameObjectID in_gameObjectID = AK_INVALID_GAME_OBJECT,		///< Associated game object ID
			AkPlayingID in_playingID = AK_INVALID_PLAYING_ID				///< Target playing ID
			) = 0;

		/// \return The gateway to platform-specific functionality
		/// \sa IAkPlatformContext
		virtual IAkPlatformContext * GetPlatformContext() const = 0;

		/// Retrieves a plug-in service to provide specific "helper" functionality. Note that each service should provide
		/// macros that handle the casting to the appropriate service, and are recommended instead of calling this directly.
		/// Note that all plug-in service are statically allocated, and any references to them can be cached without lifetime checks.
		virtual IAkPluginService* GetPluginService(
			AkPluginServiceType in_pluginService ///< Enum value for the specific plug-in service to fetch
		) const = 0;

		/// Obtains the current audio output buffer tick. This corresponds to the number of buffers produced by
		/// the sound engine since initialization. 
		/// \return Tick count.
		virtual AkUInt32 GetBufferTick() const = 0;
	};

	/// Interface for the "Mixer" plug-in service, to handle mixing together of signals, or applying simple transforms
	class IAkPluginServiceMixer : public IAkPluginService
	{
	protected:
		virtual ~IAkPluginServiceMixer() {}
	public:
		/// N to N channels mix
		virtual void MixNinNChannels(
			AkAudioBuffer* in_pInputBuffer,				///< Input multichannel buffer.
			AkAudioBuffer* in_pMixBuffer,					///< Multichannel buffer with which the input buffer is mixed.
			AkReal32		in_fPrevGain,					///< Gain, corresponding to the beginning of the buffer, to apply uniformly to each mixed channel.
			AkReal32		in_fNextGain,					///< Gain, corresponding to the end of the buffer, to apply uniformly to each mixed channel.
			AK::SpeakerVolumes::ConstMatrixPtr in_mxPrevVolumes,///< In/out channel volume distribution corresponding to the beginning of the buffer (see AK::SpeakerVolumes::Matrix services).
			AK::SpeakerVolumes::ConstMatrixPtr in_mxNextVolumes	///< In/out channel volume distribution corresponding to the end of the buffer (see AK::SpeakerVolumes::Matrix services).
		) = 0;

		/// 1 to N channels mix
		virtual void Mix1inNChannels(
			AkReal32* AK_RESTRICT in_pInChannel,			///< Input channel buffer.
			AkAudioBuffer* in_pMixBuffer,					///< Multichannel buffer with which the input buffer is mixed.
			AkReal32		in_fPrevGain,					///< Gain, corresponding to the beginning of the input channel.
			AkReal32		in_fNextGain,					///< Gain, corresponding to the end of the input channel.
			AK::SpeakerVolumes::ConstVectorPtr in_vPrevVolumes,	///< Output channel volume distribution corresponding to the beginning of the buffer (see AK::SpeakerVolumes::Vector services).
			AK::SpeakerVolumes::ConstVectorPtr in_vNextVolumes	///< Output channel volume distribution corresponding to the end of the buffer (see AK::SpeakerVolumes::Vector services).
		) = 0;

		/// Single channel mix
		virtual void MixChannel(
			AkReal32* AK_RESTRICT in_pInBuffer,			///< Input channel buffer.
			AkReal32* AK_RESTRICT in_pOutBuffer,			///< Output channel buffer.
			AkReal32		in_fPrevGain,					///< Gain, corresponding to the beginning of the input channel.
			AkReal32		in_fNextGain,					///< Gain, corresponding to the end of the input channel.
			AkUInt16		in_uNumFrames					///< Number of frames to mix.
		) = 0;

		/// Given non-interleaved audio in the provided in_pInputBuffer, will apply a ramping gain over the number
		/// of frames specified, and store the result in in_pOutputBuffer. Channel data from in_pInputBuffer will also be
		/// interleaved in in_pOutputBuffer's results, and optionally converted from 32-bit floats to 16-bit integers.
		virtual void ApplyGainAndInterleave(
			AkAudioBuffer* in_pInputBuffer,		///< Input audioBuffer data
			AkAudioBuffer* in_pOutputBuffer,	///< Output audioBuffer data
			AkRamp in_gain,						///< Ramping gain to apply over duration of buffer
			bool in_convertToInt16				///< Whether the input data should be converted to int16
		) const = 0;

		/// Given non-interleaved audio in the provided in_pInputBuffer, will apply a ramping gain over the number
		/// of frames specified, and store the result in in_pOutputBuffer. Audio data in in_pOutputBuffer will have
		/// the same layout as in_pInputBuffer, and optionally converted from 32-bit floats to 16-bit integers.
		virtual void ApplyGain(
			AkAudioBuffer* in_pInputBuffer,		///< Input audioBuffer data
			AkAudioBuffer* in_pOutputBuffer,	///< Output audioBuffer data
			AkRamp in_gain,						///< Ramping gain to apply over duration of buffer
			bool in_convertToInt16				///< Whether the input data should be converted to int16
		) const = 0;
	};
	
	/// Interface for the services related to generating pseudorandom numbers
	/// \sa
	/// - <tt>AK::SoundEngine::SetRandomSeed()</tt>
	/// - <tt>CAkRng</tt>
	class IAkPluginServiceRNG : public IAkPluginService
	{
	protected:
		virtual ~IAkPluginServiceRNG() {}
	public:
		/// Advances and returns a PRNG seed that a plug-in may use in its own RNG for DSP processing
		/// This is the same seed used for the internal sound engine randomization.
		virtual AkUInt64 RandomSeed() const = 0;

		/// Advances the internal PRNG seed, and returns a random number generator suitable for DSP processing
		virtual CAkRng CreateRNG() const = 0;
	};

	/// Interface for the services related to extracting attenuation curves from audio objects and using them.
	class IAkPluginServiceAudioObjectAttenuation : public IAkPluginService
	{
	protected:
		virtual ~IAkPluginServiceAudioObjectAttenuation() {}
	public:
		
		/// Obtain the unique ID of the Attenuation curves attached to the provided audio object. 
		/// \return The unique ID of the Attenuation curves (Shareset or Custom). AK_INVALID_UNIQUE_ID if not the audio object does not have Attenuation curves.
		virtual AkUniqueID GetAttenuationID(
			const AkAudioObject& in_object	///< Audio object from which to get the attenuation ID.
		) const = 0;

		/// Extract the curve of a given type from the set of Attenuation curves attached to the given audio object.
		/// The curve's data is copied into an opaque data structure, pointed to by out_curve.
		/// The curve's data remain until the client of this service calls AK::IAkPluginServiceAttenuationCurve::Delete.
		/// \return true if the copy succeeded, or if the requested curve was not initialized.
		virtual bool ExtractCurves(
			IAkPluginMemAlloc* in_pAllocator,	///< Memory allocator.
			const AkAudioObject & in_object,	///< The audio object from which to extract the curve.
			AkUInt32 in_curveTypesMask,	///< The set of curves, identified with a mask of bits offset by AkAttenuationCurveType values, to extract from the set of Attenuation curves. For example, set to (1 << AttenuationCurveID_VolumeDry | 1 << AttenuationCurveID_Spread) to obtain the distance-driven dry volume and spread curves.
			void* out_curves[]	///< The returned addresses of the requested curve data. Pass in an array of void* with length corresponding to the number of desired curves. For each curve, if it exists, a blob of data is allocated by the function and the address is returned in the corresponding item of the out_curves. The item is set to nullptr if the curve does not exist.
		) const = 0;

		/// Free memory of curve obtained with AK::IAkPluginServiceAttenuationCurve::ExtractCurves.
		virtual void Delete(
			IAkPluginMemAlloc* in_pAllocator,	///< Memory allocator.
			void*& io_attenuationCurve	///< Curve to delete.
		) = 0;
		
		/// Evaluate the value of a curve at given x coordinate.
		virtual AkReal32 Evaluate(
			void*& io_attenuationCurve, ///< Curve to evaluate.
			AkReal32 x ///< Value on the abscissa.
		) = 0;

		/// Some curves are serialized in the log domain. Use this function to convert all the points to linear at once.
		virtual void Linearize(void*& io_attenuationCurve) = 0;

		/// Get the ith point of the curve.
		virtual const AkRTPCGraphPoint& GetPoint(
			const void* in_attenuationCurve, ///< Curve.
			AkUInt32 i	///< Point index. Must be between 0 and AK::IAkPluginServiceAttenuationCurve::GetNumPoints-1 inclusively.
		) const = 0;

		/// Get the number of points on a curve.
		virtual AkUInt32 GetNumPoints(
			const void* in_attenuationCurve ///< Curve.
		) const = 0;
	};

	/// Interface for the audio object priority service, to retrieve and update playback priority on audio objects.
	/// Playback priority of the audio object may be used by the audio endpoint when there are more audio objects than the available hardware objects
	/// to determine which audio objects should be mixed as hardware objects in priority and which can be mixed to a lower resolution 3D bed.
	/// \sa
	/// - <a href="https://www.audiokinetic.com/library/edge/?source=Help&id=defining_playback_priority" target="_blank">Defining Playback Priority</a>
	/// - <tt>AkAudioObject</tt>
	/// - <tt>AkPriority</tt>
	class IAkPluginServiceAudioObjectPriority : public IAkPluginService
	{
	protected:
		virtual ~IAkPluginServiceAudioObjectPriority() {}
	public:
		/// Populates <tt>out_pPriorities</tt> with playback priorities for objects in <tt>in_ppObjects</tt>.
		virtual void GetPriorities(
			AkAudioObject** in_ppObjects, ///< Array of pointers to audio objects to extract priorites from.
			AkUInt32 in_uNumObjects,      ///< The number of audio objects in <tt>in_ppObjects</tt>. Must correspond to the number of priorites in <tt>out_pPriorities</tt>.
			AkPriority* out_pPriorities   ///< Priorities to fill from <tt>in_ppObjects</tt>. Must be large enough to contain <tt>in_uNumObjects</tt> priorities.
		) = 0;

		/// Sets the playback priority of each of the <tt>in_uNumObjects</tt> audio objects in <tt>io_ppObjects</tt> from <tt>in_pPriorities</tt>.
		virtual void SetPriorities(
			AkAudioObject** io_ppObjects, ///< Array of pointers to audio objects for which to update the playback priority.
			AkUInt32 in_uNumObjects,      ///< The number of audio objects in <tt>in_ppObjects</tt>. Must correspond to the number of priorites in <tt>in_pPriorities</tt>.
			AkPriority* in_pPriorities    ///< Array of priorities to set on <tt>in_ppObjects</tt>. Must contain <tt>in_uNumObjects</tt> priorities.
		) = 0;
	};

	#define AK_GET_PLUGIN_SERVICE_MIXER(plugin_ctx) static_cast<AK::IAkPluginServiceMixer*>(plugin_ctx->GetPluginService(AK::PluginServiceType_Mixer))
	#define AK_GET_PLUGIN_SERVICE_RNG(plugin_ctx) static_cast<AK::IAkPluginServiceRNG*>(plugin_ctx->GetPluginService(AK::PluginServiceType_RNG))
	#define AK_GET_PLUGIN_SERVICE_AUDIO_OBJECT_ATTENUATION(plugin_ctx) static_cast<AK::IAkPluginServiceAudioObjectAttenuation*>(plugin_ctx->GetPluginService(AK::PluginServiceType_AudioObjectAttenuation))
	#define AK_GET_PLUGIN_SERVICE_AUDIO_OBJECT_PRIORITY(plugin_ctx) static_cast<AK::IAkPluginServiceAudioObjectPriority*>(plugin_ctx->GetPluginService(AK::PluginServiceType_AudioObjectPriority))

	/// This class takes care of the registration of plug-ins in the Wwise engine.  Plug-in developers must provide one instance of this class for each plug-in.
	/// \sa
	/// - \ref soundengine_plugins
	class PluginRegistration
	{
	public:
		PluginRegistration(
			AkUInt32 in_ulCompanyID,						///< Plugin company ID.
			AkUInt32 in_ulPluginID							///< Plugin ID.
			)
		{
			// Placeholder used for plug-in extensions (plug-ins that modify the behavior of an existing plug-in without registering a new ID)
		}

		PluginRegistration(
			AkPluginType in_eType,								///< Plugin type.
			AkUInt32 in_ulCompanyID,							///< Plugin company ID.
			AkUInt32 in_ulPluginID,								///< Plugin ID.
			AkCreatePluginCallback in_pCreateFunc,				///< Plugin object factory.
			AkCreateParamCallback in_pCreateParamFunc,			///< Plugin parameter object factory.
			AkGlobalCallbackFunc in_pRegisterCallback = NULL,	///< Optional callback function called after successful plugin registration, with argument AkGlobalCallbackLocation_Register.
			void * in_pRegisterCallbackCookie = NULL			///< Optional cookie passed to register callback function above.
			)
			: pNext(g_pAKPluginList)
			, m_eType(in_eType)
			, m_ulCompanyID(in_ulCompanyID)
			, m_ulPluginID(in_ulPluginID)
			, m_pCreateFunc(in_pCreateFunc)
			, m_pCreateParamFunc(in_pCreateParamFunc)
			, m_pFileCreateFunc(NULL)		// Legacy
			, m_pBankCreateFunc(NULL)		// Legacy
			, m_pRegisterCallback(in_pRegisterCallback)
			, m_pRegisterCallbackCookie(in_pRegisterCallbackCookie)
			, m_pGetDeviceListFunc(NULL)
			, m_CodecDescriptor{ nullptr, nullptr, nullptr, nullptr }
		{
			g_pAKPluginList = this;
		}

		PluginRegistration(
			AkPluginType in_eType,								///< Plugin type.
			AkUInt32 in_ulCompanyID,							///< Plugin company ID.
			AkUInt32 in_ulPluginID,								///< Plugin ID.
			AkCreatePluginCallback in_pCreateFunc,				///< Plugin object factory.
			AkCreateParamCallback in_pCreateParamFunc,				///< Plugin parameter object factory.
			AkGetDeviceListCallback in_pGetDeviceListFunc,	///< Plugin parameter object factory.
			AkGlobalCallbackFunc in_pRegisterCallback = NULL,	///< Optional callback function called after successful plugin registration, with argument AkGlobalCallbackLocation_Register.
			void * in_pRegisterCallbackCookie = NULL			///< Optional cookie passed to register callback function above.
		)
			: pNext(g_pAKPluginList)
			, m_eType(in_eType)
			, m_ulCompanyID(in_ulCompanyID)
			, m_ulPluginID(in_ulPluginID)
			, m_pCreateFunc(in_pCreateFunc)
			, m_pCreateParamFunc(in_pCreateParamFunc)
			, m_pFileCreateFunc(NULL)		// Legacy
			, m_pBankCreateFunc(NULL)		// Legacy
			, m_pRegisterCallback(in_pRegisterCallback)
			, m_pRegisterCallbackCookie(in_pRegisterCallbackCookie)
			, m_pGetDeviceListFunc(in_pGetDeviceListFunc)
			, m_CodecDescriptor{ nullptr, nullptr, nullptr, nullptr }
		{
			g_pAKPluginList = this;
		}

		PluginRegistration(
			AkUInt32 in_ulCompanyID,						///< Plugin company ID.
			AkUInt32 in_ulPluginID,							///< Plugin ID.
			AkCreateFileSourceCallback in_pCreateFile,		///< Streamed source factory.
			AkCreateBankSourceCallback in_pCreateBank)		///< In-memory source factory.
			: pNext(g_pAKPluginList)
			, m_eType(AkPluginTypeCodec)
			, m_ulCompanyID(in_ulCompanyID)
			, m_ulPluginID(in_ulPluginID)
			, m_pCreateFunc(NULL)
			, m_pCreateParamFunc(NULL)
			, m_pFileCreateFunc(in_pCreateFile)		// Legacy
			, m_pBankCreateFunc(in_pCreateBank)		// Legacy
			, m_pRegisterCallback(NULL)
			, m_pRegisterCallbackCookie(NULL)
			, m_pGetDeviceListFunc(NULL)
			, m_CodecDescriptor{ in_pCreateFile, in_pCreateBank, nullptr, nullptr }
		{
			g_pAKPluginList = this;
		}

		PluginRegistration(
			AkUInt32 in_ulCompanyID,                        ///< Plugin company ID.
			AkUInt32 in_ulPluginID,                         ///< Plugin ID.
			const AkCodecDescriptor &in_Descriptor)         ///< Codec descriptor.
			: pNext(g_pAKPluginList)
			, m_eType(AkPluginTypeCodec)
			, m_ulCompanyID(in_ulCompanyID)
			, m_ulPluginID(in_ulPluginID)
			, m_pCreateFunc(NULL)
			, m_pCreateParamFunc(NULL)
			, m_pFileCreateFunc(in_Descriptor.pFileSrcCreateFunc)		// Legacy
			, m_pBankCreateFunc(in_Descriptor.pBankSrcCreateFunc)		// Legacy
			, m_pRegisterCallback(NULL)
			, m_pRegisterCallbackCookie(NULL)
			, m_pGetDeviceListFunc(NULL)
			, m_CodecDescriptor(in_Descriptor)
		{
			g_pAKPluginList = this;
		}

		PluginRegistration *pNext;
		AkPluginType m_eType;
		AkUInt32 m_ulCompanyID;
		AkUInt32 m_ulPluginID;
		AkCreatePluginCallback m_pCreateFunc;
		AkCreateParamCallback m_pCreateParamFunc;
		AkCreateFileSourceCallback m_pFileCreateFunc;		///< LEGACY: Kept for compatibility with 2019.1. Unused in 2019.2 and up.
		AkCreateBankSourceCallback m_pBankCreateFunc;		///< LEGACY: Kept for compatibility with 2019.1. Unused in 2019.2 and up.
		AkGlobalCallbackFunc m_pRegisterCallback;
		void * m_pRegisterCallbackCookie;
		
		// 2019.2 added parameters
		AkGetDeviceListCallback m_pGetDeviceListFunc;
		AkCodecDescriptor m_CodecDescriptor;
	};
}

#define AK_IMPLEMENT_PLUGIN_FACTORY(_pluginName_, _plugintype_, _companyid_, _pluginid_) \
	AK::IAkPlugin* Create##_pluginName_(AK::IAkPluginMemAlloc * in_pAllocator); \
	AK::IAkPluginParam * Create##_pluginName_##Params(AK::IAkPluginMemAlloc * in_pAllocator); \
	AK_ATTR_USED AK::PluginRegistration _pluginName_##Registration(_plugintype_, _companyid_, _pluginid_, Create##_pluginName_, Create##_pluginName_##Params);

#define AK_STATIC_LINK_PLUGIN(_pluginName_) \
	extern AK::PluginRegistration _pluginName_##Registration; \
	void *_pluginName_##_linkonceonly = (void*)&_pluginName_##Registration;

#define DEFINE_PLUGIN_REGISTER_HOOK AK_DLLEXPORT AK::PluginRegistration * g_pAKPluginList = NULL;

#define AK_GET_SINK_TYPE_FROM_DEVICE_KEY(_key) ((AkUInt32)(_key & 0xffffffff))
#define AK_GET_DEVICE_ID_FROM_DEVICE_KEY(_key) ((AkUInt32)(_key >> 32))

#endif // _IAK_PLUGIN_H_
