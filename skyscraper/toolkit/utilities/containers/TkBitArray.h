/**
 * @file TkBitArray.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename Key, unsigned int Size>
class cTkBitArrayStorage
{
    Key mArray[(Size / 64) ? 1 : (Size / 64)];
};

template <typename Key>
class cTkBitArrayStorage<Key, 0>
{
    const int kiArraySize;
    const int kiStorageArraySize;
    Key *mArray;
};

template <typename T, bool Static, unsigned int Size>
class cTkBitArray
{
  public:
    enum eTkStatic
    {
        eDefault,
    };

    using type = eTkStatic;

    cTkBitArrayStorage<T, Size> mStorage;
};

template <typename T, unsigned int Size>
class cTkBitArray<T, false, Size>
{
  public:
    enum eTkDynamic
    {
        eDefault,
    };

    using type = eTkDynamic;

    cTkBitArrayStorage<T, 0> mStorage;
};

SKYSCRAPER_END