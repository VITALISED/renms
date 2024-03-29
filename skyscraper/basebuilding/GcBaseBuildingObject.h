/**
 * @file GcBaseBuildingObject.h
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

#include <toolkit/maths/geometry/TkAABB.h>

#include <gamestate/basebuilding/gcbasebuildingentry.meta.h>

SKYSCRAPER_BEGIN

struct TemplateHandleSet
{
    uint16_t muStart;
    uint16_t muCount;
};

struct CacheMask
{
    uint64_t muMask[4];
};

struct SnapSocketsMask
{
    bool IsCompatible(const SnapSocketsMask &lMask);

    CacheMask mInMask;
    CacheMask mOutMask;
};

struct BaseBuildingObjectTemplate
{
    cGcBaseBuildingEntry *mpEntry;
    TemplateHandleSet mSnapPointTemplates;
    TemplateHandleSet mPlacementModelRules;
    hkRefPtr<hknpConvexShape> mpPlacementCollisionShape;
    SnapSocketsMask mSnapSocketsMask;
    CacheMask mConditionsMask;
    cTkAABB mOBB;
    cTkAABB mMeshOBB;
    float mfLayoutRadius;
    bool mbHasRequiredSnapPoint;
    bool mbHasTwinSnapPoint;
};

SKYSCRAPER_END