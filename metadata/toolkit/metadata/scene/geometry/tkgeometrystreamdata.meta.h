#pragma once
#include <metadata/metadata_common.h>
#include <metadata/scene/geometry/tkmeshdata.meta.h>

class cTkGeometryStreamData
{
    static unsigned long long muNameHash = 0xA8D08B04A442318C;
    static unsigned long long muTemplateHash = 0xC59E7E150ECDC89B;

    cTkDynamicArray<cTkMeshData> maStreamDataArray;
}
