/**
 * @file GcFrontendPageEnum.h
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

SKYSCRAPER_BEGIN

enum eFrontendPage
{
    EFrontendPage_None = -1,
    EFrontendPage_Suit,
    EFrontendPage_Ship,
    EFrontendPage_Vehicle,
    EFrontendPage_Freighter,
    EFrontendPage_Weapon,
    EFrontendPage_Discovery,
    EFrontendPage_Journey,
    EFrontendPage_MissionLog,
    EFrontendPage_Wiki,
    EFrontendPage_Catalogue,
    EFrontendPage_InfoPortal,
    EFrontendPage_Season,
    EFrontendPage_Options,
    EFrontendPage_Switcher,
    EFrontendPage_Controls,
    EFrontendPage_Network,
    EFrontendPage_NetworkPlayers,
    EFrontendPage_NetworkManageFriends,
    EFrontendPage_NetworkManageBlocked,
    EFrontendPage_Difficulty,
    EFrontendPage_Credits,
    EFrontendPage_Redeem,
    EFrontendPage_Interact,
    EFrontendPage_InteractDialog,
    EFrontendPage_InteractConsole,
    EFrontendPage_InteractShip,
    EFrontendPage_Trade,
    EFrontendPage_TechTrade,
    EFrontendPage_BuildingTrade,
    EFrontendPage_SpecialsTrade,
    EFrontendPage_MissionList,
    EFrontendPage_MissionHandInList,
    EFrontendPage_MissionRenounce,
    EFrontendPage_MissionDescription,
    EFrontendPage_BuyScreen,
    EFrontendPage_CompareScreen,
    EFrontendPage_DisplayTech,
    EFrontendPage_DisplayProduct,
    EFrontendPage_DisplayPatchNotes,
    EFrontendPage_FreighterTransferScreen,
    EFrontendPage_InventoryTransferScreen,
    EFrontendPage_Message,
    EFrontendPage_PhotoMode,
    EFrontendPage_ReportBase,
    EFrontendPage_PhotoBaseForUpload,
    EFrontendPage_BaseUpload,
    EFrontendPage_BasePartsMenu,
    EFrontendPage_BasePartPalette,
    EFrontendPage_Popup,
    EFrontendPage_Maintenance,
    EFrontendPage_Portal,
    EFrontendPage_PortalRunes,
    EFrontendPage_PortalActivate,
    EFrontendPage_PortalUaDisplay,
    EFrontendPage_Refiner,
    EFrontendPage_SystemHoover,
    EFrontendPage_EggMachine,
    EFrontendPage_VehicleRace,
    EFrontendPage_ManageFleet,
    EFrontendPage_ManageExpeditions,
    EFrontendPage_ExpeditionDebrief,
    EFrontendPage_FrigateDetails,
    EFrontendPage_FrigateCaptain,
    EFrontendPage_ExpeditionDetails,
    EFrontendPage_ExpeditionSelection,
    EFrontendPage_ExpeditionOutfitting,
    EFrontendPage_Customisation,
    EFrontendPage_Teleporter,
    EFrontendPage_Teleporter_Nexus,
    EFrontendPage_ByteBeat,
    EFrontendPage_BaseGridPart,
    EFrontendPage_UnlockItemTree,
    EFrontendPage_CreatureFeeder,
    EFrontendPage_CreatureHarvester,
    EFrontendPage_Multiplayer_MissionList,
    EFrontendPage_Multiplayer_MissionDescription,
    EFrontendPage_CraftingTree,
    EFrontendPage_ByteBeatSwitch,
    EFrontendPage_RadialInteraction,
    EFrontendPage_Pet,
    EFrontendPage_IntermediateInteraction,
    EFrontendPage_ByteBeatLibrary,
    EFrontendPage_SettlementHub,
    EFrontendPage_SettlementJudgement,
    EFrontendPage_RocketLockerInventory,
    EFrontendPage_SquadronRecruitment,
    EFrontendPage_SquadronManagement,
    EFrontendPage_SquadronPilotDetails,
    EFrontendPage_NumPages,
};

SKYSCRAPER_END