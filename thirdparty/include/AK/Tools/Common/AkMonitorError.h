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

#ifndef _AKMONITORERROR_H
#define _AKMONITORERROR_H

#include <AK/SoundEngine/Common/AkSoundEngineExport.h>
#include <AK/SoundEngine/Common/AkTypes.h>
#define ERROR_CODE_DEF( in_name, in_msg ){ MonitorErrorInfo(in_name, in_msg)  }

struct AkStreamMgrSettings;
struct AkDeviceSettings;
class AkErrorMessageTranslator;

namespace AK
{
    // Error monitoring.

	namespace Monitor
	{
		// This structure contains information related to the error message
		struct MsgContext
		{
			MsgContext(AkPlayingID pId = AK_INVALID_PLAYING_ID, AkGameObjectID goId = AK_INVALID_GAME_OBJECT, AkUniqueID nodeId = AK_INVALID_UNIQUE_ID, bool isBus = false)
				:	in_playingID{ pId },
					in_gameObjID{ goId },
					in_soundID{ nodeId },
					in_bIsBus{ isBus }
			{}

			AkPlayingID in_playingID;		///< Related Playing ID if applicable
			AkGameObjectID in_gameObjID;	///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
			AkUniqueID in_soundID;			///< Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise
			bool in_bIsBus;					///< true if in_audioNodeID is a bus
		};

		struct MonitorErrorInfo
		{
			MonitorErrorInfo(const AkOSChar* in_name = nullptr, const AkOSChar* in_message= nullptr)
				:	m_name{ in_name },
					m_message{in_message}

			{}
			const AkOSChar* m_name;
			const AkOSChar* m_message;
		};

		///  ErrorLevel
		enum ErrorLevel
		{
			ErrorLevel_Message	= (1<<0), // used as bitfield
			ErrorLevel_Error	= (1<<1),
			
			ErrorLevel_All = ErrorLevel_Message | ErrorLevel_Error
		};
		/// ErrorCode
		enum ErrorCode
		{
			ErrorCode_NoError = 0, // 0-based index into AK::Monitor::s_aszMonitorErrorInfos table 
			ErrorCode_FileNotFound, 
			ErrorCode_CannotOpenFile,
			ErrorCode_CannotStartStreamNoMemory,
			ErrorCode_IODevice,
			ErrorCode_IncompatibleIOSettings,

			ErrorCode_PluginUnsupportedChannelConfiguration,
			ErrorCode_PluginMediaUnavailable,
			ErrorCode_PluginInitialisationFailed,
			ErrorCode_PluginProcessingFailed,
			ErrorCode_PluginExecutionInvalid,
			ErrorCode_PluginAllocationFailed,

			ErrorCode_VorbisSeekTableRecommended,

			ErrorCode_VorbisDecodeError,

			ErrorCode_ATRAC9DecodeFailed,
			ErrorCode_ATRAC9LoopSectionTooSmall,

			ErrorCode_InvalidAudioFileHeader,
			ErrorCode_AudioFileHeaderTooLarge,
			ErrorCode_LoopTooSmall,

			ErrorCode_TransitionNotAccurateChannel,
			ErrorCode_TransitionNotAccuratePluginMismatch,
			ErrorCode_TransitionNotAccurateRejectedByPlugin,
			ErrorCode_TransitionNotAccurateStarvation,
			ErrorCode_TransitionNotAccurateCodecError,
			ErrorCode_NothingToPlay, 
			ErrorCode_PlayFailed,

			ErrorCode_StingerCouldNotBeScheduled,
			ErrorCode_TooLongSegmentLookAhead,
			ErrorCode_CannotScheduleMusicSwitch,
			ErrorCode_TooManySimultaneousMusicSegments,
			ErrorCode_PlaylistStoppedForEditing,
			ErrorCode_MusicClipsRescheduledAfterTrackEdit,

