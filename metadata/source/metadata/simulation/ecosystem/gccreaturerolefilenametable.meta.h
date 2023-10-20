#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureRoleFilenameTable
{
    static unsigned long long muNameHash = 0x15A053481CA45D03;
    static unsigned long long muTemplateHash = 0x7B0FAF5D4550E94B;

    cTkFixedArray<cGcCreatureRoleFilenameList> maBiomeFiles;
    cGcCreatureRoleFilenameList UnderwaterFiles;
    cGcCreatureRoleFilenameList UnderwaterFilesExtra;
    cGcCreatureRoleFilenameList CaveFiles;
    cGcCreatureRoleFilenameList AirFiles;
    cGcCreatureRoleFilenameList RobotFiles;
    cTkFixedArray<cGcCreatureRoleFilenameList> maWeirdBiomeFiles;
    cTkFixedArray<float> maLifeChance;
    cTkFixedArray<float> maRoleFrequencyModifiers;
}
