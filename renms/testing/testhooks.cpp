/**
 * @file testhooks.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-24
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

#include <testing/testhooks.h>

RENMS_HOOK(
    cGcSolarSystemGenerator__Generate,
    renms::SignatureScan("48 89 5C 24 18 4C 89 4C 24 20 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 E0 DD FF FF"),
    void,
    (nms::cGcSolarSystemGenerator * thiscall, const nms::cTkSeed *lSeed,
     const nms::cGcGalaxyAttributesAtAddress *lAttributes, nms::cGcSolarSystemGenerator::GenerationData *lData) {
        spdlog::info("System Seed from Generator: {:X}", lSeed->mu64SeedValue);
        return RENMS_CAST(cGcSolarSystemGenerator__Generate, thiscall, lSeed, lAttributes, lData);
    });

RENMS_BEGIN

void CreateTestingHooks()
{
    RENMS_DISPATCH_HOOK(cGcSolarSystemGenerator__Generate);
}

RENMS_END