			ErrorCode_CannotPlaySource_Create,
			ErrorCode_CannotPlaySource_VirtualOff,
			ErrorCode_CannotPlaySource_TimeSkip,
			ErrorCode_CannotPlaySource_InconsistentState,
			ErrorCode_MediaNotLoaded,
			ErrorCode_VoiceStarving,
			ErrorCode_StreamingSourceStarving,
			ErrorCode_XMADecoderSourceStarving,
			ErrorCode_XMADecodingError,
			ErrorCode_InvalidXMAData,

			ErrorCode_PluginNotRegistered,
			ErrorCode_CodecNotRegistered,
			ErrorCode_PluginVersionMismatch,

			ErrorCode_EventIDNotFound,

			ErrorCode_InvalidGroupID,
			ErrorCode_SelectedNodeNotAvailable,
			ErrorCode_SelectedMediaNotAvailable,
			ErrorCode_NoValidSwitch,

			ErrorCode_BankLoadFailed,
			ErrorCode_ErrorWhileLoadingBank,
			ErrorCode_InsufficientSpaceToLoadBank,
			
			ErrorCode_LowerEngineCommandListFull,

			ErrorCode_SeekNoMarker,
			ErrorCode_CannotSeekContinuous,
			ErrorCode_SeekAfterEof,

			ErrorCode_UnknownGameObject,
			ErrorCode_GameObjectNeverRegistered,	//To be used by the Capture Log to replace ErrorCode_UnknownGameObject
			ErrorCode_DeadGameObject,				//To be used by the Capture Log to replace ErrorCode_UnknownGameObject
			ErrorCode_GameObjectIsNotEmitter,

			ErrorCode_ExternalSourceNotResolved,
			ErrorCode_FileFormatMismatch,

			ErrorCode_CommandQueueFull,
			ErrorCode_CommandTooLarge,

			ErrorCode_XMACreateDecoderLimitReached,
			ErrorCode_XMAStreamBufferTooSmall,

			ErrorCode_ModulatorScopeError_Inst,
			ErrorCode_ModulatorScopeError_Obj,

			ErrorCode_SeekAfterEndOfPlaylist,

			ErrorCode_OpusRequireSeekTable,
			ErrorCode_OpusDecodeError,
			
			ErrorCode_SourcePluginNotFound,

			ErrorCode_VirtualVoiceLimit,

			ErrorCode_NotEnoughMemoryToStart,
			ErrorCode_UnknownOpusError,			//Deprecated Opus error.

			ErrorCode_AudioDeviceInitFailure,
			ErrorCode_AudioDeviceRemoveFailure,
			ErrorCode_AudioDeviceNotFound,
			ErrorCode_AudioDeviceNotValid,

			ErrorCode_SpatialAudio_ListenerAutomationNotSupported,
			ErrorCode_MediaDuplicationLength,

			ErrorCode_HwVoicesSystemInitFailed, // When the hardware-accelerated subsystem fails to initialize
			ErrorCode_HwVoicesDecodeBatchFailed, // When a grouping of hardware-accelerated voices fail to decode collectively
			ErrorCode_HwVoiceLimitReached, // Cannot create any more hardware-accelerated voices
			ErrorCode_HwVoiceInitFailed, // A hardware-accelerated voice fails to be created, but not because the max number of voices was reached

			ErrorCode_OpusHWCommandFailed,
			
			ErrorCode_AddOutputListenerIdWithZeroListeners,

			ErrorCode_3DObjectLimitExceeded,

			ErrorCode_OpusHWFatalError,
			ErrorCode_OpusHWDecodeUnavailable,
			ErrorCode_OpusHWTimeout,

			ErrorCode_SystemAudioObjectsUnavailable,

			ErrorCode_AddOutputNoDistinctListener,

			ErrorCode_PluginCannotRunOnObjectConfig,
			ErrorCode_SpatialAudio_ReflectionBusError,

			ErrorCode_VorbisHWDecodeUnavailable,
			ErrorCode_ExternalSourceNoMemorySize,

			ErrorCode_MonitorQueueFull,
			ErrorCode_MonitorMsgTooLarge,

			ErrorCode_NonCompliantDeviceMemory,

