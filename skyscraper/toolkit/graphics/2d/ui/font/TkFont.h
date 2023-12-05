/**
 * @file TkFont.h
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

#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cTkCharDescr
{
    int16_t srcX;
    int16_t srcY;
    int16_t srcW;
    int16_t srcH;
    int16_t xOff;
    int16_t yOff;
    int16_t xAdv;
    int16_t page;
    unsigned int chnl;
    cTkVector<short> kerningPairs;
};

class cTkFont
{
    cTkTexture *mpTexture;
    cTkSmartResHandle mTextureRes;
    int16_t miFontHeight;
    int16_t miCharWidthMin;
    int16_t miCharPad;
    int16_t mu8BaseLine;
    int16_t mu8ScaleW;
    int16_t mu8ScaleH;
    std::array<cTkCharDescr, 1024> maCharacters;
    std::array<short, 65536> maiCharacterLookup;
    int miNumMappedChars;
    int16_t miDefaultCharacterIndex;
    float mfScale;
    bool mbLoaded;
};

SKYSCRAPER_END