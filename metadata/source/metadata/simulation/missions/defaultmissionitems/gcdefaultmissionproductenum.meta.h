#pragma once
#include <metadata/metadata_common.h>
enum eDefaultProductType
{
    EDefaultProductType_None = 0,
    EDefaultProductType_PrimaryProduct = 1,
    EDefaultProductType_SecondaryProduct = 2,
}

class cGcDefaultMissionProductEnum
{
    static unsigned long long muNameHash = 0x20AE1E70418EDA80;
    static unsigned long long muTemplateHash = 0x666451205CCD88E3;

    eDefaultProductType DefaultProductType;
}
