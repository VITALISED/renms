#pragma once

#include <skyscraper.h>
#include <gamestate/EnvironmentLocation.h>
#include <metadata/simulation/player/gchand.meta.h>

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

    __declspec(align(16)) cGcOwnerConcept mOwnerConcept;
    cGcPlayerWanted mWanted;
    TkHandle mRootNode;
    std::vector<cTkAttachmentPtr,TkSTLAllocatorShim<cTkAttachmentPtr,8,-1> > maBeingScannedBy;
    float mfLastBeingScannedTime;
    std::vector<cTkAttachmentPtr,TkSTLAllocatorShim<cTkAttachmentPtr,8,-1> > maAttackingPredators;
    std::vector<cTkAttachmentPtr,TkSTLAllocatorShim<cTkAttachmentPtr,8,-1> > maEngagedPredators;
    float mfLastAttackTime;
    float mfLastRespawnTime;
    cTkAttachmentPtr mpRidingCreature;
    cTkAttachmentPtr mpPetCreature;
    cTkAttachmentPtr mpFriendlyDrone;
};

SKYSCRAPER_END