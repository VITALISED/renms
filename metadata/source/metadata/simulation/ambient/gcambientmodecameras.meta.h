#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcAmbientModeCameras
{
    static unsigned long long muNameHash = 0xAF2F2B2DB8C8446A;
    static unsigned long long muTemplateHash = 0x33FA353B288C9430;

    cTkDynamicArray<cGcCameraAmbientBuildingData> maBuildingCameraAnimations;
    cTkDynamicArray<cGcCameraAmbientSpaceData> maSpaceCameraAnimations;
    cTkDynamicArray<cGcCameraAmbientSpecialData> maSpecialCameraAnimations;
}
