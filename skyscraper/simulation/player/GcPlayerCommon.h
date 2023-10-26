#pragma once

#include <skyscraper.h>
#include <gamestate/EnvironmentLocation.h>
#include <simulation/player/GcOwnerConcept.h>
#include <simulation/player/GcPlayerWanted.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <metadata/source/simulation/player/gchand.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerCommon
{
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
};

SKYSCRAPER_END