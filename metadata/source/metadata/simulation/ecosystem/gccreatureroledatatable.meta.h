#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureRoleDataTable
{
    static unsigned long long muNameHash = 0xF460B1FDC0499CEA;
    static unsigned long long muTemplateHash = 0x6AF89D990978373;

    cTkDynamicArray<cGcCreatureRoleData> maAvailableRoles;
    float mfMaxProportionFlying;
    bool mbHasSandWorms;
    float mfSandWormFrequency;
}
