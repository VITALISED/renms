#pragma once
#include <metadata/metadata_common.h>
enum eObjectPlacement
{
    EObjectPlacement_None = 0,
    EObjectPlacement_ResourceSmall = 1,
    EObjectPlacement_ResourceMedium = 2,
    EObjectPlacement_ResourceLarge = 3,
    EObjectPlacement_ResourceDebris = 4,
}

class cGcObjectPlacementCategory
{
    static unsigned long long muNameHash = 0x79F70E3905C45C6D;
    static unsigned long long muTemplateHash = 0xAD8E71D1E344A2D0;

    eObjectPlacement ObjectPlacement;
}
