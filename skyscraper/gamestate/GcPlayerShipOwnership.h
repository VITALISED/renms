#pragma once

#include <skyscraper.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <metadata/simulation/customisation/gccustomisationcomponentdata.meta.h>
#include <metadata/simulation/spaceship/gcspaceshipcomponentdata.meta.h>
#include <metadata/simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerShipOwnership
{
    struct sGcShipData
    {
        cTkSeed mPlayerShipSeed;
        cTkSmartResHandle mPlayerShipResHandle;
        TkHandle mPlayerShipNode;
        cTkAttachmentPtr mpPlayerShipAttachment;
        int mFreighterDockIndex;
        cGcCustomisationComponentData mShipCustomisationData;
    };

    std::unordered_map<int,std::function<void __cdecl(cTkMatrix34 const &)>> mNewSpaceshipSpawnCallbacks;
    TkHandle mGroupRootNode;
    cGcPlayerShipOwnership::sGcShipData mShips[12];
    cTkMatrix34 mPlayerShipTMWhenLastDestroyed;
    cTkMatrix34 mNewShipDelayedSpawnMatrix;
    const cGcSpaceshipComponentData *mpPrimaryShipComponentData;
    int miCachedShipComponentDataIndex;
    cTkModelResourceRenderer maThumbnailRenderers[12];
    cGcPlacementArc mPlacementArc;
    cTkVector2 mInitialPlacementDirection;
    float mfPlacementRotation;
    bool mbUseOffHandForPlacementRotation;
    cTkVector<cGcPlayerShipOwnership::RetiredShipRecord> mRetiredShips;
    bool mbShowShipPreview;
    int miShipToPreview;
    int miCurrentPreviewShip;
    TkHandle mPreviewShipNode;
    cTkPhysRelMat34 mLastKnownPreviewMatrix;
    cTkPhysRelMat34 mLastGoodPreviewMatrix;
    bool mbLastGoodPreviewMatrixValid;
    cGcScanEffectData mShipPreviewScanData;
    float mfShipPreviewFirstActiveTime;
    float mfShipPreviewLastActiveTime;
    cTkVector3 mShipPreviewScale;
     cTkColour mShipPreviewColour;
    bool mbShouldRefreshMesh;
    cGcPlayerShipOwnership::eMeshRefreshState mMeshRefreshState;
    cTkSmartResHandle mRefreshSwapRes;
    bool mbNextSummonIsFree;
};

SKYSCRAPER_END