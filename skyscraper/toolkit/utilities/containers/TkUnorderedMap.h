/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <toolkit/system/memory/TkMemoryManager.h>

SKYSCRAPER_BEGIN

template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = TkSTLAllocatorShim<std::pair<const Key, T> > >
class cTkUnorderedMap : public std::unordered_map<T, TkSTLAllocatorShim<T>>
{ };

struct TkIDUnorderedMap::Hash256
{
};


namespace TkIDUnorderedMap
{
    struct Hash128
    { };

    struct Hash256
    { };
}

SKYSCRAPER_END