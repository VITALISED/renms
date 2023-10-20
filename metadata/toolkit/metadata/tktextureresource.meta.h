#pragma once
#include <metadata/metadata_common.h>

class cTkTextureResource
{
    static unsigned long long muNameHash = 0x2316F23520D820A9;
    static unsigned long long muTemplateHash = 0xE143B09D707BBE56;

    cTkFixedString<128,char> macFilename;
    cTkSmartResHandle mResHandle;
}
