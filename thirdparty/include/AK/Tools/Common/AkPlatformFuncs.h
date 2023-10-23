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

// AkPlatformFuncs.h

/// \file 
/// Platform-dependent functions definition.

#ifndef _AK_TOOLS_COMMON_AKPLATFORMFUNCS_H
#define _AK_TOOLS_COMMON_AKPLATFORMFUNCS_H

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/SoundEngine/Common/AkAtomic.h>

// Uncomment the following to enable built-in platform profiler markers in the sound engine
//#define AK_ENABLE_INSTRUMENT

#if defined(AK_WIN)
#include <AK/Tools/Win32/AkPlatformFuncs.h>

#elif defined (AK_XBOX)
#include <AK/Tools/XboxOne/AkPlatformFuncs.h>

#elif defined (AK_APPLE)
#include <AK/Tools/Mac/AkPlatformFuncs.h>
#include <AK/Tools/POSIX/AkPlatformFuncs.h>

#elif defined( AK_ANDROID ) || defined ( AK_LINUX_AOSP ) 
#include <AK/Tools/Android/AkPlatformFuncs.h>

#elif defined (AK_PS4)
#include <AK/Tools/PS4/AkPlatformFuncs.h>

#elif defined (AK_PS5)
#include <AK/Tools/PS5/AkPlatformFuncs.h>

#elif defined (AK_EMSCRIPTEN)
#include <AK/Tools/Emscripten/AkPlatformFuncs.h>

#elif defined (AK_LINUX)

#ifdef AK_GGP
#include <AK/Tools/GGP/AkPlatformFuncs.h>
#endif
#include <AK/Tools/Linux/AkPlatformFuncs.h>
#include <AK/Tools/POSIX/AkPlatformFuncs.h>

#elif defined (AK_QNX)
#include <AK/Tools/QNX/AkPlatformFuncs.h>
#include <AK/Tools/POSIX/AkPlatformFuncs.h>

#elif defined (AK_NX)
#include <AK/Tools/NX/AkPlatformFuncs.h>

#else
#error AkPlatformFuncs.h: Undefined platform
#endif

#ifndef AkPrefetchZero
#define AkPrefetchZero(___Dest, ___Size)
#endif

#ifndef AkPrefetchZeroAligned
#define AkPrefetchZeroAligned(___Dest, ___Size)
#endif

#ifndef AkZeroMemAligned
#define AkZeroMemAligned(___Dest, ___Size) AKPLATFORM::AkMemSet(___Dest, 0, ___Size);
#endif
#ifndef AkZeroMemLarge
#define AkZeroMemLarge(___Dest, ___Size) AKPLATFORM::AkMemSet(___Dest, 0, ___Size);
#endif
#ifndef AkZeroMemSmall
#define AkZeroMemSmall(___Dest, ___Size) AKPLATFORM::AkMemSet(___Dest, 0, ___Size);
#endif

#ifndef AkAllocaSIMD
#ifdef __clang__
#if __has_builtin( __builtin_alloca_with_align )
#define AkAllocaSIMD( _size_ ) __builtin_alloca_with_align( _size_, 128 )
#else
// work around alloca alignment issues in versions of clang before 4.0
#define AkAllocaSIMD( _size_ ) (void*)( ( ( uintptr_t )AkAlloca( _size_ + 16 ) + 0xF ) & ~0xF )
#endif
#else
#define AkAllocaSIMD( _size_ ) AkAlloca( _size_ )
#endif
#endif

#ifndef AK_THREAD_INIT_CODE
#define AK_THREAD_INIT_CODE(_threadProperties)
#endif

/// Utility functions
namespace AK
{
	/// Count non-zero bits.
	/// \return Number of channels.
	AkForceInline AkUInt32 GetNumNonZeroBits( AkUInt32 in_uWord )
	{
		AkUInt32 num = 0;
		while( in_uWord ){ ++num; in_uWord &= in_uWord-1; }
		return num;
	}

	/// Computes the next power of two given a value.
	/// \return next power of two.
	AkForceInline AkUInt32 GetNextPowerOfTwo( AkUInt32 in_uValue )
	{
		in_uValue--;
		in_uValue |= in_uValue >> 1;
		in_uValue |= in_uValue >> 2;
		in_uValue |= in_uValue >> 4;
		in_uValue |= in_uValue >> 8;
		in_uValue |= in_uValue >> 16;
		in_uValue++;
		return in_uValue;
	}

