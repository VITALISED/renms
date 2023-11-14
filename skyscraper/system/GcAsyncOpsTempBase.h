#pragma once

#include <skyscraper.h>

#include <gamestate/basebuilding/BaseIndex.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cGcAsyncOpsTempBase
{
  public:
    enum ProfanityState
    {
        Unchecked,
        Processing,
        DoneAndProfane,
        DoneAndClean,
    };

    std::atomic<cGcAsyncOpsTempBase::ProfanityState> meBaseNameState;
    std::atomic<cGcAsyncOpsTempBase::ProfanityState> meOwnerNameState;
    BaseIndex muiBaseIndex;
    cTkFixedString<64, char> mOriginalBaseName;
    cTkFixedString<64, char> mOriginalOwnerName;
};

SKYSCRAPER_END