#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcDungeonGenerationParams
{
    static unsigned long long muNameHash = 0xFD9E29934900184E;
    static unsigned long long muTemplateHash = 0xAA790A943816F13C;

    unsigned int muiSizeX;
    unsigned int muiSizeY;
    unsigned int muiSizeZ;
    unsigned int muiEntranceX;
    unsigned int muiEntranceY;
    unsigned int muiEntranceZ;
    unsigned int muiRooms;
    float mfXProbability;
    float mfYProbability;
    float mfZProbability;
    float mfStraightMultiplier;
    cTkDynamicArray<cGcDungeonRoomParams> maMainRoomTypes;
    cTkDynamicArray<TkID<128>> maBranchRoomTypes;
    cTkDynamicArray<cGcDungeonQuestParams> maQuests;
    cTkDynamicArray<cTkClassPointer> maGenerationRules;
    cTkDynamicArray<TkID<128>> maPruningRules;
}
