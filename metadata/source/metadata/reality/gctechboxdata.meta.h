#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcTechBoxData
{
    static unsigned long long muNameHash = 0x3839C255F197D92C;
    static unsigned long long muTemplateHash = 0xED863C113D36079B;

    TkID<128> mProductID;
    TkID<128> mInstallTechID;
    cTkTextureResource Icon;
    bool mbIsAlien;
}
