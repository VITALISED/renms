/**
 * @file GcNetworkPlayerFullSim.h
 * @author VITALISED & Contributors
 * @since 2023-12-08
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

#include <networking/GcNetworkPlayer.h>
#include <networking/GcNetworkPlayerFullSim.h>
#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <toolkit/networking/TkNetworkId.h>

SKYSCRAPER_BEGIN

class cGcNetworkPlayerFullSim : public cGcNetworkPlayer
{
  public:
    /*cGcNetworkPlayerTeleportEffect*/ uintptr_t *mpTeleportEffect;
    cTkFixedString<256, char> mNameWithTitle;
    cTkMatrix34 maPreviousWristMatrix[2];
    cTkMatrix34 maDesiredWristMatrix[2];
    cTkVector3 mWorldPosition;
    cTkVector3 mMapPosition;
    cTkVector3 mLookAtPoint;
    cTkNetworkId mCurrentPossessedNetReplicatedId;
    cTkNetworkId mPrimaryShipNetReplicatedId;
    cTkNetworkId mRiddenCreatureNetReplicatedId;
    float mfEnergyLevel;
    float mfHazardLevel;
    float mfTimeSinceLastUpdateRecvd;
    float mfSendUpdateTimer;
    float mfSendHandTrackingUpdateTimer;
    float mfDistanceFromLocalPlayer;
    int mPlayerIndex;
    int miNumPlayersInFireteam;
    cTkAttachmentPtr mShipWeaponLockTarget;
    float mfHealthPercent;
    float mafWristMotionCompletion[2];
    float mfWristMotionDuration;
    cTkUserIdBase<cTkFixedString<64, char>> mPlayerFreighterOwnerId;
    TkHandle mCurrentNode;
    uint64_t mActiveBattleUA;
    cGcMarkerPoint mMarkerPoint;
    cGcNetworkWeapon mWeapon;
    uint8_t meState[1];
    uint8_t mePendingState[1];
    uint64_t muStateChangeTime;
    robin_hood::detail::Table<
        true, 80, cTkNetworkId, void, robin_hood::hash<cTkNetworkId, void>, std::equal_to<cTkNetworkId>>
        mEntitiesToReplicate;
    uint8_t mbJetpacking[4];
    bool mbHasWarpDrive;
    bool mbHasWorkingWarpDrive;
    bool mbIsOnOtherSideOfPortal;
    bool mbIsSliding;
    eHand meDominantHand;
    bool mabHasTrackedHand[2];
    bool mbIsVRPlayer;
    bool mbIsValidCreatureAttackTarget;
    cTkVector3 mGrabbedByPosition;
    cTkBitArray<uint64_t, 1, 11> mMPMissionEligibility;
};

SKYSCRAPER_END