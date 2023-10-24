#pragma once

#include <skyscraper.h>
#include <toolkit/networking/TkReplicatedVariableBase.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkReplicatedVariablePlayer : public cTkReplicatedVariableTemplated<cTkUserIdBase<cTkFixedString<64,char> > >
{
    bool mbIsLocallyOwned;
};

SKYSCRAPER_END