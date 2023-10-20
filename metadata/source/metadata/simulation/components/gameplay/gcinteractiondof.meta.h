#pragma once
#include <metadata/metadata_common.h>

class cGcInteractionDof
{
    static unsigned long long muNameHash = 0xE4D4852DEDEE280B;
    static unsigned long long muTemplateHash = 0xE00369E1965F75C9;

    bool mbIsEnabled;
    bool mbUseGlobals;
    float mfNearPlaneMin;
    float mfNearPlaneAdjust;
    float mfFarPlane;
    float mfFarFadeDistance;
}
