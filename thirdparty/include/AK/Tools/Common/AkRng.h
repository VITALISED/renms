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

#include <AK/SoundEngine/Common/AkTypes.h>

/// A pseudorandom number generator appropriate for introducing randomness in DSP processing
/// LCG with Newlib/Musl characteristics: 64-bit seed, 31-bit output (see http://en.wikipedia.org/wiki/Linear_congruential_generator)
/// Warning: This RNG is not cryptographically secure! Do not use it as such!
class CAkRng
{
public:
	static constexpr AkUInt64 RANDOM_A = 6364136223846793005ULL;
	static constexpr AkUInt64 RANDOM_C = 1;
	static constexpr AkUInt32 RANDOM_MAX = 0x7FFFFFFF; // 31 bits

	/// Initialize using the specified seed
	CAkRng(AkUInt64 uSeed)
		: m_uSeed(uSeed)
	{}

	/// Returns the current seed value of the RNG
	inline AkUInt64 Seed() const
	{
		return m_uSeed;
	}

	/// Returns the next random number to be generated without advancing the RNG state
	inline AkUInt32 Peek() const
	{
		return Peek(m_uSeed);
	}

	/// Returns a random 31-bit unsigned integer
	inline AkUInt32 Random()
	{
		return Random(m_uSeed);
	}

	/// Returns a random 31-bit integer
	inline AkInt32 RandomInt()
	{
		return RandomInt(m_uSeed);
	}

	/// Returns a random float from 0.0 to 1.0
	AkReal32 RandomFloat()
	{
		return (AkReal32)Random(m_uSeed) / (AkReal32)RANDOM_MAX;
	}

	/// Returns a random 31-bit unsigned integer using provided seed
	static inline AkInt32 Random(AkUInt64 &io_uSeed)
	{
		io_uSeed = io_uSeed * RANDOM_A + RANDOM_C;
		return Peek(io_uSeed);
	}

	/// Returns a random 31-bit integer using provided seed
	static inline AkInt32 RandomInt(AkUInt64 &io_uSeed)
	{
		io_uSeed = io_uSeed * RANDOM_A + RANDOM_C;
		return (AkInt32)Peek(io_uSeed);
	}

	/// Returns the next random number to be generated without advancing the RNG state
	static inline AkUInt32 Peek(AkUInt64 in_uSeed)
	{
		return (AkUInt32)(in_uSeed >> 33);
	}

private:
	AkUInt64 m_uSeed;
};
