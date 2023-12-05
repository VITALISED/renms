/**
 * @file TkAlignedMemory.h
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

template <uint32_t liSize, uint32_t liAlignment>
class cTkAlignedBlock
{
  public:
    alignas(liAlignment) uint8_t data_[liSize];
    void *void_data() { return static_cast<void *>(data_); }
    const void *void_data() const { return static_cast<const void *>(data_); }
    template <typename Type>
    Type *data_as()
    {
        return static_cast<Type *>(void_data());
    }
    template <typename Type>
    const Type *data_as() const
    {
        return static_cast<const Type *>(void_data());
    }

  private:
    void *operator new(size_t);
    void operator delete(void *);
};

SKYSCRAPER_END