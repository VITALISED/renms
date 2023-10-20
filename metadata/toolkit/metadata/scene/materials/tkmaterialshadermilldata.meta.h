#pragma once
#include <metadata/metadata_common.h>
#include <metadata/scene/materials/tkmaterialshadermillnode.meta.h>
#include <metadata/scene/materials/tkmaterialshadermilllink.meta.h>
#include <metadata/scene/materials/tkmaterialshadermillflag.meta.h>
#include <metadata/scene/materials/tkmaterialshadermillcomment.meta.h>

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
