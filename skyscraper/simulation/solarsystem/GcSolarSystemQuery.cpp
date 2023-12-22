/**
 * @file GcSolarSystemQuery.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-20
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

#include <simulation/solarsystem/GcSolarSystemQuery.h>

SKYSCRAPER_BEGIN

cGcSolarSystemQuery::cGcSolarSystemQuery() : mSystemAttributes()
{
    typedef void (*fn_type)(cGcSolarSystemQuery *thiscall);

    reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(
        renms_sdk::SignatureScan("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 54 41 56 41 57 48 83 "
                                 "EC ? 45 33 E4 48 C7 41 08 ? ? ? ?")))(this);
}

void cGcSolarSystemQuery::Run(uint64_t lUA, cGcSolarSystemQuery::Type leType, bool lbGenerateObjectLists)
{
    typedef void (*fn_type)(
        cGcSolarSystemQuery *thiscall, uint64_t lUA, cGcSolarSystemQuery::Type leType, bool lbGenerateObjectLists);

    return reinterpret_cast<fn_type>(reinterpret_cast<uint64_t>(renms_sdk::SignatureScan(
        "40 53 57 41 54 41 55 41 56 41 57 48 83 EC ? 4C 8B C2")))(this, lUA, leType, lbGenerateObjectLists);
}

SKYSCRAPER_END