	AkForceInline AkUInt32 ROTL32( AkUInt32 x, AkUInt32 r )
	{
		return ( x << r ) | ( x >> ( 32 - r ) );
	}

	AkForceInline AkUInt64 ROTL64( AkUInt64 x, AkUInt64 r )
	{
		return ( x << r ) | ( x >> ( 64 - r ) );
	}
}

/// Platform-dependent helpers
namespace AKPLATFORM
{
	inline void AkGetDefaultHighPriorityThreadProperties(AkThreadProperties& out_threadProperties)
	{
		AkGetDefaultThreadProperties(out_threadProperties);
		out_threadProperties.nPriority = AK_THREAD_PRIORITY_ABOVE_NORMAL;
	}


#if defined _MSC_VER && defined AK_CPU_X86_64
	AkForceInline AkUInt32 AkBitScanForward64(unsigned long long in_bits)
	{
		unsigned long ret = 0;
		_BitScanForward64(&ret, in_bits);
		return ret;
	}
#elif __clang__ || defined __GNUG__
	AkForceInline AkUInt32 AkBitScanForward64(AkUInt64 in_bits)
	{
		return __builtin_ctzll(in_bits);
	}
#else
	AkForceInline AkUInt32 AkBitScanForward64(unsigned long long in_bits)
	{
		unsigned long ret = 0;
		if (in_bits)
		{
			while ((in_bits & 1ULL) == 0)
			{
				in_bits >>= 1;
				ret++;
			}
		}
		return ret;
	}
#endif

#if defined _MSC_VER
	AkForceInline AkUInt32 AkBitScanForward(unsigned long in_bits)
	{
		unsigned long ret = 0;
		_BitScanForward(&ret, in_bits);
		return ret;
	}

#elif __clang__ || defined __GNUG__
	AkForceInline AkUInt32 AkBitScanForward(AkUInt32 in_bits)
	{
		return __builtin_ctzl(in_bits);
	}
#else
	AkForceInline AkUInt32 AkBitScanForward(unsigned long in_bits)
	{
		unsigned long ret = 0;
		if (in_bits)
		{
			while ((in_bits & 1ULL) == 0)
			{
				in_bits >>= 1;
				ret++;
			}
		}
		return ret;
	}
#endif

	// fallback implementation for when platform doesn't have its own implementation
#if !defined(AK_LIMITEDSPINFORZERO)
	// Waits for a limited amount of time for in_pVal to hit zero (without yielding the thread)
	inline void AkLimitedSpinForZero(AkAtomic32* in_pVal)
	{
		AkInt64 endSpinTime = 0;
		AkInt64 currentTime = 0;
		PerformanceCounter(&endSpinTime);
		endSpinTime += AkInt64(AK::g_fFreqRatio * 0.01); // only spin for about 10us
		while (true)
		{
			// if pval is zero, skip out
			if (AkAtomicLoad32(in_pVal) == 0)
			{
				break;
			}
			AkSpinHint();

			// Check if we've hit the deadline for the timeout
			PerformanceCounter(&currentTime);
			if (currentTime > endSpinTime)
			{
				break;
			}
		}
	}
#endif

	inline void AkSpinWaitForZero(AkAtomic32* in_pVal)
	{
		// do a limited spin on-the-spot until in_pVal hits zero
		AkLimitedSpinForZero(in_pVal);

		// if in_pVal is still non-zero, then the other thread is either blocked or waiting for us.  Yield for real.
		while (AkAtomicLoad32(in_pVal))
			AkThreadYield();
	}
}

#ifndef AK_PERF_RECORDING_RESET
#define AK_PERF_RECORDING_RESET()
#endif
#ifndef AK_PERF_RECORDING_START
#define AK_PERF_RECORDING_START( __StorageName__, __uExecutionCountStart__, __uExecutionCountStop__ )
#endif
#ifndef AK_PERF_RECORDING_STOP
#define AK_PERF_RECORDING_STOP( __StorageName__, __uExecutionCountStart__, __uExecutionCountStop__ )	
#endif

#endif // _AK_TOOLS_COMMON_AKPLATFORMFUNCS_H
