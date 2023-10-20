#pragma once
#include <metadata/metadata_common.h>
enum ePageToOpen
{
    EPageToOpen_FreighterShipTransfer = 0,
    EPageToOpen_DisplayPortalUa = 1,
    EPageToOpen_ExpeditionSelect = 2,
    EPageToOpen_TraderInventory = 3,
    EPageToOpen_ExpeditionDetails = 4,
    EPageToOpen_ExpeditionDebrief = 5,
    EPageToOpen_BuildingPartsShop = 6,
    EPageToOpen_ExocraftShop = 7,
    EPageToOpen_NexusTechShop = 8,
    EPageToOpen_ScrapDealerShop = 9,
    EPageToOpen_BuyShip = 10,
    EPageToOpen_SettlementManagement = 11,
    EPageToOpen_SquadronManagement = 12,
    EPageToOpen_SquadronRecruitment = 13,
    EPageToOpen_FleetManagement = 14,
}

class cGcRewardOpenPage
{
    static unsigned long long muNameHash = 0xF1F483BCEFC0AD13;
    static unsigned long long muTemplateHash = 0xFF551FA54C6FC97E;

    ePageToOpen PageToOpen;
    bool mbReinteractWhenComplete;
}
