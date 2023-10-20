#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcClothAttachmentCirlce
{
    static unsigned long long muNameHash = 0xE5DC8328938D3562;
    static unsigned long long muTemplateHash = 0x22A3925ECEBE9AB2;

    bool mbEnabled;
    cTkFixedString<64,char> macDebugName;
    cTkFixedString<64,char> macBoneName;
    float mfRadius;
    cTkVector3 mCenter;
    cAxisSpecification RightAxis;
    cAxisSpecification ForwardAxis;
    cAxisSpecification ClothDirection;
    float mfStartAngle;
    float mfEndAngle;
    bool mbWrapIAround;
    bool mbWrapJAround;
    int miNumRowsOfSameJToFix;
    int miRowToFixJ;
    float mfAttractionStrength;
    float mfAttractionStartDistance;
    float mfStartIFraction;
    float mfEndIFraction;
    float mfJStepDistanceOverride;
}
