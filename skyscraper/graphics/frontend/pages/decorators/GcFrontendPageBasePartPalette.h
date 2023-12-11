/**
 * @file GcFrontendPageBasePartPalette.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <toolkit/core/types/TkHandle.h>
#include <toolkit/utilities/containers/TkBitArray.h>

SKYSCRAPER_BEGIN

class cGcFrontendPageBasePartPalette
{
  public:
    TkHandle maLightNodes[4];
    cTkBitArray<uint64_t, 1, 128> mAvailablePalettes;
    cTkBitArray<unsigned int, 1, 32> mAvailableMaterials;
    uint8_t mu8ObjectPaletteIndex;
    uint8_t mu8SelectedPaletteIndex;
    uint8_t mu8ObjectMaterialIndex;
    uint8_t mu8SelectedMaterialIndex;
    bool mbPaletteChanged;
    bool mbMaterialChanged;
};

SKYSCRAPER_END