			ErrorCode_JobWorkerFuncCallMismatch,
			ErrorCode_JobMgrOutOfMemory,

			ErrorCode_InvalidFileSize,
			ErrorCode_PluginMsg,

			
			ErrorCode_SinkOpenSL,
			ErrorCode_AudioOutOfRange,
			ErrorCode_AudioOutOfRangeOnBus,
			ErrorCode_AudioOutOfRangeOnBusFx,
			ErrorCode_AudioOutOfRangeRay,
			ErrorCode_UnknownDialogueEvent,
			ErrorCode_FailedPostingEvent,
			ErrorCode_OutputDeviceInitializationFailed,
			ErrorCode_UnloadBankFailed,

			ErrorCode_PluginFileNotFound,
			ErrorCode_PluginFileIncompatible,
			ErrorCode_PluginFileNotEnoughMemoryToStart,
			ErrorCode_PluginFileInvalid,
			ErrorCode_PluginFileRegisterFailed,

			ErrorCode_UnknownArgument,

			ErrorCode_DynamicSequenceAlreadyClosed,
			ErrorCode_PendingActionDestroyed,
			ErrorCode_CrossFadeTransitionIgnored,
			ErrorCode_MusicRendererSeekingFailed,

			//MONITOR_ERRORMSG
			ErrorCode_DynamicSequenceIdNotFound,
			ErrorCode_BusNotFoundByName,
			ErrorCode_AudioDeviceShareSetNotFound,
			ErrorCode_AudioDeviceShareSetNotFoundByName,

			ErrorCode_SoundEngineTooManyGameObjects,
			ErrorCode_SoundEngineTooManyPositions,
			ErrorCode_SoundEngineCantCallOnChildBus,
			ErrorCode_SoundEnginePlayingIdNotFound,
			ErrorCode_SoundEngineInvalidTransform,
			ErrorCode_SoundEngineTooManyEventPosts,

			ErrorCode_AudioSubsystemStoppedResponding,
			
			ErrorCode_NotEnoughMemInFunction,
			ErrorCode_FXNotFound,
			ErrorCode_SetMixerNotABus,
			ErrorCode_AudioNodeNotFound,
			ErrorCode_SetMixerFailed,
			ErrorCode_SetBusConfigUnsupported,
			ErrorCode_BusNotFound,

			ErrorCode_MismatchingMediaSize,
			ErrorCode_IncompatibleBankVersion,
			ErrorCode_UnexpectedPrepareGameSyncsCall,
			ErrorCode_MusicEngineNotInitialized,
			ErrorCode_LoadingBankMismatch,

			ErrorCode_MasterBusStructureNotLoaded,
			ErrorCode_TooManyChildren,
			ErrorCode_BankContainUneditableEffect,
			ErrorCode_MemoryAllocationFailed,
			ErrorCode_InvalidFloatPriority,
			ErrorCode_SoundLoadFailedInsufficientMemory,
			ErrorCode_NXDeviceRegistrationFailed,
			ErrorCode_MixPluginOnObjectBus,

			ErrorCode_XboxXMAVoiceResetFailed,
			ErrorCode_XboxACPMessage,
			ErrorCode_XboxFrameDropped,
			ErrorCode_XboxACPError,
			ErrorCode_XboxXMAFatalError,
			ErrorCode_MissingMusicNodeParent,
			ErrorCode_HardwareOpusDecoderError,
			ErrorCode_SetGeometryTooManyTriangleConnected,
			ErrorCode_SetGeometryTriangleTooLarge,
			ErrorCode_SetGeometryFailed,
			ErrorCode_RemovingGeometrySetFailed,
			ErrorCode_SetGeometryInstanceFailed,
			ErrorCode_RemovingGeometryInstanceFailed,

