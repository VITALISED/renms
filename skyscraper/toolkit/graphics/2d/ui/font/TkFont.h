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
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>

SKYSCRAPER_BEGIN

class cTkCharDescr
{
    __int16 srcX;
    __int16 srcY;
    __int16 srcW;
    __int16 srcH;
    __int16 xOff;
    __int16 yOff;
    __int16 xAdv;
    __int16 page;
    unsigned int chnl;
    cTkVector<short> kerningPairs;
};


class cTkFont
{
    cTkTexture *mpTexture;
    cTkSmartResHandle mTextureRes;
    __int16 miFontHeight;
    __int16 miCharWidthMin;
    __int16 miCharPad;
    __int16 mu8BaseLine;
    __int16 mu8ScaleW;
    __int16 mu8ScaleH;
    std::array<cTkCharDescr,1024> maCharacters;
    std::array<short,65536> maiCharacterLookup;
    int miNumMappedChars;
    __int16 miDefaultCharacterIndex;
    float mfScale;
    bool mbLoaded;
};

SKYSCRAPER_END