#pragma once
#include <metadata/metadata_common.h>
enum eTriggerType
{
    ETriggerType_Disabled = 0,
    ETriggerType_Interrupt = 1,
    ETriggerType_RunParallel = 2,
    ETriggerType_Blocked = 3,
    ETriggerType_QueueLatest = 4,
    ETriggerType_QueueAll = 5,
}
#include <?>

class cTkSketchNodeData
{
    static unsigned long long muNameHash = 0x34A0F43E0ECB3765;
    static unsigned long long muTemplateHash = 0x42A7CE67E1CAAAA6;

    cTkFixedString<32,char> macTypeName;
    eTriggerType TriggerType;
    int miSelectedVariant;
    int miPositionX;
    int miPositionY;
    cTkDynamicArray<cTkSketchNodeConnections> maConnections;
    cTkDynamicArray<unsigned char> maCustomData;
}
