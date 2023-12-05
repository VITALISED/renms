/**
 * @file Tk2dLayer.h
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

#include <toolkit/graphics/2d/ui/objects/Tk2dObject.h>
#include <toolkit/utilities/containers/TkBitArray.h>

SKYSCRAPER_BEGIN

enum eTkBlendMode
{
    EBlendMode_None,
    EBlendMode_Normal,
    EBlendMode_Additive,
    EBlendMode_Subtractive,
    EBlendMode_SourceRGBIsAlpha,
    EBlendMode_EngineBlend,
    EBlendMode_EngineAdd,
    EBlendMode_EngineMult,
    EBlendMode_EngineBlend_OutputOneMinusAlpha,
    EBlendMode_EngineBlend_OutputAlpha,
    EBlendMode_EngineAdd_OutputOneMinusAlpha,
    EBlendMode_InvSourceAlpha,
    EBlendMode_SourceAlpha,
    EBlendMode_RgbOnly,
    EBlendMode_AlphaOnly,
    EBlendMode_Num = 15,
};

class cTk2dLayer : public cTk2dObject
{
  public:
    cTkBitArray<uint64_t, true, 512> mBitArray;
    eTkBlendMode meBlendMode;
    cTk2dObject *mpFirstChild;
    bool mbIsVisible;
    bool mbDynamicSize;
    cTkVector2 mScale;
    float mfAngle;

    virtual void ConstructDynamicSize(const cTkVector2 *, const cTkVector2 *);
    virtual void Construct(const cTkVector2 *, const cTkVector2 *, const cTkVector2 *);
    virtual void SetScale(const cTkVector2 *);
    virtual void SetAngle(float);
    virtual float GetAngle();
    virtual cTkVector2 *CalculateSize(cTkVector2 *result);
};

SKYSCRAPER_END