#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eDecorationLayer
{
    EDecorationLayer_Stairs = 0,
    EDecorationLayer_Corridor = 1,
    EDecorationLayer_Room = 2,
    EDecorationLayer_Door = 3,
    EDecorationLayer_Decoration1 = 4,
    EDecorationLayer_Decoration2 = 5,
    EDecorationLayer_Decoration3 = 6,
    EDecorationLayer_DecorationCorridor = 7,
}

class cGcGeneratedBaseDecorationTemplate
{
    static unsigned long long muNameHash = 0x6370110DC5DC47D2;
    static unsigned long long muTemplateHash = 0x320EC0C308ECA15C;

    TkID<128> mId;
    cTkModelResource TemplateScene;
    float mfProbability;
    int miMaxPerRoom;
    eDecorationLayer DecorationLayer;
    cTkDynamicArray<int> maInvalidRoomIndexes;
}
