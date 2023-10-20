#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eDependsOnEnvironment
{
    EDependsOnEnvironment_None = 0,
    EDependsOnEnvironment_DayNight = 1,
    EDependsOnEnvironment_Storms = 2,
}
#include <?>

class cGcBaseLinkGridData
{
    static unsigned long long muNameHash = 0x3FBB55C99E667F9E;
    static unsigned long long muTemplateHash = 0xE8F66D1290EEC0E7;

    cGcBaseLinkGridConnectionData Connection;
    int miRate;
    int miStorage;
    eDependsOnEnvironment DependsOnEnvironment;
    eDependsOnHotspots DependsOnHotspots;
    cTkDynamicArray<cGcBaseLinkGridConnectionDependency> maDependentConnections;
}
