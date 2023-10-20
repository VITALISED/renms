#pragma once
#include <metadata/metadata_common.h>

class cGcModSettingsInfo
{
    static unsigned long long muNameHash = 0xC0CE6220E5E98BD9;
    static unsigned long long muTemplateHash = 0xF658C5CC0A4A78DE;

    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macAuthor;
    unsigned long long mui64ID;
    unsigned long long mui64AuthorID;
    unsigned long long mui64LastUpdated;
    unsigned short muiLoadOrder;
    bool mbEnabled;
    bool mbEnabledVR;
    cTkDynamicArray<unsigned long long> maDependencies;
}
