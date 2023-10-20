#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBaseGridSearchFilter
{
    static unsigned long long muNameHash = 0xA4186DCC6FC21A11;
    static unsigned long long muTemplateHash = 0x502237C1EE9366E8;

    cGcLinkNetworkTypes NetworkType;
    int miPartRateIsGreaterThan;
    int miPartRateIsLessThan;
    int miGridRateIsGreaterThan;
    int miGridRateIsLessThan;
    bool mbGridHasANegativeRate;
    bool mbGridHasAPositiveRate;
    bool mbGridIsOnline;
    bool mbGridIsNotOnline;
    int miGridHasMinParts;
    int miGridHasMaxParts;
    int miGridHasMinNonPassiveParts;
    int miGridHasMaxNonPassiveParts;
    bool mbGridHasPositiveRatePotential;
}
