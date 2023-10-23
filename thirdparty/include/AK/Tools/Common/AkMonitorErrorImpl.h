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

#pragma once

#ifndef _AKMONITORERROR_H
#include <AK/Tools/Common/AkMonitorError.h>
#endif

namespace AK
{
	namespace Monitor
	{
		const MonitorErrorInfo s_aszMonitorErrorInfos[Num_ErrorCodes] =
		{
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NoError"), AKTEXT("No error")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_FileNotFound"), AKTEXT("File %s not found in path(s): %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotOpenFile"), AKTEXT("Cannot open file %s in path(s): %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotStartStreamNoMemory"), AKTEXT("Not enough memory in I/O pool to start stream")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_IODevice"), AKTEXT("Unknown I/O device error")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_IncompatibleIOSettings"), AKTEXT("I/O settings incompatible.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginUnsupportedChannelConfiguration"), AKTEXT("Plug-in unsupported channel configuration: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginMediaUnavailable"), AKTEXT("Plug-in media unavailable: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginInitialisationFailed"), AKTEXT("Plug-in initialization failure: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginProcessingFailed"), AKTEXT("Plug-in execution failure: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginExecutionInvalid"), AKTEXT("Invalid plug-in execution mode: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginAllocationFailed"), AKTEXT("Could not allocate effect: $p")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_VorbisSeekTableRecommended"), AKTEXT("Seek table is not present, or seek table granularity is larger than the maximum decode buffer size. Conversion settings may need to be updated.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_VorbisDecodeError"), AKTEXT("Vorbis decoder failure")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_ATRAC9DecodeFailed"), AKTEXT("ATRAC9 decoding failed")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ATRAC9LoopSectionTooSmall"), AKTEXT("ATRAC9 loop section is too small")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidAudioFileHeader"), AKTEXT("Invalid file header")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioFileHeaderTooLarge"), AKTEXT("File header too large due to markers or envelope.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_LoopTooSmall"), AKTEXT("File or loop region is too small to be played properly")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccurateChannel"), AKTEXT("Transition not sample-accurate due to mixed channel configurations")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccuratePluginMismatch"), AKTEXT("Transition not sample-accurate due to incompatible audio formats")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccurateRejectedByPlugin"), AKTEXT("Transition not sample-accurate due to incompatible encoding parameters")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccurateStarvation"), AKTEXT("Transition not sample-accurate due to source starvation")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccurateCodecError"), AKTEXT("Transition not sample-accurate due to codec internal error")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NothingToPlay"), AKTEXT("Nothing to play in Dynamic Sequence")),
			// Notification meaning the play asked was not done for an out of control reason // For example, if The Element has a missing source file.
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PlayFailed"), AKTEXT("Play Failed")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_StingerCouldNotBeScheduled"), AKTEXT("Stinger could not be scheduled in this segment or was dropped.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TooLongSegmentLookAhead"), AKTEXT("Segment look-ahead plus pre-entry duration is longer than previous segment in sequence")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotScheduleMusicSwitch"), AKTEXT("Cannot schedule music switch transition ($w to $w) in upcoming segments. Using Exit Cue")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TooManySimultaneousMusicSegments"),	AKTEXT("Cannot schedule music segments: Stopping music")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PlaylistStoppedForEditing"), AKTEXT("Music system is stopped because a music playlist is modified")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MusicClipsRescheduledAfterTrackEdit"), AKTEXT("Rescheduling music clips because a track was modified")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotPlaySource_Create"), AKTEXT("Failed creating source")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotPlaySource_VirtualOff"), AKTEXT("Virtual source failed becoming physical")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotPlaySource_TimeSkip"), AKTEXT("Error while computing virtual source elapsed time")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotPlaySource_InconsistentState"), AKTEXT("Inconsistent source status")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MediaNotLoaded"), AKTEXT("Media $m was not loaded for this source")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_VoiceStarving"), AKTEXT("Voice Starvation")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_StreamingSourceStarving"), AKTEXT("Source starvation")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XMADecoderSourceStarving"),	AKTEXT("XMA decoder starvation")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XMADecodingError"),	AKTEXT("XMA decoding error")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidXMAData"), AKTEXT("Invalid XMA data - Make sure data is allocated from APU memory and is aligned to 2K.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginNotRegistered"), AKTEXT("Plug-in not found: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CodecNotRegistered"), AKTEXT("Codec plug-in not registered: $p")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginVersionMismatch"), AKTEXT("Plug-in version doesn't match sound engine version. Please ensure the plug-in is compatible with this version of Wwise. Plug-in name : $p")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_EventIDNotFound"), AKTEXT("Event ID not found")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidGroupID"), AKTEXT("Invalid State Group ID")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SelectedNodeNotAvailable"), AKTEXT("Selected node ($w) not available. Make sure the structure associated to the event is loaded or that the event has been prepared")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SelectedMediaNotAvailable"), AKTEXT("Selected media $m not available")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NoValidSwitch"), AKTEXT("Not a valid Switch value $s in group $s.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_BankLoadFailed"), AKTEXT("Bank Load Failed")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ErrorWhileLoadingBank"), AKTEXT("Error while loading bank")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_InsufficientSpaceToLoadBank"), AKTEXT("Insufficient Space to Load Bank, requires $u bytes.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_LowerEngineCommandListFull"), AKTEXT("Lower engine command list is full")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SeekNoMarker"), AKTEXT("No marker in file; seeking to specified location")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotSeekContinuous"), AKTEXT("Cannot seek in sound that is within a continuous container with special transitions")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SeekAfterEof"), AKTEXT("Seeking after end of file. Playback will stop")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnknownGameObject"), AKTEXT("Unknown/Dead game object ID used in function %s. Make sure the game object is registered before using it and do not use it once it was unregistered.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_GameObjectNeverRegistered"), AKTEXT("Unknown game object ID used in function %s. This ID was not registered with AK::SoundEngine::RegisterGameObj before.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_DeadGameObject"), AKTEXT("Dead game object ID used in function %s. This object was unregistered with AK::SoundEngine::UnregisterGameObj some time prior this call.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_GameObjectIsNotEmitter"), AKTEXT("The game object for an event was not registered as an emitter. Make sure the game object is registered as an emitter before using it to post an event.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_ExternalSourceNotResolved"), AKTEXT("External source missing from PostEvent call")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_FileFormatMismatch"), AKTEXT("Source file is of different format than expected")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CommandQueueFull"), AKTEXT("Audio command queue is full, blocking caller.  Reduce number of calls to sound engine or boost command queue memory.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CommandTooLarge"), AKTEXT("Audio command is too large to fit in the command queue.  Break the command in smaller pieces.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_XMACreateDecoderLimitReached"), AKTEXT("Failed creating XMA decoder: no more XMA voices available")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XMAStreamBufferTooSmall"), AKTEXT("Failed seeking in XMA source: stream buffer is smaller than XMA block size")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_ModulatorScopeError_Inst"), AKTEXT("Triggered a note-scoped or playing-instance-scoped modulator in a global context (such as a bus or bus effect).  Modulator will have global scope.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ModulatorScopeError_Obj"), AKTEXT("Triggered a game-object-scoped modulator in a global context (such as a bus or bus effect).  Modulator will have global scope.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SeekAfterEndOfPlaylist"), AKTEXT("Ignoring seek after end of playlist")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusRequireSeekTable"), AKTEXT("Seek table required to seek in Opus sources. Please update conversion settings.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusDecodeError"), AKTEXT("Opus decoder failure")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SourcePluginNotFound"), AKTEXT("Source plugin not found in currently loaded banks.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_VirtualVoiceLimit"), AKTEXT("Number of Resume and/or Play-From-Beginning virtual voices has reached warning limit (see Project Settings > Log tab). There may be some infinite, leaked voices.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_NotEnoughMemoryToStart"), AKTEXT("Not enough memory to start sound.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnknownOpusError"), AKTEXT("Error while decoding Opus header.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceInitFailure"), AKTEXT("The Output Device specified by AddOutput() or Init() could not be initialized.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceRemoveFailure"), AKTEXT("ReplaceOutput could not properly remove old output device.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceNotFound"), AKTEXT("AkOutputDeviceID not found as an active device in call to function %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceNotValid"), AKTEXT("Device ID not recognized by the platform or is disabled.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SpatialAudio_ListenerAutomationNotSupported"), AKTEXT("Early reflections are not supported on sounds using 3D Position: Listener with Automation. The assigned early reflections bus will be ignored.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MediaDuplicationLength"), AKTEXT("Duplicated media has different length in bank $b. Check previously unloaded bank. Stopping sound.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_HwVoicesSystemInitFailed"), AKTEXT("The hardware-accelerated voice subsystem failed to initialize.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_HwVoicesDecodeBatchFailed"), AKTEXT("Hardware accelerated audio decoding failed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_HwVoiceLimitReached"), AKTEXT("Maximum number of hardware-accelerated voices reached. Voice will not play.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_HwVoiceInitFailed"), AKTEXT("Failed creating hardware-accelerated voice.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusHWCommandFailed"), AKTEXT("Opus HW command failure. Sound will glitch.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_AddOutputListenerIdWithZeroListeners"), AKTEXT("Non-empty array of listeners specified for AddOutput() but uNumListeners is set to zero.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_3DObjectLimitExceeded"), AKTEXT("3D audio object limit exceeded; object %u instigated by voice/bus will be mixed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusHWFatalError"), AKTEXT("Fatal XAPU failure, Opus sounds will glitch while it is being reset.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusHWDecodeUnavailable"), AKTEXT("AkInitSettings::uNumSamplesPerFrame value unsupported by Opus hardware decoder. Supported size: 256, 512 and 1024. Opus will be disabled")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OpusHWTimeout"), AKTEXT("Opus hardware stopped responding ")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SystemAudioObjectsUnavailable"), AKTEXT("Another process is using Microsoft Spatial Sound objects. Some audio objects may be mixed.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_AddOutputNoDistinctListener"), AKTEXT("AddOutput() needs unique Listeners for multi-instance outputs using the same shareset.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginCannotRunOnObjectConfig"), AKTEXT("Plug-in $p does not support Audio Objects bus configuration.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SpatialAudio_ReflectionBusError"), AKTEXT("The playing sound is assigned the same early reflection bus in the Authoring Tool that has been set via AK::SpatialAudio::SetImageSource. Use a unique bus to avoid image source conflicts.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_VorbisHWDecodeUnavailable"), AKTEXT("Vorbis Hardware Acceleration library not found. Source will be decoded in software.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ExternalSourceNoMemorySize"), AKTEXT("No memory size provided in AkExternalSource structure, but data pointer was used. Fill uiMemorySize.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_MonitorQueueFull"), AKTEXT("Monitor queue full. Increase the size of uMonitorQueuePoolSize. Message size %u bytes")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MonitorMsgTooLarge"), AKTEXT("Monitor queue message is too large. Increase the size of uMonitorQueuePoolSize. Message size %u bytes)")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_NonCompliantDeviceMemory"), AKTEXT("Non-compliant device memory detected. Device memory is required for hardware acceleration.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_JobWorkerFuncCallMismatch"), AKTEXT("Job worker function was called more often than it was requested. Check your sound engine integration.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_JobMgrOutOfMemory"), AKTEXT("Job Manager ran out of memory. Significant loss of performance or instability may occur.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidFileSize"), AKTEXT("Invalid file size for: %s at path %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginMsg"), AKTEXT("%s (Plugin: $p)")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SinkOpenSL"), AKTEXT("AkSink, OpenSL Event %s on %s:")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioOutOfRange"), AKTEXT("Wwise audio out of range: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioOutOfRangeOnBus"), AKTEXT("Wwise audio out of range: %s, bus ID $w")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioOutOfRangeOnBusFx"), AKTEXT("Wwise audio out of range : Bus Effect %u, bus ID $w")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioOutOfRangeRay"), AKTEXT("Wwise audio out of range : %s, ray %u")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnknownDialogueEvent"), AKTEXT("Unknown Dialogue Event: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_FailedPostingEvent"), AKTEXT("Failed posting event: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_OutputDeviceInitializationFailed"), AKTEXT("Initialization of output device failed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnloadBankFailed"), AKTEXT("Unload bank failed, requested bank was not found: %s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginFileNotFound"), AKTEXT("Could not find plug-in dynamic library: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginFileIncompatible"), AKTEXT("Incompatible plug-in dynamic library file: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginFileNotEnoughMemoryToStart"), AKTEXT("System ran out of resources while loading plug-in dynamic library: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginFileInvalid"), AKTEXT("Not a plug-in dynamic library: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginFileRegisterFailed"), AKTEXT("Could not register plug-in: %s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnknownArgument"), AKTEXT("Unknown Argument Value name: %s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_DynamicSequenceAlreadyClosed"), AKTEXT("Dynamic Sequence already closed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PendingActionDestroyed"), AKTEXT("Pending action was destroyed because a critical memory allocation failed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CrossFadeTransitionIgnored"), AKTEXT("Cross-Fade transition ignored: Estimated length not available. Make sure sounds with Cross-Fade transitions virtual mode are set to \"Play from elapsed time\" and that only sounds with finite duration are used.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MusicRendererSeekingFailed"), AKTEXT("Music Renderer: Seeking failed. Music will continue from current position.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_DynamicSequenceIdNotFound"), AKTEXT("Dynamic Sequence ID not found: %u")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_BusNotFoundByName"), AKTEXT("Bus %s not found in Init bank.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceShareSetNotFound"), AKTEXT("Audio Device ShareSet not found in Init bank.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioDeviceShareSetNotFoundByName"), AKTEXT("Audio Device ShareSet not found in Init bank: %s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineTooManyGameObjects"), AKTEXT("%s - Too many game objects in array. Count: %u; Limit: %u")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineTooManyPositions"), AKTEXT("%s: too many positions. Count: %u; Limit: %u")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineCantCallOnChildBus"), AKTEXT("Can't call %s on child bus.  Use on Master busses only.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEnginePlayingIdNotFound"), AKTEXT("Playing ID %u not found in function %s.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineInvalidTransform"), AKTEXT("Invalid transform in function %s.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineTooManyEventPosts"), AKTEXT("Too many event posts on event. Function %s; Event $w; Count: %u; Limit: %u")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioSubsystemStoppedResponding"), AKTEXT("Hardware audio subsystem stopped responding.  Silent mode is enabled.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_NotEnoughMemInFunction"), AKTEXT("Not enough memory to complete the operation in %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_FXNotFound"), AKTEXT("Effect Shareset not found in function %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetMixerNotABus"), AKTEXT("SetMixer can only apply to Bus or Aux Bus.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioNodeNotFound"), AKTEXT("Audio node not found in call to %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetMixerFailed"), AKTEXT("SetMixer: Plug-in instanciation failed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetBusConfigUnsupported"), AKTEXT("SetBusConfig cannot modify master bus speaker configuration, it is dictated by the audio hardware.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_BusNotFound"), AKTEXT("%s: Bus not found in Init bank.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_MismatchingMediaSize"), AKTEXT("Mismatching media size error for file $m. Possibly caused by mismatching sound bank or WEM resources. WEM is %u bytes and sound bank expects %u bytes.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_IncompatibleBankVersion"), AKTEXT("Load bank failed : incompatible bank version. Bank was generated with %s version of Wwise. The Bank version is %i and the current runtime SDK version is %i (%s)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_UnexpectedPrepareGameSyncsCall"), AKTEXT("Unexpected call to PrepareGameSyncs. See: \"bEnableGameSyncPreparation\" parameter in AkInitSettings for more information")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MusicEngineNotInitialized"), AKTEXT("Music engine not initialized. Content can not be loaded from bank.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_LoadingBankMismatch"), AKTEXT("Type mismatch while loading bank. Object $w is a %s in the currently loading bank. It was a %s in bank $b")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MasterBusStructureNotLoaded"), AKTEXT("Output bus $w not found. Make sure that the Init bank is loaded first.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TooManyChildren"), AKTEXT("Too many children in one single container. Current count: %u; Limit: %u")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_BankContainUneditableEffect"), AKTEXT("Warning: Bank contains rendered source effects which can't be edited in Wwise")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MemoryAllocationFailed"), AKTEXT("Memory allocation failed: %u bytes in category '%s' - media?: %s - device?: %s - currently allocated %u / %u bytes")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidFloatPriority"), AKTEXT("Invalid floating point value detected: non-finite(or NaN) priority.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundLoadFailedInsufficientMemory"), AKTEXT("Insufficient memory preparing media. Sound will not play.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NXDeviceRegistrationFailed"), AKTEXT("NX audio device notification registration failed, output format changes will not be detected.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MixPluginOnObjectBus"), AKTEXT("Mixer plugins not supported on object busses")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XboxXMAVoiceResetFailed"), AKTEXT("XMA Voice Reset failed, voice may leak.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XboxACPMessage"), AKTEXT("ACP_MESSAGE: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XboxFrameDropped"), AKTEXT("XMA Error, frame dropped. Audible glitch possible.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XboxACPError"), AKTEXT("ACP ERROR: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_XboxXMAFatalError"), AKTEXT("XMA Fatal Error, sound will be terminated.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MissingMusicNodeParent"), AKTEXT("Missing music node parent. Make sure all banks containing music structures are completely loaded.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_HardwareOpusDecoderError"), AKTEXT("Hardware Opus Decoder error: %i. Sound killed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryTooManyTriangleConnected"), AKTEXT("AK::SpatialAudio::SetGeometry - More than two triangles (%i, %i, %i) are connected to the same edge [%i, %i].")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryTriangleTooLarge"), AKTEXT("AK::SpatialAudio::SetGeometry - Triangle %i formed by vertices [%i, %i, %i] is too large.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryFailed"), AKTEXT("AK::SpatialAudio::SetGeometry: error setting geometry (ID=%llu)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_RemovingGeometrySetFailed"), AKTEXT("AK::SpatialAudio::RemoveGeometry: error removing geometry set (ID=%llu)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryInstanceFailed"), AKTEXT("AK::SpatialAudio::SetGeometryInstance: error setting geometry instance (ID=%llu)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_RemovingGeometryInstanceFailed"), AKTEXT("AK::SpatialAudio::RemoveGeometryInstance: error removing geometry instance (ID=%llu)")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_RevertingToDefaultAudioDevice"), AKTEXT("Reverting to default Built-in Audio Device.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_RevertingToDummyAudioDevice"), AKTEXT("Reverting to Dummy Audio Device (no output).")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioThreadSuspended"), AKTEXT("Audio thread suspended. Audio output will be silent.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AudioThreadResumed"), AKTEXT("Audio thread resumed, audio restarts.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ResetPlaylistActionIgnoredGlobalScope"), AKTEXT("Reset playlist action with a game object specific scope is ignored on a global container.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ResetPlaylistActionIgnoredContinuous"), AKTEXT("Reset playlist action on a continuous container is ignored.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_PlayingTriggerRateNotSupported"), AKTEXT("Playing a trigger-rate container as part of a sample-accurate playlist is not supported and will sound out-of-sync.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryTriangleIsSkipped"), AKTEXT("AK::SpatialAudio::SetGeometry - Triangle number %i is skipped because it is invalid; two or more of its vertices are at the same position.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGeometryInstanceInvalidTransform"), AKTEXT("AK::SpatialAudio::SetGeometryInstance - Transform is not valid.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetGameObjectRadiusSizeError"), AKTEXT("AK::SpatialAudio::SetGameObjectRadius: Outer radius must be greater than inner radius.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetPortalNonDistinctRoom"), AKTEXT("AK::SpatialAudio::SetPortal: Portal \"%s\" (ID:%llu) must have a front room which is distinct from its back room.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SetPortalInvalidExtent"), AKTEXT("AK::SpatialAudio::SetPortal: Invalid extent. Extent dimensions must be positive.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SpatialAudio_PortalNotFound"), AKTEXT("Portal %u not found in function %s.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidFloatInFunction"), AKTEXT("Invalid float in parameter %s of function %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_FLTMAXNotSupported"), AKTEXT("%s: FLT_MAX not supported")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotInitializeAmbisonicChannelConfiguration"), AKTEXT("Cannot initialize with ambisonic channel configuration, reverting to standard configuration.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CannotInitializePassthrough"), AKTEXT("Cannot initialize passthrough. Passthrough and objects will be disabled.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_3DAudioUnsupportedSize"), AKTEXT("AkInitSettings::uNumSamplesPerFrame set to a value that is not 256, 512, or 1024. 3D Audio will be disabled.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AmbisonicNotAvailable"), AKTEXT("Ambisonic is only available with 3D audio. 3D audio is not enabled in the audio device shareset, reverting to standard configuration.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_NoAudioDevice"), AKTEXT("No audio device found on system.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_Support"), AKTEXT("Internal error, contact Support with this information: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_ReplayMessage"), AKTEXT("Replay: %s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_GameMessage"), AKTEXT("%s (Game Message)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TestMessage"), AKTEXT("%s")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TranslatorStandardTagTest"), AKTEXT("%i %f %u %s %llu %l %le %lle %y")), //(The l, le, lle tag doesn't exist and serve to check if the llu tags conditions are working)
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TranslatorWwiseTagTest"), AKTEXT("$$w $y $b $g $m $p $w $s $s $w")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_TranslatorStringSizeTest"), AKTEXT("%s%s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_InvalidParameter"), AKTEXT("Invalid parameter %s in function call %s")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_MaxAudioObjExceeded"), AKTEXT("Microsoft Spatial Sound: Too many dynamic objects. Some sounds may not play.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_MMSNotEnabled"), AKTEXT("Microsoft Spatial Sound not enabled by user.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NotEnoughSystemObj"), AKTEXT("System does not meet minimum requirement for System Audio Objects. System Audio Objects will be mixed.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NotEnoughSystemObjWin"), AKTEXT("AkPlatformInitSettings::uMaxSystemAudioObjects (%u) does not meet minimum requirement of %u System Audio Objects. System Audio Objects will be mixed.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_TransitionNotAccurateSourceTooShort"), AKTEXT("Transition not sample-accurate, the new source is shorter than two audio frames. Use a software codec to support this case.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_AlreadyInitialized"), AKTEXT("Sound Engine was already initialized. New settings ignored.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_WrongNumberOfArguments"), AKTEXT("Wrong number of Arguments for Dialogue Event argument list in function: %s. Expected %i, got %i.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_DataAlignement"), AKTEXT("Bank or Media pointer not aligned to %i bytes.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_PluginMsgWithShareSet"), AKTEXT("%s (Plugin: $p Shareset: $w)")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SoundEngineNotInit"), AKTEXT("SoundEngine is not initalized yet or Init bank has not been loaded. Function: %s.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NoDefaultSwitch"), AKTEXT("No default Switch value selected in group $s.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_CantSetBoundSwitch"), AKTEXT("Switch $s is bound to RTPC $w. It can not be set directly.")),

			ERROR_CODE_DEF(AKTEXT("ErrorCode_IODeviceInitFailed"), AKTEXT("I/O Device initialization failed. Streaming from file will not be possible.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_SwitchListEmpty"), AKTEXT("Switch Group $s has no Switch Values. Switch container will do nothing.")),
			ERROR_CODE_DEF(AKTEXT("ErrorCode_NoSwitchSelected"), AKTEXT("No Switch Group selected for this Switch container.")),
		};

		static_assert((sizeof(s_aszMonitorErrorInfos) / sizeof(s_aszMonitorErrorInfos[0])) == AK::Monitor::Num_ErrorCodes, "ARRAYSIZE(AK::Monitor::s_aszMonitorErrorInfos) is not matching AK::Monitor::Num_ErrorCodes, make sure they are maintained at the same time.");
	}

}
