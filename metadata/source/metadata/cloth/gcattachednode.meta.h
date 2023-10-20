#pragma once
#include <metadata/metadata_common.h>

class cGcAttachedNode
{
    static unsigned long long muNameHash = 0x6F644A9834B845DB;
    static unsigned long long muTemplateHash = 0xCE61FFF81577D8E8;

    bool mbEnabled;
    cTkFixedString<64,char> macNodeName;
    float mfMinRenderIFraction;
    float mfMinRenderJFraction;
    float mfMaxRenderIFraction;
    float mfMaxRenderJFraction;
    float mfBlendStrength;
    cTkVector3 mRelativeTransform_Axis0;
    cTkVector3 mRelativeTransform_Axis1;
    cTkVector3 mRelativeTransform_Axis2;
    cTkVector3 mRelativeTransform_Position;
}
