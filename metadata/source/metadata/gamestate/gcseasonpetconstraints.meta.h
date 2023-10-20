#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcSeasonPetConstraints
{
    static unsigned long long muNameHash = 0x154E67C8939691E0;
    static unsigned long long muTemplateHash = 0xFDA422DC68B001D0;

    TkID<128> mCreatureId;
    float mfMinRelativeScale;
    float mfMaxRelativeScale;
    bool mbSpecificBiome;
    cGcBiomeType Biome;
    float mfStartingTrust;
    unsigned long long mui64TimeSinceLastEgg;
    unsigned long long mui64TimeSinceBirth;
}
