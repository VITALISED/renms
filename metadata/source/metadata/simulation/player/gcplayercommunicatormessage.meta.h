#pragma once
#include <metadata/metadata_common.h>
enum eCommunicatorType
{
    ECommunicatorType_HoloExplorer = 0,
    ECommunicatorType_HoloSceptic = 1,
    ECommunicatorType_HoloNoone = 2,
    ECommunicatorType_Generic = 3,
    ECommunicatorType_PlayerFreighterCaptain = 4,
    ECommunicatorType_Polo = 5,
    ECommunicatorType_Nada = 6,
    ECommunicatorType_QuicksilverBot = 7,
    ECommunicatorType_PlayerSettlementResident = 8,
    ECommunicatorType_CargoScanDrone = 9,
    ECommunicatorType_Tethys = 10,
}
#include <?>

class cGcPlayerCommunicatorMessage
{
    static unsigned long long muNameHash = 0xF839343C27983F1A;
    static unsigned long long muTemplateHash = 0x1974CA6D4B99B386;

    TkID<256> mDialog;
    bool mbShowHologram;
    eCommunicatorType CommunicatorType;
    cGcAlienRace RaceOverride;
    TkID<256> mShipHUDOverride;
}
