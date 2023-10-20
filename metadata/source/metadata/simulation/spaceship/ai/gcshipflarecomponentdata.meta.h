#pragma once
#include <metadata/metadata_common.h>
enum eFlareType
{
    EFlareType_Default = 0,
}

class cGcShipFlareComponentData
{
    static unsigned long long muNameHash = 0xCF633C20574F7F38;
    static unsigned long long muTemplateHash = 0xAC35861E5E356A4C;

    eFlareType FlareType;
}
