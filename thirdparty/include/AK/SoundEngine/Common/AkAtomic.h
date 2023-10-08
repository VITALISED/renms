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

// AkAtomic.h

#pragma once

#if defined( _MSC_VER )
	#include <AK/SoundEngine/Platforms/Windows/AkAtomic.h>
#elif defined( __EMSCRIPTEN__ )
	#include <AK/SoundEngine/Platforms/Emscripten/AkAtomic.h>
#elif defined(NN_NINTENDO_SDK)
	#include <AK/SoundEngine/Platforms/NX/AkAtomic.h>
#elif defined(AK_PS4)
	#include <AK/SoundEngine/Platforms/PS4/AkAtomic.h>
#elif defined(AK_PS5)
	#include <AK/SoundEngine/Platforms/PS5/AkAtomic.h>
#else
	#include <AK/SoundEngine/Platforms/Linux/AkAtomic.h>
#endif

