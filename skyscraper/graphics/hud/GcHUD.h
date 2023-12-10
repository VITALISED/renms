/**
 * @file GcHUD.h
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

#include <skyscraper.h>

#include <toolkit/graphics/2d/ui/layers/Tk2dLayer.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dImage.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dText.h>
#include <toolkit/system/timer/TkTimer.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <graphics/hud/gchudimagedata.meta.h>
#include <graphics/hud/gchudlayerdata.meta.h>
#include <graphics/hud/gchudtextdata.meta.h>

SKYSCRAPER_BEGIN

class cGcHUDScreensPool
{
  public:
    cTkClassPoolHandle maScreens[200];
    cTkClassPoolHandle *mapScreenPools[6];
    int maCurrentScreens[6];
};

class cGcHUDLayer
{
  public:
    cTk2dLayer mLayer;
    cGcHUDLayerData *mpData;
};

class cGcHUDImage
{
  public:
    cTk2dImageEx mImage;
    cGcHUDImageData *mpData;
    cTkColour mColourStart;
    cTkColour mColourEnd;
    cTkTimerTemplate<0> mColourTimer;
};

class cGcHUDText
{
    cTkFixedString<256, wchar_t> mBuffer;
    cTk2dText mText;
    cGcHUDTextData *mpData;
};

class cGcHUD
{
  public:
    cTkSmartResHandle mUIMaterial;
    cGcHUDLayer maLayers[128];
    int miNumLayers;
    cGcHUDImage maImages[128];
    int miNumImages;
    cGcHUDText maTexts[128];
    int miNumTexts;
};

SKYSCRAPER_END