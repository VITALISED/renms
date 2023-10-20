#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/tkbuttonimagelookup.meta.h>
#include <metadata/utilities/input/tkaxisimagelookup.meta.h>
#include <metadata/utilities/input/tkchordsimagelookup.meta.h>

class cTkControllerSpecification
{
    static unsigned long long muNameHash = 0x5DBD3B5170282610;
    static unsigned long long muTemplateHash = 0x3724BA849DF5AE03;

    TkID<128> mId;
    cTkButtonImageLookup ButtonImageLookup;
    cTkAxisImageLookup AxisImageLookup;
    cTkChordsImageLookup ChordsImageLookup;
}