			ErrorCode_RevertingToDefaultAudioDevice,
			ErrorCode_RevertingToDummyAudioDevice,
			ErrorCode_AudioThreadSuspended,
			ErrorCode_AudioThreadResumed,
			ErrorCode_ResetPlaylistActionIgnoredGlobalScope,
			ErrorCode_ResetPlaylistActionIgnoredContinuous,
			ErrorCode_PlayingTriggerRateNotSupported,
			ErrorCode_SetGeometryTriangleIsSkipped,
			ErrorCode_SetGeometryInstanceInvalidTransform,
			
			//AkSpatialAudio:AkMonitorError_WithID
			ErrorCode_SetGameObjectRadiusSizeError,
			ErrorCode_SetPortalNonDistinctRoom,
			ErrorCode_SetPortalInvalidExtent,
			ErrorCode_SpatialAudio_PortalNotFound,

			//Invalid float
			ErrorCode_InvalidFloatInFunction,
			ErrorCode_FLTMAXNotSupported,


			ErrorCode_CannotInitializeAmbisonicChannelConfiguration,
			ErrorCode_CannotInitializePassthrough,
			ErrorCode_3DAudioUnsupportedSize,
			ErrorCode_AmbisonicNotAvailable,

			ErrorCode_NoAudioDevice,

			ErrorCode_Support,
			ErrorCode_ReplayMessage,
			ErrorCode_GameMessage,
			ErrorCode_TestMessage,
			ErrorCode_TranslatorStandardTagTest,
			ErrorCode_TranslatorWwiseTagTest,
			ErrorCode_TranslatorStringSizeTest,

			ErrorCode_InvalidParameter,

			ErrorCode_MaxAudioObjExceeded,
			ErrorCode_MMSNotEnabled,
			ErrorCode_NotEnoughSystemObj,
			ErrorCode_NotEnoughSystemObjWin,

			ErrorCode_TransitionNotAccurateSourceTooShort,

			ErrorCode_AlreadyInitialized,
			ErrorCode_WrongNumberOfArguments,
			ErrorCode_DataAlignement,
			ErrorCode_PluginMsgWithShareSet,
			ErrorCode_SoundEngineNotInit,
			ErrorCode_NoDefaultSwitch,
			ErrorCode_CantSetBoundSwitch,
			ErrorCode_IODeviceInitFailed,
			ErrorCode_SwitchListEmpty,
			ErrorCode_NoSwitchSelected,

			// ALWAYS ADD NEW CODES AT THE END !!!!!!!
			// Otherwise it may break comm compatibility in a patch

			Num_ErrorCodes // THIS STAYS AT END OF ENUM
		};

		static_assert(Num_ErrorCodes == 211,
			"Please document your new ErrorCode "
			"in 'Documentation/Help/source_en/reference/common_errors_capture_log.xml', "
			"then you can increment this value."
		);

		/// Function prototype of local output function pointer.
		AK_CALLBACK( void, LocalOutputFunc )(
			ErrorCode in_eErrorCode,	///< Error code number value
			const AkOSChar* in_pszError,	///< Message or error string to be displayed
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			AkPlayingID in_playingID,   ///< Related Playing ID if applicable, AK_INVALID_PLAYING_ID otherwise
			AkGameObjectID in_gameObjID ///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
			);

		extern const MonitorErrorInfo s_aszMonitorErrorInfos[ Num_ErrorCodes ];

		/// Post a monitoring message or error code. This will be displayed in the Wwise capture
		/// log. Since this function doesn't send variable arguments, be sure that the error code you're posting doesn't contain any tag.
		/// Otherwise, there'll be an undefined behavior
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is 
		///			called in the optimized/release configuration and return AK_NotCompatible.
		AK_EXTERNAPIFUNC( AKRESULT, PostCode )( 
			ErrorCode in_eError,		///< Message or error code to be displayed
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			AkPlayingID in_playingID = AK_INVALID_PLAYING_ID,   ///< Related Playing ID if applicable
			AkGameObjectID in_gameObjID = AK_INVALID_GAME_OBJECT, ///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
			AkUniqueID in_audioNodeID = AK_INVALID_UNIQUE_ID, ///< Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise
			bool in_bIsBus = false		///< true if in_audioNodeID is a bus
			);

