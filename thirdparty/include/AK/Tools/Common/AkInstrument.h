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
#include <AK/Tools/Common/AkAssert.h>

namespace AK
{
	namespace Instrument
	{
#ifndef AK_OPTIMIZED
		AK_CALLBACK(void*, PushTimerFunc)(
			AkPluginID in_uPluginID,
			const char * in_pszZoneName
			);

		AK_CALLBACK(void, PopTimerFunc)(void* in_pToken);

		AK_CALLBACK(void, PostMarkerFunc)(
			AkPluginID in_uPluginID,
			const char* in_pszMarkerName
			);

		AK_CALLBACK(void, PostMetaMarkerFunc)(
			AkPluginID in_uPluginID,
			AkUInt32 in_uMetadata
			);

		extern AKSOUNDENGINE_API PushTimerFunc g_fnPushTimer;
		extern AKSOUNDENGINE_API PopTimerFunc g_fnPopTimer;
		extern AKSOUNDENGINE_API PostMarkerFunc g_fnPostMarker;
		extern AKSOUNDENGINE_API PostMetaMarkerFunc g_fnPostMetaMarker;

		class Scope
		{
		public:
			inline Scope(AkPluginID in_uPluginID, const char* in_pszZoneName)
			{
				m_pToken = g_fnPushTimer(in_uPluginID, in_pszZoneName);
			}

			inline ~Scope()
			{
				g_fnPopTimer(m_pToken);
			}
		private:
			void* m_pToken;
		};

#endif
	}
}

#if !defined(AK_OPTIMIZED)

#define AK_INSTRUMENT_BEGIN(_plugin_id_, _zone_name_) (AK::Instrument::g_fnPushTimer(_plugin_id_, _zone_name_))
#define AK_INSTRUMENT_END(__token__) (AK::Instrument::g_fnPopTimer(__token__))
#define AK_INSTRUMENT_MARKER(_plugin_id_, _marker_name_) (AK::Instrument::g_fnPostMarker(_plugin_id_, _marker_name_))
#define AK_INSTRUMENT_MARKER_PROFILINGID(_profilingid_) (AK::Instrument::g_fnPostMarker(AKMAKECLASSID( AkPluginTypeNone, AKCOMPANYID_AUDIOKINETIC, _profilingid_ ), nullptr))
#define AK_INSTRUMENT_METAMARKER(_plugin_id_, _metadata_) (AK::Instrument::g_fnPostMetaMarker(_plugin_id_, _metadata_))

#define AK_INSTRUMENT_CONCAT_INNER(_base_, _counter_) _base_ ## _counter_
#define AK_INSTRUMENT_CONCAT(_base_, _counter_) AK_INSTRUMENT_CONCAT_INNER(_base_, _counter_)

#define AK_INSTRUMENT_SCOPE(_zone_name_) \
	AK::Instrument::Scope AK_INSTRUMENT_CONCAT(_akInstrumentScope_, __LINE__)(0, _zone_name_)

#define AK_INSTRUMENT_SCOPE_ID(_plugin_id_, _zone_name_) \
	AK::Instrument::Scope AK_INSTRUMENT_CONCAT(_akInstrumentScope_, __LINE__)(_plugin_id_, _zone_name_)

#define AK_INSTRUMENT_SCOPE_PROFILINGID(_profilingid_) \
	AK::Instrument::Scope AK_INSTRUMENT_CONCAT(_akInstrumentScope_, __LINE__)(AKMAKECLASSID( AkPluginTypeNone, AKCOMPANYID_AUDIOKINETIC, _profilingid_ ), nullptr)

#define AK_INSTRUMENT_THREAD_START( _thread_name_ )
	
#else // AK_OPTIMIZED

#define AK_INSTRUMENT_BEGIN(_plugin_id_, _zone_name_) (void*)( 0 )
#define AK_INSTRUMENT_END(__token__) 
#define AK_INSTRUMENT_MARKER(_plugin_id_, _zone_name_)
#define AK_INSTRUMENT_MARKER_PROFILINGID(_profilingid_)
#define AK_INSTRUMENT_METAMARKER(_plugin_id_, _metadata_)
#define AK_INSTRUMENT_SCOPE( _zone_name_ )
#define AK_INSTRUMENT_SCOPE_ID(_plugin_id_, _zone_name_)
#define AK_INSTRUMENT_SCOPE_PROFILINGID(_plugin_id_)

#define AK_INSTRUMENT_THREAD_START( _thread_name_ )

#endif // AK_OPTIMIZED

#ifndef AK_INSTRUMENT_BEGIN_C
	#define AK_INSTRUMENT_BEGIN_C(_plugin_id_, _color_, _zone_name_) AK_INSTRUMENT_BEGIN(_plugin_id_, _zone_name_)
#endif
