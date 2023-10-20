#pragma once
#include <metadata/metadata_common.h>
enum eCharacterControlOutputSpace
{
    ECharacterControlOutputSpace_CameraRelative = 0,
    ECharacterControlOutputSpace_CameraRelativeTopDown = 1,
    ECharacterControlOutputSpace_Raw = 2,
}

class cGcCharacterControlOutputSpace
{
    static unsigned long long muNameHash = 0x17FDBAA75DF0569B;
    static unsigned long long muTemplateHash = 0xFB81DE26A5931326;

    eCharacterControlOutputSpace CharacterControlOutputSpace;
}
