/**
 * @file Tk3dLayer.h
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

#include <toolkit/graphics/2d/ui/layers/Tk2dLayer.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>

SKYSCRAPER_BEGIN

class cTk3dLayer : public cTk2dLayer
{
    enum eDepthTest
    {
        EDepthTest_None,
        EDepthTest_Normal,
        EDepthTest_Inverse,
    };

    cTkVector3 mWorldPosition;
    cTkVector4 mScreenPosition;
    cTkVector4 mScreenPositionLeft;
    cTkVector4 mScreenPositionRight;
    float mfScreenDepth;
    float mfDefaultDistToCamera;
    float mfMinScale;
    float mfMaxScale;
    cTk3dLayer::eDepthTest meTestZ;
    bool mbEnable3d;
    bool mbScale3d;

    virtual void ConstructDynamicSize(const cTkVector3 *, const cTkVector2 *);
    virtual void Construct(const cTkVector3 *, const cTkVector2 *, const cTkVector2 *);
    virtual void SetPosition(const cTkPhysRelVec3 *);
    virtual void SetPosition(const cTkVector3 *);
};

SKYSCRAPER_END