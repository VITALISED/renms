#pragma once
#include <metadata/metadata_common.h>
enum eDiet
{
    EDiet_Carnivore = 0,
    EDiet_Omnivore = 1,
    EDiet_Herbivore = 2,
    EDiet_Robot = 3,
}

class cGcCreatureDiet
{
    static unsigned long long muNameHash = 0xEF306B43D1C79D7F;
    static unsigned long long muTemplateHash = 0xD8BBB83FF622C3C4;

    eDiet Diet;
}
