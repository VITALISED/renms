#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreatureroles.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturesizeclasses.meta.h>
#include <metadata/simulation/ecosystem/gccreaturegenerationdensity.meta.h>
#include <metadata/simulation/ecosystem/gccreatureactivetime.meta.h>

class cGcCreatureRoleDescription
{
    static unsigned long long muNameHash = 0xA1B4C2EA26DFEA74;
    static unsigned long long muTemplateHash = 0x6875F7793735EEE2;

    cGcCreatureRoles Role;
    cGcCreatureTypes ForceType;
    TkID<128> mForceID;
    TkID<128> mRequireTag;
    cGcCreatureSizeClasses MinSize;
    cGcCreatureSizeClasses MaxSize;
    int miMinGroupSize;
    int miMaxGroupSize;
    cGcCreatureGenerationDensity Density;
    cGcCreatureActiveTime ActiveTime;
    float mfProbabilityOfBeingEnabled;
    float mfIncreasedSpawnDistance;
    TkID<256> mFilter;
}
