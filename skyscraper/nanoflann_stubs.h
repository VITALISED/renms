/**
 * @file nanoflann_stubs.h
 * @author VITALISED & Contributors
 * @since 2023-12-10
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

namespace nanoflann
{
// template <typename T, typename U, int Dim, typename Z>
class KDTreeSingleIndexAdaptor
{
    char vind[0x18];
    unsigned __int64 m_leaf_max_size;
    uintptr_t dataset;
    char index_params[0x10];
    unsigned __int64 m_size;
    int dim;
    uintptr_t root_node;
    char root_bbox[0x18];
    char pool[0x38];
    uintptr_t distance;
};

} // namespace nanoflann