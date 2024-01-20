/**
 * @file GcBaseBuildingPlaceholder.h
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

#include <basebuilding/GcBaseBuildingManagerTypes.h>
#include <basebuilding/GcBaseBuildingObject.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/TkQuaternion.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <gamestate/basebuilding/gcbasebuildingmode.meta.h>
#include <gamestate/basebuilding/gcbuildingplacementerrortypes.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

struct sBaseBuildingMaterial
{
    uint8_t muColourIndex;
    uint8_t muMaterialIndex;
};

class cGcProjectorEffect
{
  public:
    void UpdateRender(
        const cTkPhysRelVec3 &lStart, const cTkPhysRelMat34 &lTargetMat, const cGcBaseBuildingEntry *lpEntry,
        const cTkColour &lColour);

    cTkSmartResHandle mProjectorEffectRes;
    TkHandle mProjectorEffectNode;
    cTkSmartResHandle mPointerLineRes;
    TkHandle mPointerLineNode;
    float mfTimer;
    cTkSeed mSeed;
    cTkPersonalRNG mRNG;
};

class cGcBaseBuildingPlayerPlacement
{
  public:
    enum RotationAxis;
    struct sInvalidPlacementMetadata;

    bool IsValid();
    TkID<128> &GetCurrentID();
    bool HasTwinPosition();
    void Construct();
    void Update(float lfTimeStep);
    void UpdateRender();
    void Destruct();
    void GetInvalidPositionDescription(cTkFixedString<256, char> &lDescription);
    void RotatePlaceHolder(float lfAmount, cGcBaseBuildingPlayerPlacement::RotationAxis leAxis, bool lbCameraSpace);
    void UpdatePosition(float lfSlerp); // what the fuck is a slerp
    void RestorePlaceholderSettings();
    bool IsSnapped(TkHandle lNode);
    void SetValidPosition(
        bool lbValue, eInvalidPlacementReason leReason,
        cGcBaseBuildingPlayerPlacement::sInvalidPlacementMetadata &lReasonMetadata);
    void SetSelectedNode(TkHandle lNode, bool lbSuppressScanEffect);
    void SetCurrentBaseIndex(BaseIndex luBaseIndex);
    void SetColourIndex(uint8_t luColourIndex);
    void SetMaterialIndex(uint8_t luMaterialIndex);
    bool DuplicateSelectedNode();
    BaseIndex &GetBaseIndexForCurrentPart();
    void SetPreviewMode(bool lbPreviewMode);
    void SetPlaceholderHeartSize(float lfHeartSize);
    void SetGhostHeartSize(int liGhostIndex, float lfHeartSize);
    float GetMinPlacementDistanceForCurrentObject();
    bool DoesPartExistAsProductInInventories(const TkID<128> &lPartId);
    cTkPhysRelMat34 &PreviewMatrix();
    bool UpdateLoadPlaceholder();
    void GetScanEffect(bool lbSelection, cGcScanEffectData &lOutScanEffectData);
    void SetNodeState(TkHandle lNode, const char *lsStateName);
    TkHandle &AddGhostHeartToObject(const TkID<128> &lObjectID, TkHandle lObjectNode, const cTkVector3 &lLocalPosition);

    enum RotationAxis
    {
        ERotationAxis_XAxis,
        ERotationAxis_YAxis,
        ERotationAxis_ZAxis,
        ERotationAxis_NumEntries,
    };

    enum ePlacementMode
    {
        EPlacementMode_Default,
        EPlacementMode_Duplicating,
        EPlacementMode_Moving,
    };

    struct sPlaceholderSettings
    {
        cTkPhysRelMat34 mMatrix;
        cTkQuaternion mRotation;
        TkID<128> mRequestedID;
        sBaseBuildingMaterial mMaterial;
    };

    struct sPlacementGhost
    {
        TkHandle mObjectNode;
        TkHandle mHeartNode;
    };

    struct sSnapRotation
    {
        int miLastSnapIndex;
        int miRotationsRemaining;
        float mfRotationAngle;
    };

    struct sInvalidPlacementMetadata
    {
        cTkFixedString<128, char> mOffendersName;
        int miPartLimit;
    };

    const cGcBaseBuildingPlayerPlacement::RotationAxis kInitialRotationAxis;
    cGcBaseBuildingPlayerPlacement::sPlaceholderSettings mStoredPlaceholderSettings;
    eBaseBuildingMode meMode;
    eBaseBuildingMode mePreviousFrameMode;
    bool mbBuildingCamActive;
    TkID<128> muRequestedID;
    bool mbIsWiring;
    bool mbVisionsMode;
    cGcBaseBuildingPlayerPlacement::ePlacementMode mePlacementMode;
    const BaseBuildingObjectTemplate *mpCurrentObjectTemplate;
    cTkVector3 mHeartPosition;
    cTkAABB mPlaceholderGhostOBB;
    cGcBaseBuildingPlayerPlacement::sPlacementGhost mPlaceholderGhost;
    int miNumSnappingGhosts;
    cGcBaseBuildingPlayerPlacement::sPlacementGhost mSnappingGhosts[20];
    cGcBaseBuildingPlayerPlacement::sSnapRotation mSnapRotation;
    cTkQuaternion mPlaceholderRotation;
    float mfPlaceholderScale;
    sBaseBuildingMaterial mMaterial;
    TkHandle mScaleRotateGizmo;
    TkHandle mScaleRotateGizmoAxes[3];
    cGcBaseBuildingPlayerPlacement::RotationAxis meCurrentRotationAxis;
    bool mbRotationCameraSpace;
    cTkPhysRelMat34 mPlacementInterpMatrix;
    cTkPhysRelMat34 mPlaceholderAnimationMatrix;
    float mfPlaceholderPreviewEndTime;
    float mfPlaceholderPreviewStartTime;
    cTkPhysRelVec3 mTwinPosition;
    bool mbPlaceholderVisible;
    bool mbPlaceholderSnapped;
    bool mbPreviewMode;
    cTkVector3 mHiddenNearPosition;
    float mfHideTimer;
    float mfPlacementMaxDistance;
    eInvalidPlacementReason meInvalidPlacementReason;
    cGcBaseBuildingPlayerPlacement::sInvalidPlacementMetadata mReasonMetadata;
    cTkPhysRelVec3 mProjectorOrigin;
    cGcProjectorEffect mProjectorEffect;
    int miPlayerIndex;
    BaseIndex muCurrentBaseIndex;
    TkHandle mSelectedNode;
    cGcScanEffectData mPlacementScanEffect;
    cGcScanEffectData mSelectionScanEffect;
    int16_t miInitialCollisionGroups;
    bool mbMaintainRotationAndScaleWhenChangingPlaceholder;
    bool mbRenderInvalidCrosshair;
    bool mbEnableSnapping;
    bool mbHasChangedRotationAxis;
    bool mbSelectedNodeScanEffectSuppressed;
};

SKYSCRAPER_END