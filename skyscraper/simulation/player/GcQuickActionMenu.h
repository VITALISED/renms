/**
 * @file GcQuickActionMenu.h
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

#include <simulation/player/GcQuickMenuTypes.h>

SKYSCRAPER_BEGIN

class cGcQuickActionMenu : public cGcQuickMenuState
{
  public:
    struct ActionTable
    {
        int miCurrentActionDepth;
        std::array<cTkVector<MenuAction>, 3> maActionDepths;
        std::array<int, 3> maSelectedActions;
    };

    struct HotAction
    {
        MenuAction mKeyAction;
        MenuAction mOpenMenuToAction[5];
    };

    cGcQuickActionMenu::HotAction maHotActionKeys[3][10];
    cGcQuickActionMenu::ActionTable mActionTable;
    cTkSmartResHandle mSummonNexusIcon;
    cTkSmartResHandle mSummonSquadronIcon;
    cTkSmartResHandle mSummonFreighterIcon;
    cTkSmartResHandle mSummonShipMenuIcon;
    cTkSmartResHandle mSummonVehicleMenuIcon;
    cTkSmartResHandle maSummonVehicleIcons[7];
    cTkSmartResHandle mVehicleAIToggleIcon;
    cTkSmartResHandle mVehicleScanIcon;
    cTkSmartResHandle mVehicleResetRaceIcon;
    cTkSmartResHandle mTorchOnIcon;
    cTkSmartResHandle mTorchOffIcon;
    cTkSmartResHandle mGalaxyMapIcon;
    cTkSmartResHandle mPhotoModeIcon;
    cTkSmartResHandle mCommunicatorIcon;
    cTkSmartResHandle mThirdPersonCharacterIcon;
    cTkSmartResHandle mThirdPersonShipIcon;
    cTkSmartResHandle mThirdPersonVehicleIcon;
    cTkSmartResHandle mTerrainAdvancedIconOn;
    cTkSmartResHandle mTerrainAdvancedIconOff;
    cTkSmartResHandle mChargeMenuIcon;
    cTkSmartResHandle mSummonMenuIcon;
    cTkSmartResHandle mPetMenuIcon;
    cTkSmartResHandle mPetManagerIcon;
    cTkSmartResHandle mUtilityMenuIcon;
    cTkSmartResHandle mSecondaryWeaponMenuIcon;
    cTkSmartResHandle mCreatureBaitIcon;
    cTkSmartResHandle mEconomyScannerIcon;
    cTkSmartResHandle mCargoShieldIcon;
    cTkSmartResHandle mWarpToNexusIcon;
    cTkSmartResHandle mByteBeatIcon;
    cTkSmartResHandle mByteBeatPlayIcon;
    cTkSmartResHandle mReportBaseIcon;
    cTkSmartResHandle mSummonRocketIcon;
    cTkSmartResHandle mEmoteMenuIcon;
    cTkVector<cTkSmartResHandle> mEmoteIcons;
    cTkVector<cTkSmartResHandle> mUnderWaterEmoteIcons;
    cTkVector<cTkSmartResHandle> mPetCommandEmoteIcons;
    cTkSmartResHandle mRocketLockerRes;
    eQuickMenuActions mStartOverrideAction;
    bool mbTriggerOverrideAction;
    bool mbOverrideToFirstActionInSubMenu;
    bool mbOverrideToLastActionInSubMenu;
    bool mbFirstUpdate;
    bool mbEnteredSubMenu;
    int miOpenToHotKey;
    float mfAutoCloseTimer;
};

SKYSCRAPER_END