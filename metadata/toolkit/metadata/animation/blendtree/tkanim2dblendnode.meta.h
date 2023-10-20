#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>
enum eCoordinates
{
    ECoordinates_Polar = 0,
    ECoordinates_Cartesian = 1,
}
#include <metadata/animation/blendtree/tkanim2dblendnodedata.meta.h>

class cTkAnim2dBlendNode
{
    static unsigned long long muNameHash = 0xB08E12209E446AC4;
    static unsigned long long muTemplateHash = 0xFF4AD3EEDA81AD59;

    TkID<128> mNodeId;
    cTkFixedString<64,char> macPositionIn;
    float mfPositionRangeBegin;
    float mfPositionRangeEnd;
    float mfPositionSpringTime;
    cTkCurveType PositionCurve;
    eCoordinates Coordinates;
    eBlendOp BlendOp;
    cTkDynamicArray<cTkAnim2dBlendNodeData> maBlendChildren;
}
