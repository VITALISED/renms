#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/gcspaceshipclasses.meta.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiproles.meta.h>
#include <metadata/reality/gcfrigateclass.meta.h>

class cGcAISpaceshipModelData
{
    static unsigned long long muNameHash = 0xA1AD260BA61A04EE;
    static unsigned long long muTemplateHash = 0x530ECCF351373B52;

    cTkFixedString<128,char> macFilename;
    cGcSpaceshipClasses Class;
    cGcAISpaceshipRoles AIRole;
    cGcFrigateClass FrigateClass;
}
