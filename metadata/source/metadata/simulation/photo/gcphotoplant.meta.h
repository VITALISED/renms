#pragma once
#include <metadata/metadata_common.h>
enum ePhotoPlantType
{
    EPhotoPlantType_Sodium = 0,
    EPhotoPlantType_Oxygen = 1,
    EPhotoPlantType_BluePlant = 2,
}

class cGcPhotoPlant
{
    static unsigned long long muNameHash = 0xEFC8FCE1F6004590;
    static unsigned long long muTemplateHash = 0xAEC58C1CD705E809;

    ePhotoPlantType PhotoPlantType;
}
