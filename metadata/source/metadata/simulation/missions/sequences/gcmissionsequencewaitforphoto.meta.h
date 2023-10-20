#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcMissionSequenceWaitForPhoto
{
    static unsigned long long muNameHash = 0x2EB82866D685EFBF;
    static unsigned long long muTemplateHash = 0xEB0CC38D5B31E41;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macMessageSecondary;
    cTkFixedString<128,char> macMessageSuccess;
    cTkDynamicArray<cGcBiomeType> maBiomes;
    cTkDynamicArray<cGcPhotoFauna> maFauna;
    cTkDynamicArray<cGcPhotoFlora> maFlora;
    cTkDynamicArray<cGcPhotoBuildings> maBuildings;
    bool mbTakeAmountFromSeasonData;
    cTkFixedString<128,char> macDebugText;
}
