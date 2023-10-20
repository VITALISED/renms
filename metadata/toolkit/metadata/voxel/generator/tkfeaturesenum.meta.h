#pragma once
#include <metadata/metadata_common.h>
enum eFeatureTypes
{
    EFeatureTypes_River = 0,
    EFeatureTypes_Crater = 1,
    EFeatureTypes_Arches = 2,
    EFeatureTypes_ArchesSmall = 3,
    EFeatureTypes_Blobs = 4,
    EFeatureTypes_BlobsSmall = 5,
    EFeatureTypes_Substance = 6,
}

class cTkFeaturesEnum
{
    static unsigned long long muNameHash = 0x34E815E84B84D42B;
    static unsigned long long muTemplateHash = 0x21B18A160AD77B69;

    eFeatureTypes FeatureTypes;
}
