#pragma once
#include <metadata/metadata_common.h>
enum eExpeditionDuration
{
    EExpeditionDuration_VeryShort = 0,
    EExpeditionDuration_Short = 1,
    EExpeditionDuration_Medium = 2,
    EExpeditionDuration_Long = 3,
    EExpeditionDuration_VeryLong = 4,
}

class cGcExpeditionDuration
{
    static unsigned long long muNameHash = 0x406EA68C88F85056;
    static unsigned long long muTemplateHash = 0x1E8C9B82EF4E5E52;

    eExpeditionDuration ExpeditionDuration;
}
