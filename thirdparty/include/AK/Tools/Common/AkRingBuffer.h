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
#include <AK/Tools/Common/AkObject.h>
#include <AK/Tools/Common/AkPlatformFuncs.h>

template <AkMemID T_MEMID>
struct AkRingBufferAllocatorNoAlign
{
	static AkForceInline void* Alloc(size_t in_uSize)
	{
		return AkAlloc(T_MEMID, in_uSize);
	}

	static AkForceInline void Free(void * in_pAddress)
	{
		AkFree(T_MEMID, in_pAddress);
	}
};

template <AkMemID T_MEMID>
struct AkRingBufferAllocatorAligned
{
	static AkForceInline void* Alloc(size_t in_uSize)
	{
		return AkMalign(T_MEMID, in_uSize, AK_SIMD_ALIGNMENT);
	}

	static AkForceInline void Free(void * in_pAddress)
	{
		AkFree(T_MEMID, in_pAddress);
	}
};

typedef AkRingBufferAllocatorNoAlign<AkMemID_Object> AkRingBufferAllocatorDefault;
typedef AkRingBufferAllocatorNoAlign<AkMemID_Processing> AkRingBufferAllocatorLEngine;
typedef AkRingBufferAllocatorAligned<AkMemID_Processing> AkRingBufferAllocatorLEngineAligned;

template <class T, class TAlloc = AkRingBufferAllocatorDefault>

//Single producer, single consumer pattern implementation.
class AkRingBuffer
{
public:
    AkRingBuffer()
        : m_nbItems(0)
        , m_readIndex(0)
        , m_writeIndex(0)
        , m_nbReadableItems(0)
    {
    }

    AKRESULT Init(AkUInt32 nbItems)
    {
        m_nbItems = nbItems;
        m_readIndex = 0;
        m_writeIndex = 0;
        m_nbReadableItems = 0;

        m_data = reinterpret_cast<T*>(TAlloc::Alloc(m_nbItems * sizeof(T)));
        if (m_data == NULL)
        {
            return AK_InsufficientMemory;
        }
        return AK_Success;
    }

    void Term()
    {
        m_nbItems = 0;
        m_readIndex = 0;
        m_writeIndex = 0;
        m_nbReadableItems = 0;
        
        if (m_data != NULL)
        {
            TAlloc::Free(reinterpret_cast<void*>(m_data));
            m_data = NULL;
        }
    }

    // Reset ringbuffer to initial state without freeing memory. Not thread-safe.
    void Reset()
    {
        m_readIndex = 0;
        m_writeIndex = 0;
        m_nbReadableItems = 0;
    }

    // ---- Producer ---- //

    AkUInt32 GetWriteIndex() const
    {
        return m_writeIndex;
    }
    
    T* GetWritePtr()
    {
        return &m_data[m_writeIndex];
    }

    void IncrementWriteIndex(AkUInt32 nbItems)
    {
        AKASSERT(GetNbWritableItems() >= nbItems);

        m_writeIndex = (m_writeIndex + nbItems) % m_nbItems;

        AkAtomicAdd32(&m_nbReadableItems, nbItems);
    }

    // ---- Consumer ----

    AkUInt32 GetReadIndex() const
    {
        return m_readIndex;
    }

    const T* GetReadPtr() const
    {
        return &m_data[m_readIndex];
    }

    // Peek at any item between the read and write pointer without advancing the read pointer.
    const T* Peek(AkUInt32 uOffset) const
    {
        AKASSERT((AkUInt32)m_nbReadableItems > uOffset);
        AkUInt32 uReadIndex = (m_readIndex + uOffset) % m_nbItems;
        return &m_data[uReadIndex];
    }

    void IncrementReadIndex(AkUInt32 nbItems)
    {
        AKASSERT((AkUInt32)m_nbReadableItems >= nbItems);
        
        m_readIndex = (m_readIndex + nbItems) % m_nbItems;

        AkAtomicSub32(&m_nbReadableItems, nbItems);
    }

    AkUInt32 GetNbReadableItems() const
    {
        return m_nbReadableItems;
    }

    AkUInt32 GetNbWritableItems() const
    {
        return m_nbItems - (AkUInt32)m_nbReadableItems;
    }

    AkUInt32 Size() const
    {
        return m_nbItems;
    }

    // Warning: requires external locking to prevent concurrent Grow+Read in a multi-threaded scenario. 
    // Like the rest of the class, assumes a single writing thread.
    bool Grow(AkUInt32 in_uGrowBy)
    {
        AkUInt32 uTargetItems = m_nbItems + in_uGrowBy;
        if (T* pNewData = reinterpret_cast<T*>(TAlloc::Alloc(uTargetItems * sizeof(T))))
        {
            if (m_nbReadableItems)
            {
                if (m_readIndex >= m_writeIndex)
                {
                    // insert new free space in the middle of the buffer.

                    if (m_writeIndex)
                        memcpy(pNewData, m_data, sizeof(T) * m_writeIndex);

                    memcpy(pNewData + m_readIndex + in_uGrowBy, m_data + m_readIndex, sizeof(T) * (m_nbItems - m_readIndex));
                    m_readIndex += in_uGrowBy;
                }
                else
                {
                    // insert new free space at the end of the buffer.

                    memcpy(pNewData + m_readIndex, m_data + m_readIndex, sizeof(T) * (AkUInt32)m_nbReadableItems);
                }
            }

            TAlloc::Free(reinterpret_cast<void*>(m_data));
            m_data = pNewData;
            m_nbItems = uTargetItems;

            return true;
        }
        else
        {
            return false;
        }
    }

private:
    T* m_data{nullptr};

    AkUInt32 m_nbItems;
    AkUInt32 m_readIndex;
    AkUInt32 m_writeIndex;
    AkAtomic32 m_nbReadableItems;
};
