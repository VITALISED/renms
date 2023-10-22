#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/TkString.h>

SKYSCRAPER_BEGIN

struct LogBookMessage
{
    int miTimeStamp;
    cTkFixedString<128,char> msLogMessage;
};

class cGcPlayerLogBook
{
    cTkVector<LogBookMessage> mPlayerLogs;
};

SKYSCRAPER_END
