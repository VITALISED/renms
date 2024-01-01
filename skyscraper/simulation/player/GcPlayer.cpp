/**
 * @file GcPlayer.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-18
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

#include <simulation/player/GcPlayer.h>

SKYSCRAPER_BEGIN

void cGcPlayer::SetToPosition(const cTkVector3 *lPos, const cTkVector3 *lDir, const cTkVector3 *lVel)
{
    typedef void (*fn_type)(
        cGcPlayer *thiscall, const cTkVector3 *lPos, const cTkVector3 *lDir, const cTkVector3 *lVel);

    return reinterpret_cast<fn_type>(renms::SignatureScan("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC "
                                                          "? 0F 29 74 24 60 49 8B F9 0F 29 7C 24 50 49 8B F0"))(
        this, lPos, lDir, lVel);
}

SKYSCRAPER_END