#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcnamegeneratorword.meta.h>
#include <metadata/reality/gcproceduralproductword.meta.h>
#include <metadata/reality/gcproductdata.meta.h>
#include <metadata/reality/gcproductproceduralonlydata.meta.h>
#include <metadata/simulation/solarsystem/planet/gcbiomelist.meta.h>

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
