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

// AkSimd.h

/// \file 
/// AKSIMD - Windows implementation

#pragma once

#if defined AK_CPU_X86 || defined AK_CPU_X86_64
		#include <AK/SoundEngine/Platforms/SSE/AkSimd.h>
#endif

#if defined AK_CPU_ARM_NEON
		#define AKSIMD_DECLARE_V4F32_TYPE							DirectX::XMVECTORF32
	#define AKSIMD_DECLARE_V4F32( _x, _a, _b, _c, _d )			AKSIMD_DECLARE_V4F32_TYPE _x = { _a, _b, _c, _d }

	#define AKSIMD_DECLARE_V4I32_TYPE							DirectX::XMVECTORI32
	#define AKSIMD_DECLARE_V4I32( _x, _a, _b, _c, _d )			AKSIMD_DECLARE_V4I32_TYPE _x = { _a, _b, _c, _d }

	#include <DirectXMath.h>
	#include <AK/SoundEngine/Platforms/arm_neon/AkSimd.h>
#endif
