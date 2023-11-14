#pragma once

#include <skyscraper.h>

#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cGcLoopingHelper
{
    TkID<128> mPlayOnStart;
    TkID<128> mPlayOnStop;
    TkAudioObject mObject;
    TkAudioID mStartEvent;
    TkAudioID mStopEvent;
    bool mbPlaying;
    bool mbPlayOnce;
    bool mbLocked;
    bool mbHasAudio;
    TkID<128> mAnimToPlay;
};

SKYSCRAPER_END
