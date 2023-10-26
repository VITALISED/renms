#pragma once

#include <skyscraper.h>
#include <networking/GcNetworkPlayer.h>

SKYSCRAPER_BEGIN

class cTkReplicatedVariableBase
{
    std::function<bool __cdecl(cGcNetworkPlayer *)> mShouldReplicate;
    bool mbChanged;
};


template <typename T>
class cTkReplicatedVariableTemplated : public cTkReplicatedVariableBase
{
    T mValue;
    std::function<void __cdecl(T const &, T const &)> mOnReceiveChange;
};

SKYSCRAPER_END