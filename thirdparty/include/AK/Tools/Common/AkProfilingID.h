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

#include <AK/SoundEngine/Common/AkCommonDefs.h>

namespace AK
{
	namespace ProfilingID
	{
		enum ProfilingID
		{
			AudioFrameBoundary = 1,
			AudioVoiceStarvation,
			CAkLEngine_AnalyzeMixingGraph,
			CAkLEngine_PreprocessSources,
			CAkLEngine_VoiceTask,
			CAkLEngine_VoiceTaskParallelAsync,
			AkPerf_PostPipelineStats,
			CommunicationCentral_Process,
			JobMgr_WorkerFunction,
			SwVoice,
			HwVoice,
			SpatialAudio_Update,
			SpatialAudio_Dispatch,
			SpatialAudio_End,
			SpatialAudio_EmitterToListener,
			SpatialAudio_ListenerRayCasting,
			SpatialAudio_ListenerToPortal,
			SpatialAudio_EmitterToPortal,
			SpatialAudio_PortalToPortal,
			SpatialAudio_PortalRayCasting,
			CAkEdgePathSearch_Search,
			CAkStochasticReflectionEngine_ComputeRays,
			CAkStochasticReflectionEngine_TraceDiffractionRay,
			CAkStochasticReflectionEngine_TraceReflectionRay,
			CAkStochasticReflectionEngine_ValidateExistingPaths,
			CAkStochasticReflectionEngine_ValidatePaths,
			AkAcousticRoom_PropagateSound,
			AkSoundGeometry_SetGeometry,
			AkSoundGeometry_SetGeometryInstance,

			Num // Keep last!
		};

		enum MetaID
		{
			PipelineID = Num // Avoid ID space clash
		};

#ifdef AK_IMPLEMENT_PROFILINGID_NAMES
		const char* s_aszNames[] =
		{
			"AK INVALID PROFILEID", // should never be used; 0 means no relevant profile id was provided
			"AK Audio Frame Boundary",
			"AK Audio Voice Starvation",
			"CAkLEngine::AnalyzeMixingGraph",
			"CAkLEngine::PreprocessSources",
			"CAkLEngine::VoiceTask",
			"CAkLEngine::VoiceTaskParallelAsync",
			"AkPerf::PostPipelineStats",
			"AK::CommunicationCentral::Process",
			"AkJobMgr::WorkerFunction",
			"AK SwVoice",
			"AK HwVoice",
			"AK::SpatialAudio::Update",
			"AK::SpatialAudio::Dispatch",
			"AK::SpatialAudio::End",
			"AK::SpatialAudio::EmitterToListener",
			"AK::SpatialAudio::ListenerRayCasting",
			"AK::SpatialAudio::ListenerToPortal",
			"AK::SpatialAudio::EmitterToPortal",
			"AK::SpatialAudio::PortalToPortal",
			"AK::SpatialAudio::PortalRayCasting",
			"CAkEdgePathSearch::Search",
			"CAkStochasticReflectionEngine::ComputeRays",
			"CAkStochasticReflectionEngine::TraceDiffractionRay",
			"CAkStochasticReflectionEngine::TraceReflectionRay",
			"CAkStochasticReflectionEngine::ValidateExistingPaths",
			"CAkStochasticReflectionEngine::ValidatePaths",
			"AkAcousticRoom::PropagateSound",
			"AkSoundGeometry::SetGeometry",
			"AkSoundGeometry::SetGeometryInstance"
		};

		static_assert((sizeof(s_aszNames) / sizeof(s_aszNames[0])) == AK::ProfilingID::Num, "ARRAYSIZE(AK::ProfilingID::s_aszNames) is not matching AK::ProfilingID::Num, make sure they are maintained at the same time.");
#endif
	}
}

#define AKMAKECLASSIDFORPROFILING( _profilingid_ ) AKMAKECLASSID( AkPluginTypeNone, AKCOMPANYID_AUDIOKINETIC, _profilingid_ )
