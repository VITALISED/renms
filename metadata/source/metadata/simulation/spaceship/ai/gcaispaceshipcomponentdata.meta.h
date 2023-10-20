#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/spaceship/ai/gcaispaceshiptypes.meta.h>
#include <metadata/simulation/gcspaceshipclasses.meta.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>
#include <metadata/tkmodelresource.meta.h>

class cGcAISpaceshipComponentData
{
    static unsigned long long muNameHash = 0x4F5433BCFC028B49;
    static unsigned long long muTemplateHash = 0xC53919B53D4EA93E;

    cGcAISpaceshipTypes Type;
    cGcSpaceshipClasses Class;
    cGcPrimaryAxis Axis;
    cTkModelResource Hangar;
    bool mbIsSpaceAnomaly;
}
