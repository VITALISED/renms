/**
 * @file GcPlayerAim.h
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
#include <toolkit/simulation/physics/havok/TkRigidBody.h>

SKYSCRAPER_BEGIN

class cGcPlayer;

class cGcPlayerAimTarget
{
  public:
    cTkPhysRelVec3 mPoint;
    cTkVector3 mNormal;
    int miMaterial;
    cTkRigidBodyPtr mpBody;
    cTkAttachmentPtr mpAttachment;
};

class cGcPlayerAim
{
  public:
    cGcPlayer *mpPlayer;
    cGcPlayerAimTarget mLookTarget;
    cGcPlayerAimTarget mShootTarget;
    cTkAttachmentPtr mpAutoAimTarget;
    cTkPhysRelVec3 mAutoAimIntercept;
    cTkVector3 mAutoAimPos;
    float mfAutoAimWeight;
};

SKYSCRAPER_END