#pragma once
#include <metadata/metadata_common.h>
enum eMatchNodeType
{
    EMatchNodeType_Any = 0,
    EMatchNodeType_Mesh = 1,
    EMatchNodeType_Model = 2,
    EMatchNodeType_Joint = 3,
}

class cGcModelExplosionRule
{
    static unsigned long long muNameHash = 0xA63D153E45037707;
    static unsigned long long muTemplateHash = 0xF632B2B1C66A9F6A;

    eMatchNodeType MatchNodeType;
    eMatchName MatchName;
    cTkFixedString<32,char> macString;
    eExplodeAction ExplodeAction;
    cTkVector3 mAxisMultiplier;
    cTkVector3 mOffset;
    float mfExplodeMod;
}
