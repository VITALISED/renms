#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasebuildingpartstyle.meta.h>
#include <metadata/tkmodelresource.meta.h>

class cGcBaseBuildingPartStyleModel
{
    static unsigned long long muNameHash = 0x92F24A976CBF224B;
    static unsigned long long muTemplateHash = 0xB8D71ACB4123A953;

    cGcBaseBuildingPartStyle Style;
    cTkModelResource Model;
    cTkModelResource Inactive;
}
