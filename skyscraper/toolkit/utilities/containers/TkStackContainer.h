#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
struct StackContainer
{
	typename T::allocator_type::Source stack_data_;
	typename T::allocator_type allocator_;
	T container_;
};

SKYSCRAPER_END