/**
 * @file GcCreatureSwarm.h
 * @author VITALISED & Contributors
 * @since 2023-12-07
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

#include <simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>
#include <simulation/ecosystem/creatures/data/gccreatureswarmdata.meta.h>
#include <simulation/ecosystem/creatures/gccreaturedata.meta.h>

SKYSCRAPER_BEGIN

class cGcCreatureRoutinePtr
{
    int64_t miUniqueId;
};

class cGcCreatureNode
{
  public:
    /*cTkPhysicsComponent*/ uintptr_t *mpPhysics;
    /*cGcShootableComponent*/ uintptr_t *mpShootable;
    cTkAttachmentPtr mpAttachment;
    TkHandle mNode;
    ePrimaryAxis meAxis;
    float mfAvoidRadius;
};

class cGcCreatureSwarm
{
  public:
    cGcCreatureNode maSwarmComponents[128];
    const cGcCreatureSwarmData *mpData;
    const cGcCreatureSwarmDataParams *mpParams;
    cTkVector<cTkVector3> mPath;
    cGcCreatureRoutinePtr mpRoutine;
    cTkPhysRelVec3 mSpawnPosition;
    cTkPhysRelVec3 mFollowPosition;
    cTkPhysRelVec3 mAveragePosition;
    cTkVector3 mAverageHeading;
    int miFreighterRoom;
    cTkAttachmentPtr mpFreighterAttachment;
    cTkVector3 maSearchPositions[4];
    int miNumComponents;
    int miNumSearchPositions;
    eMoveArea meMoveType;
    bool mbReserved;
    float mfTimer;
    float mfIgnoreTerrainTimer;
    bool mbIgnoreTerrain;
};

SKYSCRAPER_END