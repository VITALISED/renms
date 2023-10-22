#pragma once

#include <skyscraper.h>
#include <simulation/player/GcPlayer.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

class cGcNetworkSerializer
{
    typedef cGcPlayer::eRocketBootsDoubleTapState CurrentAction;

    unsigned __int8 *macBuffer;
    unsigned int muCurrentBit;
    unsigned int muLastFinishedBit;
    unsigned int muBufferSize;
    unsigned int muCurrentReadWriteByte;
    cGcNetworkSerializer::CurrentAction meCurrentAction;
    cTkFixedString<64,char> mSenderId;
};

SKYSCRAPER_END