		AK_EXTERNAPIFUNC(AKRESULT, PostCodeVarArg)(
			ErrorCode in_eError,		///< Error code to be displayed. This code corresponds to a predefined message, that may have parameters that can be passed in the variable arguments. Check the message format at the end of AkMonitorError.h.
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			MsgContext msgContext,		///< The message context containing the following information : Related Playing ID if applicable, Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise,  Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise and whether if in_audioNodeID is a bus
			...							///< The variable arguments, depending on the ErrorCode posted.
			);

		/// Post a monitoring message. This will be displayed in the Wwise capture log.
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is 
		///			called in the optimized/release configuration and return AK_NotCompatible.
		AK_EXTERNAPIFUNC(AKRESULT, PostCodeVaList)(
			ErrorCode in_eError,		///< Error code to be displayed. This code corresponds to a predefined message, that may have parameters that can be passed in the variable arguments. Check the message format at the end of AkMonitorError.h.
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			MsgContext msgContext,		///< The message context containing the following information : Related Playing ID if applicable, Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise,  Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise and whether if in_audioNodeID is a bus
			::va_list args				///< The variable arguments, depending on the ErrorCode posted.
			);

#ifdef AK_SUPPORT_WCHAR
		/// Post a unicode monitoring message or error string. This will be displayed in the Wwise capture
		/// log.
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is 
		///			called in the optimized/release configuration and return AK_NotCompatible.
		AK_EXTERNAPIFUNC( AKRESULT, PostString )( 
			const wchar_t* in_pszError,	///< Message or error string to be displayed
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			AkPlayingID in_playingID = AK_INVALID_PLAYING_ID,   ///< Related Playing ID if applicable
			AkGameObjectID in_gameObjID = AK_INVALID_GAME_OBJECT, ///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
			AkUniqueID in_audioNodeID = AK_INVALID_UNIQUE_ID, ///< Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise
			bool in_bIsBus = false		///< true if in_audioNodeID is a bus
			);

#endif // #ifdef AK_SUPPORT_WCHAR

		/// Post a monitoring message or error string. This will be displayed in the Wwise capture
		/// log.
		/// \return AK_Success if successful, AK_Fail if there was a problem posting the message.
		///			In optimized mode, this function returns AK_NotCompatible.
		/// \remark This function is provided as a tracking tool only. It does nothing if it is 
		///			called in the optimized/release configuration and return AK_NotCompatible.
		AK_EXTERNAPIFUNC( AKRESULT, PostString )( 
			const char* in_pszError,	///< Message or error string to be displayed
			ErrorLevel in_eErrorLevel,	///< Specifies whether it should be displayed as a message or an error
			AkPlayingID in_playingID = AK_INVALID_PLAYING_ID,   ///< Related Playing ID if applicable
			AkGameObjectID in_gameObjID = AK_INVALID_GAME_OBJECT, ///< Related Game Object ID if applicable, AK_INVALID_GAME_OBJECT otherwise
			AkUniqueID in_audioNodeID = AK_INVALID_UNIQUE_ID, ///< Related Audio Node ID if applicable, AK_INVALID_UNIQUE_ID otherwise
			bool in_bIsBus = false		///< true if in_audioNodeID is a bus
			);

		/// Enable/Disable local output of monitoring messages or errors. Pass 0 to disable,
		/// or any combination of ErrorLevel_Message and ErrorLevel_Error to enable. 
		/// \return AK_Success.
		///			In optimized/release configuration, this function returns AK_NotCompatible.
		AK_EXTERNAPIFUNC( AKRESULT, SetLocalOutput )(
			AkUInt32 in_uErrorLevel	= ErrorLevel_All, ///< ErrorLevel(s) to enable in output. Default parameters enable all.
			LocalOutputFunc in_pMonitorFunc = 0 	  ///< Handler for local output. If NULL, the standard platform debug output method is used.
			);

