#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcAttachmentPointSet
{
    static unsigned long long muNameHash = 0x762F430C6C191529;
    static unsigned long long muTemplateHash = 0xB5DBBE772BEDA04;

    bool mbEnabled;
    cTkFixedString<64,char> macDebugName;
    cTkFixedString<64,char> macBoneName;
    cTkDynamicArray<cGcAttachmentPointData> maFixedPoints;
}
