#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cTkSceneNodeData
{
    static unsigned long long muNameHash = 0x2C1B6B0E807F7193;
    static unsigned long long muTemplateHash = 0x1DCCBBEBB4547EB4;

    cTkFixedString<128,char> macName;
    unsigned int muiNameHash;
    TkID<128> mType;
    cTkTransformData Transform;
    cTkDynamicArray<cTkSceneNodeAttributeData> maAttributes;
    cTkDynamicArray<cTkSceneNodeData> maChildren;
}