		/// Add a translator to the wwiseErrorHandler
		/// The additional translators increase the chance of a monitoring messages or errors
		/// to be succeffully translated.
		/// \return AK_Success.
		///	In optimized/release configuration, this function returns AK_NotCompatible.
		AK_EXTERNAPIFUNC( AKRESULT, AddTranslator )(
			AkErrorMessageTranslator* translator,	///< The AkErrorMessageTranslator to add to the WwiseErrorHandler
			bool overridePreviousTranslators = false		///< Whether or not the newly added translator should override all the previous translators. 
															///< In both cases, the default translator will remain
			);

		/// Reset the wwiseErrorHandler to only using the default translator
		/// \return AK_Success.
		///	In optimized/release configuration, this function returns AK_NotCompatible.
		AK_EXTERNAPIFUNC(AKRESULT, ResetTranslator)(
			);

		/// Get the time stamp shown in the capture log along with monitoring messages.
		/// \return Time stamp in milliseconds.
		///			In optimized/release configuration, this function returns 0.
		AK_EXTERNAPIFUNC( AkTimeMs, GetTimeStamp )();

		/// Add the streaming manager settings to the profiler capture.
		AK_EXTERNAPIFUNC(void, MonitorStreamMgrInit)(
			const AkStreamMgrSettings& in_streamMgrSettings
			);

		/// Add device settings to the list of active streaming devices.
		/// The list of streaming devices and their settings will be 
		/// sent to the profiler capture when remote connecting from Wwise.
		/// 
		/// \remark \c AK::Monitor::MonitorStreamMgrTerm must be called to
		///			clean-up memory	used to keep track of active streaming devices.
		AK_EXTERNAPIFUNC(void, MonitorStreamingDeviceInit)(
			AkDeviceID in_deviceID,
			const AkDeviceSettings& in_deviceSettings 
			);

		/// Remove streaming device entry from the list of devices
		/// to send when remote connecting from Wwise.
		AK_EXTERNAPIFUNC(void, MonitorStreamingDeviceDestroyed)(
			AkDeviceID in_deviceID
			);

		/// Monitor streaming manager destruction as part of the
		/// profiler capture.
		/// 
		/// \remark This function must be called to clean-up memory	used by
		///			\c AK::Monitor::MonitorStreamingDeviceInit and \c AK::Monitor::MonitorStreamingDeviceTerm
		/// 		to keep track of active streaming devices.
		AK_EXTERNAPIFUNC(void, MonitorStreamMgrTerm)();
	}
}

// Macros.
#ifndef AK_OPTIMIZED
	#define AK_MONITOR_ERROR( in_eErrorCode ) \
		AK::Monitor::PostCode( in_eErrorCode, AK::Monitor::ErrorLevel_Error )

	#define AK_MONITOR_STREAM_MGR_INIT( in_streamMgrSettings ) \
		AK::Monitor::MonitorStreamMgrInit( in_streamMgrSettings )

	#define AK_MONITOR_STREAMING_DEVICE_INIT( in_deviceID, in_deviceSettings ) \
		AK::Monitor::MonitorStreamingDeviceInit( in_deviceID, in_deviceSettings )

	#define AK_MONITOR_STREAMING_DEVICE_DESTROYED( in_deviceID ) \
		AK::Monitor::MonitorStreamingDeviceDestroyed( in_deviceID )

	#define AK_MONITOR_STREAM_MGR_TERM( ) \
		AK::Monitor::MonitorStreamMgrTerm()
#else
	#define AK_MONITOR_ERROR( in_eErrorCode )
	#define AK_MONITOR_STREAM_MGR_INIT( in_streamMgrSettings )
	#define AK_MONITOR_STREAMING_DEVICE_INIT( in_deviceID, in_deviceSettings )
	#define AK_MONITOR_STREAMING_DEVICE_DESTROYED( in_deviceID )
	#define AK_MONITOR_STREAM_MGR_TERM( )
#endif

#ifdef AK_MONITOR_IMPLEMENT_ERRORCODES
#include <AK/Tools/Common/AkMonitorErrorImpl.h>
#endif // AK_MONITOR_IMPLEMENT_ERRORCODES

#endif // _AKMONITORERROR_H
