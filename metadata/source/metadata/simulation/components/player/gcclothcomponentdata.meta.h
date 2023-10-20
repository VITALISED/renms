#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcClothComponentData
{
    static unsigned long long muNameHash = 0x89A5D7902BDAFE9B;
    static unsigned long long muTemplateHash = 0xBC8BF2EA3F3EEA7F;

    bool mbEnabled;
    int miNumConstraintSolvingIterations;
    cTkDynamicArray<cGcClothPiece> maClothPieces;
    float mfClothScale;
    float mfCollisionScale;
    float mfAttachmentScale;
}
