#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/networking/TkReplicatedVariableBase.h>

SKYSCRAPER_BEGIN

class cTkReplicatedVariableArray
{
    cTkVector<cTkReplicatedVariableBase *> mapReplicatedVariables;
};

SKYSCRAPER_END