#pragma once
#include <metadata/metadata_common.h>
enum eExpeditionCategory
{
    EExpeditionCategory_Combat = 0,
    EExpeditionCategory_Exploration = 1,
    EExpeditionCategory_Mining = 2,
    EExpeditionCategory_Diplomacy = 3,
    EExpeditionCategory_Balanced = 4,
}

class cGcExpeditionCategory
{
    static unsigned long long muNameHash = 0x4F6C65318BF17139;
    static unsigned long long muTemplateHash = 0xE40903D9360CA39C;

    eExpeditionCategory ExpeditionCategory;
}
