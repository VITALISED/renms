#pragma once
#include <metadata/metadata_common.h>
enum eStatMessageType
{
    EStatMessageType_Full = 0,
    EStatMessageType_Quick = 1,
    EStatMessageType_Silent = 2,
}
#include <?>
#include <?>

class cGcLeveledStatData
{
    static unsigned long long muNameHash = 0x987EE8E8873AED6B;
    static unsigned long long muTemplateHash = 0x975312EAEE5209F4;

    TkID<128> mStatId;
    TkID<256> mStatTitle;
    eStatMessageType StatMessageType;
    TkID<256> mNotifyMessage;
    TkID<256> mNotifyMessageSingular;
    bool mbShowInTerminal;
    bool mbShowStatLevel;
    cTkTextureResource Icon;
    cTkFixedArray<cGcStatLevelData> maStatLevels;
    bool mbUseRankNotStats;
    bool mbTelemetryUpload;
}
