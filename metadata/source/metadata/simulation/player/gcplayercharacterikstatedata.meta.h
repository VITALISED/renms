#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPlayerCharacterIKStateData
{
    static unsigned long long muNameHash = 0x4D3FB3BF1BEB7DAE;
    static unsigned long long muTemplateHash = 0x42ECAED236415D8B;

    cGcPlayerCharacterStateType State;
    cGcPlayerCharacterIKOverrideData Data;
    cTkDynamicArray<cGcPlayerCharacterAnimationOverrideData> maAnimOverrides;
}
