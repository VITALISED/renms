#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

enum eTkMemType
{
	EMemoryPool_Physics,
	EMemoryPool_SingleBuffer,
	EMemoryPool_DoubleBuffer,
	EMemoryPool_DoubleBufferPausable,
	EMemoryPool_IO,
	EMemoryPool_Network,
	EMemoryPool_Resources,
	EMemoryPool_Audio,
	EMemoryPool_Graphics,
	EMemoryPool_Compute,
	EMemoryPool_Nodes,
	EMemoryPool_AnimStages,
	EMemoryPool_BlockAllocator,
	EMemoryPool_GraphicsContext,
	EMemoryPool_CommandBuffers,
	EMemoryPool_Debug,
	EMemoryPool_Metadata,
	EMemoryPool_NodeAllocator,
	ENumTkMemoryPools = 18,
};

template <unsigned int liSize, unsigned int liAlignment>
class cTkAlignedBlock
{
	unsigned __int8 data_[(liAlignment == 1) ? liSize * (liAlignment + 3) : liSize * liAlignment];
};

template <typename T>
struct __declspec(align(8)) StackAllocator : std::allocator<T>
{
	using value_type = T;

	template <typename U>
	struct rebind
	{
		using other = StackAllocator<U>;
	};

	struct Source
	{
		cTkAlignedBlock<sizeof(T), alignof(T)> stack_buffer_;
		bool used_stack_buffer_;
	};
};

template <typename T>
class TkSTLAllocatorShim : public std::allocator<T>
{ 
    template <typename U>
    struct rebind
    {
        using other = TkSTLAllocatorShim<U>;
    };
};

SKYSCRAPER_END