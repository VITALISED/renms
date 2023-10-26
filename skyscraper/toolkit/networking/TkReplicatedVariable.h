#pragma once

#include <skyscraper.h>
#include <toolkit/networking/TkReplicatedVariableBase.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkReplicatedVariable : cTkReplicatedVariableTemplated<T>
{
	cTkComponent* mpOwner;
};

SKYSCRAPER_END