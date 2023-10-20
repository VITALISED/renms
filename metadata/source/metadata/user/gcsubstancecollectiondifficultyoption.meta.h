#pragma once
#include <metadata/metadata_common.h>
enum eSubstanceCollectionDifficulty
{
    ESubstanceCollectionDifficulty_High = 0,
    ESubstanceCollectionDifficulty_Normal = 1,
    ESubstanceCollectionDifficulty_Low = 2,
}

class cGcSubstanceCollectionDifficultyOption
{
    static unsigned long long muNameHash = 0x685F577065EC8459;
    static unsigned long long muTemplateHash = 0x7356FAF37859706E;

    eSubstanceCollectionDifficulty SubstanceCollectionDifficulty;
}
