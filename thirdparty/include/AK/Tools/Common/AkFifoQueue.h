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

#ifndef _AKFIFOQUEUE_H
#define _AKFIFOQUEUE_H

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/SoundEngine/Common/AkAtomic.h>
#include <AK/Tools/Common/AkArray.h>

/// AkFifoQueue is a lock-less, thread-safe, multi-producer-multi-consumer queue data structure.
/// It is designed to hold copyable values.
template<typename T, T TDEFAULT, class TAlloc = ArrayPoolDefault>
struct AkFifoQueue : public TAlloc
{
public:

	AkFifoQueue()
		: m_buffer(nullptr)
		, m_uQueueIndexMask(0)
		, m_readPos(0)
		, m_writePos(0)
	{
	}

	~AkFifoQueue()
	{
		Term();
	}

	/// Initializes the FifoQueue and allocates memory for the specified number of entries.
	/// The number of entries is not growable after initialization.
	AKRESULT Init(
		AkUInt32 in_uMaxEntries      ///< The number of entries. Must be a power of two.
		)
	{
		// check that maxentries is a power of 2
		AKASSERT((in_uMaxEntries & (in_uMaxEntries - 1)) == 0);

		m_uQueueIndexMask = in_uMaxEntries - 1;
		m_writePos = 0;
		m_readPos = 0;

		m_buffer = (FifoQueueEntry*)TAlloc::Alloc(sizeof(FifoQueueEntry) * in_uMaxEntries);
		if (m_buffer == nullptr)
		{
			return AK_InsufficientMemory;
		}

		AkZeroMemLarge(m_buffer, sizeof(FifoQueueEntry) * in_uMaxEntries);
		for (AkUInt32 i = 0; i < in_uMaxEntries; ++i)
		{
			m_buffer[i].value = TDEFAULT;
			AkAtomicStore64(&m_buffer[i].uSequence, i);
		}

		return AK_Success;
	}

	/// Free memory reserved for the queue and reset internal state
	/// The queue MUST be empty when this is called!
	void Term()
	{
		if (m_buffer)
		{
			AKASSERT(m_readPos == m_writePos);
			TAlloc::Free(m_buffer);

			m_buffer = nullptr;
		}
		m_readPos = 0;
		m_writePos = 0;
	}

	/// Enqueues the provided value. The value will be copied to the queue's internal buffer.
	/// Returns true if the enqueue was performed successfully.
	/// Returns false if the enqueue could not be performed. This can happen if the queue is "full", and some dequeue operations have to occur.
	AK_NODISCARD bool Enqueue(T in_value)
	{
		const AkUInt64 uQueueIndexMask = m_uQueueIndexMask;
		FifoQueueEntry* pBuffer = m_buffer;

		AkInt64 writePos = AkAtomicLoad64(&m_writePos);
		do {
			// see where we are in the sequence, relative to where we can write data
			AkInt64 sequenceDelta = AkAtomicLoad64(&pBuffer[writePos & uQueueIndexMask].uSequence) - writePos;
			// if we're in the right spot, and we can successfully write an updated write position, break out and write the handle into the queue
			if (sequenceDelta == 0)
			{
				if (AkAtomicCas64(&m_writePos, writePos + 1, writePos))
				{
					break;
				}
			}
			else if (sequenceDelta < 0)
			{
				// we would have over-enqueued if we tried to write the position in. Return false; the user needs to decide how to handle things
				return false;
			}
			else
			{
				// if it didn't work, reload writePos: someone else must have written to the sequence and we need to get caught up
				writePos = AkAtomicLoad64(&m_writePos);
			}
		} while (true);

		// advance the sequence by one so that it can be dequeued
		pBuffer[writePos & uQueueIndexMask].value = in_value;
		AkAtomicStore64(&pBuffer[writePos & uQueueIndexMask].uSequence, writePos + 1);
		return true;
	}

	/// Dequeues a value from the specified queue, copying it to io_value
	/// \return true if a value was successfully dequeued, false otherwise (if false, io_value will not be written to)
	bool Dequeue(T& io_value)
	{
		const AkInt64 uQueueIndexMask = m_uQueueIndexMask;
		FifoQueueEntry* pBuffer = m_buffer;

		AkInt64 readPos = AkAtomicLoad64(&m_readPos);
		do {
			// see where we are in the sequence relative to where we can write data
			AkInt64 sequenceDelta = AkAtomicLoad64(&pBuffer[readPos & uQueueIndexMask].uSequence) - (readPos + 1);
			// if we're in the right spot, and we can successfully write an updated read position, break out and read the entry
			if (sequenceDelta == 0)
			{
				if (AkAtomicCas64(&m_readPos, readPos + 1, readPos))
				{
					break;
				}
			}
			// if an entry has yet to be written, bail out
			else if (sequenceDelta < 0)
			{
				return false;
			}
			else
			{
				// if it didn't work, reload readPos
				readPos = AkAtomicLoad64(&m_readPos);
			}
		} while (true);

		// update the acceptable sequence value for this entry
		io_value = pBuffer[readPos & uQueueIndexMask].value;
		AkAtomicStore64(&pBuffer[readPos & uQueueIndexMask].uSequence, readPos + m_uQueueIndexMask + 1);

		return true;
	}

	/// Checks if there is a value available to be dequeued
	bool Empty()
	{
		AkInt64 readPos = AkAtomicLoad64(&m_readPos);
		AkInt64 sequenceDelta = AkAtomicLoad64(&m_buffer[readPos & m_uQueueIndexMask].uSequence) - (readPos + 1);
		return sequenceDelta < 0;
	}

private:
	struct FifoQueueEntry
	{
		// Value actually contained in the queue
		T value;
		// Global index of the queue entry in the sequence, to detect when we are at a valid read or write pos
		AkAtomic64 uSequence;
	};

	// Buffer of QueueEntries
	FifoQueueEntry* m_buffer;
	// Mask to apply to the read/write position to clamp it to array bounds
	AkInt64 m_uQueueIndexMask;

	// readIndex of where we are in the sequence
	AkAtomic64 m_readPos;
	// writeIndex of where we are in the sequence
	AkAtomic64 m_writePos;
};

#endif // _AKFIFOQUEUE_H
