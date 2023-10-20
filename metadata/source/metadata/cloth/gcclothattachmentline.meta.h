#pragma once
#include <metadata/metadata_common.h>
#include <metadata/cloth/axisspecification.meta.h>

class cGcClothAttachmentLine
{
    static unsigned long long muNameHash = 0x44CED54C76C8DDA0;
    static unsigned long long muTemplateHash = 0x2639E8BCA820BC3C;

    bool mbEnabled;
    cTkFixedString<64,char> macDebugName;
    cTkFixedString<64,char> macBoneName;
    cTkVector3 mStart;
    cTkVector3 mEnd;
    cAxisSpecification ClothDirection;
    int miNumRowsOfSameJToFix;
    int miRowToFixJ;
    float mfAttractionStrength;
    float mfAttractionStartDistance;
    float mfStartIFraction;
    float mfEndIFraction;
    float mfJStepDistanceOverride;
}
