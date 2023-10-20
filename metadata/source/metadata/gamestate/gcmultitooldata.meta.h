#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcMultitoolData
{
    static unsigned long long muNameHash = 0x2AF78E5732410B4F;
    static unsigned long long muTemplateHash = 0x8539583BD5C9621B;

    cGcInventoryLayout Layout;
    cGcInventoryContainer Store;
    cTkSeed mSeed;
    cTkFixedString<32,char> macName;
    bool mbIsLarge;
    int miPrimaryMode;
    int miSecondaryMode;
    bool mbUseLegacyColours;
    cGcResourceElement Resource;
}
