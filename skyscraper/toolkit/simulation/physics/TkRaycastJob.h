/**
 * @file TkRaycastJob.h
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

#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/simulation/physics/havok/TkRigidBodyGameplayFlags.h>
#include <toolkit/system/memory/TkMemoryManager.h>
#include <toolkit/system/thread/TkRegionThreadManager.h>

SKYSCRAPER_BEGIN

class cTkContactPoint
{
    cTkRigidBodyPtr mpHitBody;
    cTkPhysRelVec3 mvContactPoint;
    cTkVector3 mvContactNormal;
    int miMaterial;
    int miSubIndex;
    float mfDistance;
    float mfFraction;
    bool mbIsFresh;
    bool mbIsBodyA;
    unsigned __int8 muRayHitFlags;
};

class cTkRaycastJob
{
    struct Contact
    {
        cTkPhysRelVec3 mvPosition;
        cTkVector3 mvNormal;
        unsigned int miHitBody;
        float mfHitFraction;
        unsigned __int16 miHitMaterial;
        unsigned __int8 muRayHitFlags;
    };

    struct Ray
    {
        cTkPhysRelVec3 mvFrom;
        cTkPhysRelVec3 mvTo;
        unsigned int mIgnoreBodyIdInt;
        unsigned int miFilter;
        cTkRaycastJob::Contact mFirstContact;
        cTkRaycastJob::Contact *mExtraContacts;
        unsigned __int16 miNumContacts;
        unsigned __int16 miMaxContacts;
        float mfRadius;
        eTkRigidBodyGameplayFlags mxIgnoreGameplayFlags;
        bool mbAllowBackfaces;
        bool mbAllowInsideHits;
        bool mbIgnoreCameraInvisible;
        unsigned int mFirstShapeKey;
    };

    struct Status
    {
        bool mbKicked;
        bool mbWaited;
        bool mbPausable;
        eTkMemType meMemoryPool;
        TkJobHandle mJobHandle;
        cTkRaycastJob::Ray *maRays;
        int miNumRays;
        const char *mpFile;
        const char *mpFunc;
        int miLine;
    };

    cTkRaycastJob::Status *maStatus;
    unsigned int miNumJobs;
    cTkRaycastJob::Ray *maRays;
    int miNumRays;
    bool mbConstructed;
    unsigned __int64 miFrameNum;
    eTkMemType meMemoryPool;
};

SKYSCRAPER_END