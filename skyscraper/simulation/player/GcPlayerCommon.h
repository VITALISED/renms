/**
 * @file GcPlayerCommon.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <simulation/environment/GcEnvironment.h>
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/player/GcPlayerWanted.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerCommon
{
  public:
    cGcOwnerConcept mOwnerConcept;
    cGcPlayerWanted mWanted;
    TkHandle mRootNode;
    cTkVector<cTkAttachmentPtr> maBeingScannedBy;
    float mfLastBeingScannedTime;
    cTkVector<cTkAttachmentPtr> maAttackingPredators;
    cTkVector<cTkAttachmentPtr> maEngagedPredators;
    float mfLastAttackTime;
    float mfLastRespawnTime;
    cTkAttachmentPtr mpRidingCreature;
    cTkAttachmentPtr mpPetCreature;
    cTkAttachmentPtr mpFriendlyDrone;

    virtual bool IsInSpaceship();
    virtual bool IsInLandVehicle();
    virtual EnvironmentLocation::Enum GetEnvironmentLocation();
    virtual bool IsLocalPlayer();
    virtual int GetNetworkIndex();
    virtual bool IsVRPlayer();
    virtual eHand GetDominantHand();
    virtual bool IsFullSimLobbyHost();
    virtual cTkMatrix34 *VirtualGetMatrix(cTkMatrix34 *result);
    virtual cTkAttachment *VirtualGetAttachment();
    virtual TkHandle *GetNode(TkHandle *result);
    virtual void NotifyBeingScanned(cTkAttachment *);
    virtual bool IsStealthActive();
};

SKYSCRAPER_END