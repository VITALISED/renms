#pragma once
#include <metadata/metadata_common.h>
enum eActionSetType
{
    EActionSetType_None = 0,
    EActionSetType_FRONTEND = 1,
    EActionSetType_OnFootControls = 2,
    EActionSetType_OnFootQuickMenu = 3,
    EActionSetType_ShipControls = 4,
    EActionSetType_ShipQuickMenu = 5,
    EActionSetType_VehicleMode = 6,
    EActionSetType_GalacticMap = 7,
    EActionSetType_PhotoModeMenu = 8,
    EActionSetType_PhotoModeMvCam = 9,
    EActionSetType_AmbientMode = 10,
    EActionSetType_DebugMode = 11,
    EActionSetType_BuildMenuAnalogueRotate = 12,
    EActionSetType_TextChat = 13,
    EActionSetType_BuildMenuSelectionMode = 14,
    EActionSetType_BuildMenuPlacementMode = 15,
}

class cGcActionSetType
{
    static unsigned long long muNameHash = 0x99FB64404DAF2DE7;
    static unsigned long long muTemplateHash = 0x6B1AA41A13BF3652;

    eActionSetType ActionSetType;
}
