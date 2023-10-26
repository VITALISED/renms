#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <metadata/source/simulation/customisation/gccustomisationcomponentdata.meta.h>
#include <metadata/source/simulation/spaceship/gcspaceshipcomponentdata.meta.h>
#include <metadata/source/simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerShipOwnership
{
public:
    struct sGcShipData
    {
        cTkSeed mPlayerShipSeed;
        cTkSmartResHandle mPlayerShipResHandle;
        TkHandle mPlayerShipNode;
        cTkAttachmentPtr mpPlayerShipAttachment;
        int mFreighterDockIndex;
        cGcCustomisationComponentData mShipCustomisationData;
    };

    struct RetiredShipRecord
    {
        cTkSmartResHandle mShipResHandle;
        TkHandle mShipNode;
    };

    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
        SwapMesh,
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