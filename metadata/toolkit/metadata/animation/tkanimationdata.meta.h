#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eAnimType
{
    EAnimType_Loop = 0,
    EAnimType_OneShot = 1,
    EAnimType_Control = 2,
    EAnimType_OneShotBlendable = 3,
}

class cTkAnimationData
{
    static unsigned long long muNameHash = 0x3A0F3C26A4978A6F;
    static unsigned long long muTemplateHash = 0x2B3F7ACFE888523E;

    TkID<128> mAnim;
    TkID<128> mAdditiveBaseAnim;
    cTkFixedString<128,char> macFilename;
    cTkFixedString<64,char> macStartNode;
    cTkDynamicArray<cTkFixedString<64,char>> maExtraStartNodes;
    cTkAnimationGameData GameData;
    int miFrameStart;
    int miFrameEnd;
    int miPriority;
    float mfOffsetMin;
    float mfOffsetMax;
    float mfDelay;
    float mfSpeed;
    float mfActionStartFrame;
    float mfActionFrame;
    float mfAdditiveBaseFrame;
    eAnimType AnimType;
    eCreatureSize CreatureSize;
    bool mbAdditive;
    bool mbMirrored;
    bool mbActive;
    bool mbHas30HzFrames;
}
