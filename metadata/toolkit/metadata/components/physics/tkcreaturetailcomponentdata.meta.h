#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkCreatureTailComponentData
{
    static unsigned long long muNameHash = 0x787641F134B1AFBD;
    static unsigned long long muTemplateHash = 0x38F8BA7B7D94CFC6;

    cGcPrimaryAxis LengthAxis;
    bool mbCanUseDefaultParams;
    cTkCreatureTailParams DefaultParams;
    cTkDynamicArray<cTkCreatureTailParams> maParamVariations;
}
