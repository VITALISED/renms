#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturehealthdata.meta.h>
#include <metadata/gameplay/gcdronegun.meta.h>

class cGcDroneComponentData
{
    static unsigned long long muNameHash = 0xE4A9F22B5EB5CBF8;
    static unsigned long long muTemplateHash = 0x5FD10D87A7979DA5;

    TkID<128> mId;
    cGcPrimaryAxis Axis;
    float mfScaler;
    cGcCreatureHealthData Health;
    cTkDynamicArray<TkID<128>> maProjectileChoices;
    cTkDynamicArray<cGcDroneGun> maGuns;
}
