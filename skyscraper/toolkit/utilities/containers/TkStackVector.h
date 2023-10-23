#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>
#include <toolkit/utilities/containers/TkStackContainer.h>

SKYSCRAPER_BEGIN

//this is 100% fucked
template <typename T>
class cTkStackVector : public StackContainer<std::vector<T, StackAllocator<T>>>
{ };

SKYSCRAPER_END