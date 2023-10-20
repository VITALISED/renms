#pragma once
#include <metadata/metadata_common.h>
enum eBlendOperation
{
    EBlendOperation_Blend = 0,
    EBlendOperation_Add = 1,
}
#include <metadata/animation/blendtree/tkanimvectorblendnodedata.meta.h>

class cTkAnimVectorBlendNode
{
    static unsigned long long muNameHash = 0xCEE7FEFDA2096939;
    static unsigned long long muTemplateHash = 0xB4535ED711FA64FF;

    eBlendOperation BlendOperation;
    cTkDynamicArray<cTkAnimVectorBlendNodeData> maBlendChildren;
}
