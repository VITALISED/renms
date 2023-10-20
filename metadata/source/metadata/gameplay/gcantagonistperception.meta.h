#pragma once
#include <metadata/metadata_common.h>
enum eViewShape
{
    EViewShape_Pyramid = 0,
    EViewShape_Cone = 1,
}

class cGcAntagonistPerception
{
    static unsigned long long muNameHash = 0x44D6DFC8A512D8CB;
    static unsigned long long muTemplateHash = 0x8BCCD4CF815D841F;

    TkID<128> mId;
    float mfRange;
    float mfXFOV;
    float mfYFOV;
    eViewShape ViewShape;
    bool mbRaycast;
    cTkFixedString<32,char> macSenseLocator;
}
