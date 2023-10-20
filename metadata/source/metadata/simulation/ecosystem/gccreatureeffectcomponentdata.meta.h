#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gccreatureeffecttrigger.meta.h>

class cGcCreatureEffectComponentData
{
    static unsigned long long muNameHash = 0xA0DADC1850532F54;
    static unsigned long long muTemplateHash = 0x110790E1F70E10F5;

    cTkDynamicArray<cGcCreatureEffectTrigger> maAnimTriggers;
}
