#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbaselinkgridconnectiondata.meta.h>
enum eDependsOnEnvironment
{
    EDependsOnEnvironment_None = 0,
    EDependsOnEnvironment_DayNight = 1,
    EDependsOnEnvironment_Storms = 2,
}
enum eDependsOnHotspots
{
    EDependsOnHotspots_None = 0,
    EDependsOnHotspots_Power = 1,
    EDependsOnHotspots_Mineral = 2,
    EDependsOnHotspots_Gas = 3,
}
#include <metadata/gamestate/basebuilding/gcbaselinkgridconnectiondependency.meta.h>

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
