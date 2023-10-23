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

/// \file 
/// Basic definitions for WAV / WEM file parsers.

#include <AK/SoundEngine/Common/AkSpeakerConfig.h>
#include <AK/SoundEngine/Common/AkTypes.h>

//-----------------------------------------------------------------------------
// Constants.
//-----------------------------------------------------------------------------

// Standard IDs
constexpr AkFourcc RIFXChunkId = AkmmioFOURCC('R', 'I', 'F', 'X');
constexpr AkFourcc RIFFChunkId = AkmmioFOURCC('R', 'I', 'F', 'F');
constexpr AkFourcc WAVEChunkId = AkmmioFOURCC('W', 'A', 'V', 'E');
constexpr AkFourcc OGGSChunkId = AkmmioFOURCC('O', 'g', 'g', 'S');
constexpr AkFourcc fmtChunkId  = AkmmioFOURCC('f', 'm', 't', ' ');
constexpr AkFourcc dataChunkId = AkmmioFOURCC('d', 'a', 't', 'a');
constexpr AkFourcc cueChunkId  = AkmmioFOURCC('c', 'u', 'e', ' ');
constexpr AkFourcc LISTChunkId = AkmmioFOURCC('L', 'I', 'S', 'T');
constexpr AkFourcc adtlChunkId = AkmmioFOURCC('a', 'd', 't', 'l');
constexpr AkFourcc lablChunkId = AkmmioFOURCC('l', 'a', 'b', 'l');
constexpr AkFourcc smplChunkId = AkmmioFOURCC('s', 'm', 'p', 'l');
constexpr AkFourcc junkChunkId = AkmmioFOURCC('j', 'u', 'n', 'k');

// AK-specific IDs
constexpr AkFourcc akdChunkId  = AkmmioFOURCC('a', 'k', 'd', ' ');
constexpr AkFourcc hashChunkId = AkmmioFOURCC('h', 'a', 's', 'h');
constexpr AkFourcc seekChunkId = AkmmioFOURCC('s', 'e', 'e', 'k');
constexpr AkFourcc irmdChunkId = AkmmioFOURCC('i', 'r', 'm', 'd');

//-----------------------------------------------------------------------------
// Structs.
//-----------------------------------------------------------------------------

#pragma pack(push, 1)

/// Standard WAV chunk header
struct AkChunkHeader
{
	AkFourcc	ChunkId;
	AkUInt32	dwChunkSize;
};

/// Standard WAV format header
struct WaveFormatEx
{	
	AkUInt16  	wFormatTag;
	AkUInt16  	nChannels;
	AkUInt32  	nSamplesPerSec;
	AkUInt32  	nAvgBytesPerSec;
	AkUInt16  	nBlockAlign;
	AkUInt16  	wBitsPerSample;
	AkUInt16    cbSize;	// size of extra chunk of data, after end of this struct
};

/// WEM format header: equivalent to WAVEFORMATEXTENSIBLE, with an AkChannelConfig
/// instead of dwChannelMask+SubFormat. Codecs that require format-specific chunks 
/// should extend this structure.
struct WaveFormatExtensible : public WaveFormatEx
{
	AkUInt16    wSamplesPerBlock;
	AkUInt32    uChannelConfig;		// Serialized AkChannelConfig

	inline AkChannelConfig GetChannelConfig() const
	{
		AkChannelConfig channelConfig;
		channelConfig.Deserialize(uChannelConfig);
		return channelConfig;
	}
};
static_assert(sizeof(WaveFormatExtensible) == 24, "Incorrect padding for WaveFormatExtensible");

#pragma pack(pop)
