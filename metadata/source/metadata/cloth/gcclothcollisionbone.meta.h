#pragma once
#include <metadata/metadata_common.h>
#include <metadata/cloth/axisspecification.meta.h>

class cGcClothCollisionBone
{
    static unsigned long long muNameHash = 0x3183C2CA4E0D9600;
    static unsigned long long muTemplateHash = 0x1DC689F860E9E48F;

    bool mbEnabled;
    cTkFixedString<64,char> macDebugName;
    cTkFixedString<64,char> macBoneName;
    cTkVector3 mCapsuleCentre;
    cAxisSpecification CapsuleAxis;
    float mfCapsuleRadius;
    float mfCapsuleLength;
    bool mbImproveCollisionForNarrowCapsule;
}
