#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcCustomisationGroup
{
    static unsigned long long muNameHash = 0xB5A01AE676FD46D;
    static unsigned long long muTemplateHash = 0x867D5B3F13938F63;

    TkID<128> mGroupID;
    TkID<256> mGroupTitle;
    bool mbIsBannerGroup;
    bool mbForceShowAllColourOptions;
    cGcCustomisationCameraData CameraData;
    cTkDynamicArray<cGcCustomisationDescriptorGroupOptions> maDescriptorOptions;
    cTkDynamicArray<cGcCustomisationTextureGroup> maTextureGroups;
    cTkDynamicArray<cGcCustomisationColourGroup> maColourGroups;
    cTkDynamicArray<cGcCustomisationBoneScales> maBoneScales;
}
