/**
 * @file GcBaseBuildingBaseLayout.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/maths/utilities/spatial/TkVector3KD.h>

#include <gamestate/basebuilding/gcpersistentbaseentry.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerBasePersistentBuffer;

class cGcBaseBuildingBaseLayout
{
  public:
    void GenerateLayout(cGcPlayerBasePersistentBuffer *lpBaseBuffer);
    void GenerateLayout(
        uint64_t lBaseUA, const cTkVector3 &lBaseWorldOffsetPosition, const cTkMatrix34 &lBaseOrientation,
        const cGcPersistentBaseEntry &lObjects, int liCount);
    void AddObject(const TkID<128> &lObjectId, const cTkVector3 &lLocalPosition);
    void Update(float lfTimeStep);
    bool ForceGenerateLayout();
    bool TestSphere(const cTkVector3 &lWorldOffsetPosition);
    bool TestBox(const cTkAABB &lWorldOffsetAABB);
    bool TestLayout(cGcBaseBuildingBaseLayout &lLayout);

    uint64_t mBaseUA;
    cTkVector3 mBasePosition;
    cTkVector3 mBaseUp;
    cTkVector3MetaKD<float, -1> mBaseObjectSpheres;
    // nanoflann::KDTreeSingleIndexAdaptor<
    //     nanoflann::L2_Simple_Adaptor<float, cTkVector3MetaKD<float, -1>, float>, cTkVector3MetaKD<float, -1>, 3,
    //     uint64_t>
    //     mBaseObjectsTree;
    nanoflann::KDTreeSingleIndexAdaptor mBaseObjectsTree;
    float mfBaseRadiusSqr;
    bool mbTreeNeedsRebuild;
    float mfTreeRebuildTimer;
};

SKYSCRAPER_END