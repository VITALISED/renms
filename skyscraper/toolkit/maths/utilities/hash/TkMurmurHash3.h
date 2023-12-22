/**
 * @file TkMurmurHash3.h
 * @author VITALISED & Contributors
 * @since 2023-12-22
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

// credit to MrSteyk for helping me out with this stuff

// check out this article for the mixer reference:
// http://zimbry.blogspot.com/2011/09/better-bit-mixing-improving-on.html

#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

namespace TkMurmur3
{

// generic finalise mix call
inline uint64_t FMix64Parameterised(
    uint64_t luValue, uint64_t luShift1, uint64_t luConst1, uint64_t luShift2, uint64_t luConst2, uint64_t luShift3)
{
    if (luShift1 < 64) luValue ^= (luValue >> luShift1);
    luValue *= luConst1;
    luValue ^= (luValue >> luShift2);
    luValue *= luConst2;
    luValue ^= (luValue >> luShift3);

    return luValue;
}

// mix02 finaliser, see top of file for reference
inline uint64_t FMix64StaffordMix02(uint64_t luValue)
{
    return FMix64Parameterised(luValue, 33, 0x64dd81482cbd31d7, 31, 0xe36aa5c613612997, 31);
}

} // namespace TkMurmur3

SKYSCRAPER_END