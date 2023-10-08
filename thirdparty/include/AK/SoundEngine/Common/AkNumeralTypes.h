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
// AkNumeralTypes.h

/// \file
/// Numeral data type definitions.

#ifndef _AK_NUMERAL_TYPES_H_
#define _AK_NUMERAL_TYPES_H_

#include <stdint.h>

typedef uint8_t		AkUInt8;	///< Unsigned 8-bit integer
typedef uint16_t	AkUInt16;	///< Unsigned 16-bit integer
typedef uint32_t	AkUInt32;	///< Unsigned 32-bit integer
typedef uint64_t	AkUInt64;	///< Unsigned 64-bit integer

typedef int8_t		AkInt8;		///< Signed 8-bit integer
typedef int16_t		AkInt16;	///< Signed 16-bit integer
typedef int32_t		AkInt32;	///< Signed 32-bit integer
typedef int64_t		AkInt64;	///< Signed 64-bit integer

typedef float		AkReal32;	///< 32-bit floating point
typedef double		AkReal64;	///< 64-bit floating point

typedef intptr_t	AkIntPtr;	///< Integer type for pointers
typedef uintptr_t	AkUIntPtr;	///< Integer (unsigned) type for pointers

#endif // _AK_NUMERAL_TYPES_H_
