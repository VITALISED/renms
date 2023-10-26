#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TkAudioID
{
    const char* mpacName;
    unsigned int muID;
    bool mbValid;
};

struct TkAudioObject
{
    unsigned __int64 mID;
};

SKYSCRAPER_END