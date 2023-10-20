#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cTkMaterialShaderMillData
{
    static unsigned long long muNameHash = 0xE5F4152C8F8FC861;
    static unsigned long long muTemplateHash = 0xD94EC79A8F14C379;

    cTkDynamicArray<cTkMaterialShaderMillNode> maShaderMillNodes;
    cTkDynamicArray<cTkMaterialShaderMillLink> maShaderMillLinks;
    cTkDynamicArray<cTkMaterialShaderMillFlag> maShaderMillFlags;
    cTkDynamicArray<cTkMaterialShaderMillComment> maShaderMillCmts;
    float mfScrollX;
    float mfScrollY;
    float mfZoom;
    int miOutputX;
    int miOutputY;
}
