/**
 * @file GcFrontendPopup.h
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

#include <gamestate/GcInventoryStore.h>
#include <graphics/ngui/GcNGuiLayer.h>

#include <toolkit/utilities/input/actions/gcinputactions.meta.h>

SKYSCRAPER_BEGIN

enum ePopupType
{
    EPopupType_Chemical,
    EPopupType_HoverStart,
    EPopupType_Technology,
    EPopupType_Discovery,
    EPopupType_DiscoveryItem,
    EPopupType_DiscoverySystemInfo,
    EPopupType_Empty,
    EPopupType_RepairSlot,
    EPopupType_Mission,
    EPopupType_Wiki,
    EPopupType_NetworkPlayer,
    EPopupType_ByteBeat,
    EPopupType_ByteBeatToolTip,
    EPopupType_ByteBeatLibrary,
    EPopupType_Pet,
    EPopupType_SeasonMilestone,
    EPopupType_BuildMenuItem,
    EPopupType_SquadronPilot,
    EPopupType_Build,
    EPopupType_ActionStart,
    EPopupType_Charge,
    EPopupType_Transfer,
    EPopupType_TransferSend,
    EPopupType_BuySell,
    EPopupType_BuySellTech,
    EPopupType_Outfitting,
    EPopupType_ByteBeatSend,
    EPopupType_NumTypes,
};

enum ePopupScreenAdjust
{
    EPopupScreenAdjust_Default,
    EPopupScreenAdjust_AlwaysFit,
    EPopupScreenAdjust_Tooltip,
};

enum ePopupAction : __int32
{
    EPopupAction_None = -1,
    EPopupAction_Transfer,
    EPopupAction_TransferSend,
    EPopupAction_BuildTech,
    EPopupAction_BuildProduct,
    EPopupAction_TechCharge,
    EPopupAction_Repair,
    EPopupAction_Outfitting,
    EPopupAction_ByteBeatSend,
    EPopupAction_NumTypes,
};

class cGcFrontendPopup
{
  public:
    enum ePopupClass
    {
        EPopupClass_Hover,
        EPopupClass_Action,
    };

    enum ePopupState
    {
        EPopupState_Inactive,
        EPopupState_AnimateIn,
        EPopupState_Active,
        EPopupState_AnimateOut,
    };

    ePopupType meType;
    ePopupScreenAdjust meScreenAdjust;
    cGcNGuiLayer mPopup;
    cGcNGuiLayer *mpSlot;
    cGcNGuiLayer *mpHoverSlotParent;
    cGcFrontendPopup::ePopupClass meClass;
    bool mbStayActive;
    bool mbActivatedWithTouch;
    bool mbHasPositionForTouch;
    float mfActiveTime;
    cGcFrontendPopup::ePopupState meState;
    uint8_t meActivatedInventory[4];
    cGcInventoryStore *mpPopupInventory;
    cGcNGuiLayer *mpPressedPopupButtonLayer;
    eInputAction mePressedPopupButtonAction;
    bool mbPressedButonActionCompleted;
};

SKYSCRAPER_END