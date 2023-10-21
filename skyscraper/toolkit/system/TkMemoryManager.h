#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

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