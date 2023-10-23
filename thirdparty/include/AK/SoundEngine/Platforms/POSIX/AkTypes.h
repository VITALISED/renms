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

// AkTypes.h

/// \file 
/// Data type definitions.

#pragma once

#include <AK/SoundEngine/Common/AkNumeralTypes.h>

#include <sys/types.h>
#include <semaphore.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#if defined(AK_SUPPORT_THREADS)
#include <pthread.h>
#endif

#define AK_RESTRICT		__restrict				///< Refers to the __restrict compilation flag available on some platforms
#define AK_EXPECT_FALSE( _x )	(_x)
#ifndef AkForceInline
#define AkForceInline	inline					///< Force inlining
#endif
#define AkNoInline		__attribute__ ((noinline))			///< Disable inlining

#define AK_SIMD_ALIGNMENT	16					///< Platform-specific alignment requirement for SIMD data
#define AK_ALIGN_SIMD( _declaration_ )	AK_ALIGN( _declaration_, AK_SIMD_ALIGNMENT )	///< Platform-specific alignment requirement for SIMD data
#define AK_BUFFER_ALIGNMENT AK_SIMD_ALIGNMENT

#define AK_ATTR_USED __attribute__ ((used))
#define AK_DLLEXPORT __attribute__ ((visibility("default"))) 
#define AK_DLLIMPORT

typedef char			AkOSChar;				///< Generic character string
typedef AkUInt16		AkUtf16;				///< Type for 2 byte chars. Used for communication
												///< with the authoring tool.

#if defined(AK_SUPPORT_THREADS)
typedef pthread_t		AkThread;				///< Thread handle
typedef pthread_t		AkThreadID;				///< Thread ID
#else
typedef int AkThread;
typedef int AkThreadID;
#endif
typedef void* 			(*AkThreadRoutine)(	void* lpThreadParameter	);	///< Thread routine

#ifndef AK_APPLE
typedef sem_t 			AkEvent;				///< Event handle
typedef sem_t 			AkSemaphore;			///< Semaphore handle
#endif
typedef FILE*			AkFileHandle;			///< File handle

#define AK_UINT_MAX		UINT_MAX

// For strings.
#define AK_MAX_PATH     260						///< Maximum path length.

typedef AkUInt32			AkFourcc;			///< Riff chunk

/// Create Riff chunk
#define AkmmioFOURCC( ch0, ch1, ch2, ch3 )									    \
		( (AkFourcc)(AkUInt8)(ch0) | ( (AkFourcc)(AkUInt8)(ch1) << 8 ) |		\
		( (AkFourcc)(AkUInt8)(ch2) << 16 ) | ( (AkFourcc)(AkUInt8)(ch3) << 24 ) )

#define AK_BANK_PLATFORM_DATA_ALIGNMENT	(16)	///< Required memory alignment for bank loading by memory address (see LoadBank())

/// Format for printing AkOSChar string using OutputDebugMsgV
/// Corresponds to "%ls" if AK_OS_WCHAR, else "%s".
/// \remark Usage: AKPLATFORM::OutputDebugMsgV(AKTEXT("Print this string: " AK_OSCHAR_FMT "\n", msg));
#define AK_OSCHAR_FMT "%s"

#define AKTEXT(x) x
