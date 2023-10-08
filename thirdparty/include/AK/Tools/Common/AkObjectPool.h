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

#ifndef _AKPOOLALLOCATOR_H
#define _AKPOOLALLOCATOR_H

#include <AK/Tools/Common/AkObject.h>
#include <AK/Tools/Common/AkAssert.h>
#include <AK/Tools/Common/AkArray.h>

/// Extra debug option when calling ObjectPool::Deallocate.
/// Going through the free list can be slow when the object count is high.
#define AK_OBJECT_POOL_EXTRA_SAFETY

namespace UnitTest { struct ObjectPoolHelper; }

namespace AK
{
	template<AkMemID T_MEMID = AkMemID_Object>
	using ObjectPoolDefaultAllocator = AkArrayAllocatorNoAlign<T_MEMID>;

	struct ObjectPoolNoLock
	{
		inline static constexpr void Lock() {}
		inline static constexpr void Unlock() {}
	};

	using ObjectPoolDefaultLockType = ObjectPoolNoLock;

	/// An object pool of N reusable objects with one allocation.
	template<
		typename T,
		typename AllocatorType = ObjectPoolDefaultAllocator<>,
		typename LockType = ObjectPoolDefaultLockType>
		class ObjectPool : AllocatorType, LockType
	{
	public:
		using ValueType = T;
		using SizeType = AkUInt32;
		static constexpr SizeType kInvalidIndex = (SizeType)-1;

		union DataType
		{
			inline ValueType& Data() { return *(ValueType*)data; }
			inline const ValueType& Data() const { return *(const ValueType*)data; }
			alignas(ValueType) uint8_t data[sizeof(ValueType)];
			SizeType next;
		};

		using AllocatorType::AllocatorType;

		ObjectPool() = default;
		ObjectPool(const ObjectPool&) = delete;
		ObjectPool(ObjectPool&&) = delete;

		inline ~ObjectPool() { AKASSERT(!m_data); }

		ObjectPool& operator=(const ObjectPool&) = delete;
		ObjectPool& operator=(ObjectPool&&) = delete;

		inline AKRESULT Init(SizeType count)
		{
			AKASSERT(!m_data && "ObjectPool is already initialized, call 'Term' before calling 'Init' again");
			AKASSERT(count && "ObjectPool count must be greater than zero");
			AKASSERT(count < kInvalidIndex && "ObjectPool count is above SizeType's maximum capacity");

			if (m_data || !count)
				return AK_InvalidParameter;

			m_data = reinterpret_cast<DataType*>(AllocatorType::Alloc(count * sizeof(DataType)));
			m_capacity = 0;
			m_size = 0;
			m_freeList = 0;

			if (!m_data)
				return AK_InsufficientMemory;

			m_capacity = count;

			for (SizeType i = 0; i < m_capacity - 1; i++)
				m_data[i].next = i + 1;

			m_data[m_capacity - 1].next = kInvalidIndex;

			return AK_Success;
		}

		inline void Term()
		{
			// Only assert when some object are still allocated and ValueType is not trivially destructible.
			AKASSERT(m_size == 0 && "Can't call Term() when some objects are still allocated");

			if (!m_data)
				return;

			AllocatorType::Free(m_data);
			m_data = nullptr;
			m_capacity = 0;
			m_size = 0;
			m_freeList = 0;
		}

		AK_NODISCARD inline SizeType Size() const { return m_size; }
		AK_NODISCARD inline SizeType Capacity() const { return m_capacity; }

		AK_NODISCARD inline bool IsFull() const { return m_size >= m_capacity; }
		AK_NODISCARD inline bool IsEmpty() const { return m_size == 0; }

		/// Allocates a new object.
		/// @returns the object on success or nullptr if it fails (already full).
		/// @{
		AK_NODISCARD inline ValueType* Allocate()
		{
			if (IsFull())
				return nullptr;

			LockType::Lock();
			DataType& data = m_data[m_freeList];
			m_freeList = data.next;
			m_size++;
			LockType::Unlock();
			return &data.Data();
		}

		/// Initialize memory before returning.
		AK_NODISCARD inline ValueType* AllocateZeroFilled()
		{
			ValueType* value = Allocate();
			if (value)
				AKPLATFORM::AkMemSet((void*)value, 0, (AkUInt32)sizeof(ValueType));

			return value;
		}
		/// @}

		/// Deallocates given pointer.
		/// Calling Deallocate when IsEmpty() returns true is undefined behaviour.
		/// Calling Deallocate with a pointer that wasn't allocated by this pool is undefined behaviour.
		///
		/// You can define AK_OBJECT_POOL_EXTRA_SAFETY for extra debugging check.
		inline AKRESULT Deallocate(ValueType* data)
		{
			AKASSERT(data && "Deallocating null data");
			DataType* tdata = reinterpret_cast<DataType*>(data);

			// Check if data is in memory range.
			AKASSERT((tdata >= m_data && tdata < m_data + m_capacity) && "Pointer address out of range");
			if (tdata < m_data || tdata >= m_data + m_capacity)
				return AK_InvalidParameter;

			LockType::Lock();
			AKASSERT(m_size && "Trying to deallocate when empty");

#ifdef AK_OBJECT_POOL_EXTRA_SAFETY
			AKASSERT(IsAllocated((SizeType)(tdata - m_data)));
#endif
			m_size--;
			tdata->next = m_freeList;
			m_freeList = (SizeType)(tdata - m_data);
			LockType::Unlock();

			return AK_Success;
		}

		/// Deallocates all objects.
		/// This function should only be called if ValueType is trivially destructible.
		inline void Clear()
		{
			for (SizeType i = 0; i < m_capacity - 1; i++)
				m_data[i].next = i + 1;

			m_data[m_capacity - 1].next = kInvalidIndex;
			m_size = 0;
			m_freeList = 0;
		}

	private:
		DataType* m_data = nullptr;
		SizeType m_capacity = 0;
		SizeType m_size = 0;
		SizeType m_freeList = 0;

		friend struct UnitTest::ObjectPoolHelper;

		inline bool IsAllocated(SizeType index) const
		{
			for (SizeType k = m_freeList; k != kInvalidIndex; k = m_data[k].next)
				if (index == k)
					return false;

			return true;
		}
	};
} // namespace AK
#endif
