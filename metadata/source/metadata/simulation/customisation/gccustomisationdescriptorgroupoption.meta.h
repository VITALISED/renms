#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/customisation/gccustomisationtexturegroup.meta.h>
#include <metadata/simulation/customisation/gccustomisationcolourgroup.meta.h>
#include <metadata/simulation/customisation/gccustomisationbonescales.meta.h>

class cGcCustomisationDescriptorGroupOption
{
    static unsigned long long muNameHash = 0xA29C133FB960AEB2;
    static unsigned long long muTemplateHash = 0xA4966141B9DA7E53;

    TkID<128> mDescriptorOption;
    cTkDynamicArray<cGcCustomisationTextureGroup> maTextureGroups;
    bool mbReplaceBaseColours;
    cTkDynamicArray<cGcCustomisationColourGroup> maColourGroups;
    bool mbReplaceBaseBoneScales;
    cTkDynamicArray<cGcCustomisationBoneScales> maBoneScales;
    int miInteractionCameraIndexOverride;
    cTkFixedString<32,char> macInteracttionCameraFocusJointOverride;
    cTkDynamicArray<TkID<128>> maHideIfGroupActive;
    cTkDynamicArray<TkID<128>> maSelectingRemovesGroup;
    cTkDynamicArray<TkID<128>> maSelectingAddsGroup;
    cTkDynamicArray<TkID<128>> maUnselectingRemovesGroup;
    cTkDynamicArray<TkID<128>> maUnselectingAddsGroup;
}
