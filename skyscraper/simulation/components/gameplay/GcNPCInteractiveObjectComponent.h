#pragma once

#include <skyscraper.h>

#include <toolkit/simulation/components/TkComponent.h>

#include <simulation/components/gameplay/gcnpcinteractiveobjectcomponentdata.meta.h>

SKYSCRAPER_BEGIN

class cGcNPCInteractiveObjectComponent : cTkComponent
{
    TkHandle mAssociatedBasePartNode;
    cGcNPCInteractiveObjectComponentData *mpData;
};

SKYSCRAPER_END