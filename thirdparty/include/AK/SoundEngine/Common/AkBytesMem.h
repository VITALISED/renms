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

// AkBytesMem.h

/// \file 
/// IReadBytes / IWriteBytes implementation on a growing memory buffer. This
/// version uses the AK::MemoryMgr allocator.

#pragma once

#include <AK/IBytes.h>
#include <AK/SoundEngine/Common/AkSoundEngineExport.h>
#include <AK/Tools/Common/AkBankReadHelpers.h>

namespace AK
{
	class ReadBytesMem
		: public AK::IReadBytes
	{
	public:

		AKSOUNDENGINE_API ReadBytesMem();
		AKSOUNDENGINE_API ReadBytesMem(
			const void * in_pBytes, 
			AkInt32 in_cBytes
			);
		AKSOUNDENGINE_API virtual ~ReadBytesMem();

		// IReadBytes implementation

		AKSOUNDENGINE_API virtual bool ReadBytes(
			void * in_pData, 
			AkInt32 in_cBytes, 
			AkInt32 & out_cRead
			);

		// Public methods

		AKSOUNDENGINE_API void Attach(
			const void * in_pBytes, 
			AkInt32 in_cBytes
			);

	private:
		AkInt32   m_cBytes;
		const AkUInt8 * m_pBytes;

		AkInt32   m_cPos;
	};

	class WriteBytesMem
		: public AK::IWriteBuffer
	{
	public:
	
		AKSOUNDENGINE_API WriteBytesMem();
		AKSOUNDENGINE_API virtual ~WriteBytesMem();
	
		// IWriteBytes implementation

		AKSOUNDENGINE_API virtual bool WriteBytes(
			const void * in_pData, 
			AkInt32 in_cBytes, 
			AkInt32& out_cWritten);
	
		// IWriteBuffer implementation

		AKSOUNDENGINE_API virtual bool Reserve(
			AkInt32 in_cBytes
			);

		AKSOUNDENGINE_API virtual AkInt32 Count() const;

		AKSOUNDENGINE_API virtual void SetCount(
			AkInt32 in_cBytes
			);

		AKSOUNDENGINE_API AkInt32 Size() const;

		AKSOUNDENGINE_API virtual AkUInt8 * Bytes() const;

		AKSOUNDENGINE_API virtual AkUInt8 * Detach();
	
		AKSOUNDENGINE_API virtual void Clear();
	
		// Public methods

		AKSOUNDENGINE_API void SetMemPool( AkMemPoolId in_pool );

		AKSOUNDENGINE_API bool HasValidMemPool();

		// Reserves space for writing in_cBytes and returns the location, advancing the write pointer.
		AkUInt8* GetWritePtr(AkInt32 in_cBytes)
		{
			AkInt32 cPos = m_cPos;
			AkInt32 cNewPos = cPos + in_cBytes;

			if ((m_cBytes >= cNewPos) || Grow(cNewPos))
			{
				m_cPos = cNewPos;
				return m_pBytes + cPos;
			}
			else
				return nullptr;
		}

		template<class T>
		T* GetWritePtr()
		{
			static_assert(alignof(T) == 1, "T must have an alignment of 1 to avoid crashes due to unaligned writes on 32-bit ARM targets. Use Write<T> instead.");
			return reinterpret_cast<T*>(GetWritePtr(sizeof(T)));
		}

		template<class T>
		bool Write(const T & in_data)
		{
			if (AkUInt8* pWrite = GetWritePtr(sizeof(T)))
			{
				AK::WriteUnaligned<T>(pWrite, in_data);
				return true;
			}
			else
				return false;
		}
	
	private:
		bool Grow(
			AkInt32 in_cBytes
		);

		AkInt32		m_cBytes;
		AkUInt8 *	m_pBytes;
	
		AkInt32	m_cPos;
	
		AkMemPoolId m_pool;
	};

	class WriteBytesBuffer
		: public AK::IWriteBytes
	{
	public:

		AKSOUNDENGINE_API WriteBytesBuffer();

		AKSOUNDENGINE_API virtual ~WriteBytesBuffer();

		AKSOUNDENGINE_API void SetBuffer(AkUInt8* in_pBytes, AkInt32 in_cSize);

		// IWriteBytes implementation

		AKSOUNDENGINE_API virtual bool WriteBytes(
			const void* in_pData,
			AkInt32 in_cBytes,
			AkInt32& out_cWritten);
		
		AKSOUNDENGINE_API AkInt32 GetPos() const;

		AKSOUNDENGINE_API void Clear();

	private:

		AkUInt8* m_pBytes;
		AkInt32 m_cSize;
		AkInt32	m_cPos;
	};
}
