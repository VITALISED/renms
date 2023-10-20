#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcspaceshipclasses.meta.h>
#include <metadata/reality/gcinventoryclass.meta.h>

class cGcMissionConditionHasShip
{
    static unsigned long long muNameHash = 0x9511DDC4A0C718D3;
    static unsigned long long muTemplateHash = 0x4377B1D9BF160FD4;

    cGcSpaceshipClasses ShipType;
    cGcInventoryClass ShipInventoryClass;
    bool mbCheckAllShips;
    bool mbBetterClassMatches;
    bool mbDontCheckType;
    bool mbTakeValueFromSeasonData;
}
