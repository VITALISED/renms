#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcProceduralProductData
{
    static unsigned long long muNameHash = 0xC449167C8DE081CD;
    static unsigned long long muTemplateHash = 0x96CA6F8639C9CC2A;

    cGcNameGeneratorWord NameGeneratorBase;
    cTkDynamicArray<cGcProceduralProductWord> maNameGeneratorWordList;
    int miNameGeneratorLegacyRolls;
    cGcProductData Product;
    cTkFixedArray<cGcProductProceduralOnlyData> maProceduralData;
    cGcBiomeList PerBiomeDropWeights;
    cTkFixedString<32,char> macDeployableProductID;
    bool mbRecordsStat;
}
