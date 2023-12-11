/**
 * @file GcTradeRoute.h
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

#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/graphics/2d/ui/objects/Tk2dImage.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/system/timer/TkTimer.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcTradeRouteCurvePoint
{
  public:
    int64_t muX;
    int64_t muY;
    int64_t muZ;
    uint64_t muDistance;
    uint64_t muTotalDistance;
};

class cGcTradeRouteSection
{
  public:
    cTkVector3 mStart;
    cTkVector3 mMid1;
    cTkVector3 mMid2;
    cTkVector3 mMid3;
    cTkVector3 mMid4;
    cTkVector3 mEnd;
    cTkVector<cGcTradeRouteCurvePoint> maPoints;
    uint64_t muTotalLength;
    unsigned int mLineHandle;
};

class cGcTradeRoute
{
  public:
    struct FakeTrail
    {
        TkHandle mNode;
        cTkTimerTemplate<0> mFadeTimer;
        cTkVector<TkHandle> mEmitterNodes;
    };

    struct VirtualShip
    {
        cTkVector3 mWorldPosition;
        cTkVector3 mWorldDir;
        cTkVector4 mScreenPosition;
        float mfProgress;
        cTkAttachmentPtr mpRealShip;
        cGcTradeRoute::FakeTrail mTrail;
    };

    cTkVector<cGcTradeRoute::VirtualShip> maShips;
    cTkVector<cGcTradeRouteSection> maSections;
    cTkSeed mSeed;
    cTk2dImageEx mIcon;
};

SKYSCRAPER_END