#pragma once
#include <metadata/metadata_common.h>
enum eFamilyType
{
    EFamilyType_Replacements = 0,
    EFamilyType_Extras = 1,
}

class cGcBaseBuildingFamily
{
    static unsigned long long muNameHash = 0x80538FB9394B74CA;
    static unsigned long long muTemplateHash = 0xEB9D61CFC45A85BA;

    TkID<128> mID;
    eFamilyType FamilyType;
    cTkDynamicArray<TkID<128>> maObjectIDs;
}
