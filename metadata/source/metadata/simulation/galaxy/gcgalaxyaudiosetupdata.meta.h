#pragma once
#include <metadata/metadata_common.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/audio/gcaudiowwisertpcs.meta.h>

class cGcGalaxyAudioSetupData
{
    static unsigned long long muNameHash = 0xA3F156D44BBFB2B9;
    static unsigned long long muTemplateHash = 0xCD1747D3733E529B;

    cGcAudioWwiseEvents EventMapEnter;
    cGcAudioWwiseEvents EventMapExit;
    cGcAudioWwiseEvents EventSystemSelect;
    cGcAudioWwiseEvents EventSystemDeselect;
    cGcAudioWwiseEvents EventTextAppear;
    cGcAudioWwiseEvents EventRouteLines;
    cGcAudioWwiseEvents EventAddWaypoint;
    cGcAudioWwiseEvents EventRemoveWaypoint;
    cGcAudioWwiseEvents EventWaypointError;
    cGcAudioWwiseEvents EventWaypointLoop;
    cGcAudioWwiseEvents EventNavmodeChange;
    cGcAudioWwiseEvents EventNavmodeChangeFailed;
    cGcAudioWwiseEvents EventNavmodePathMove;
    cGcAudioWwiseEvents EventPlanetRumble;
    cGcAudioWwiseRTPCs RTPCStarWhoosh;
    float mfWhooshClip;
    float mfWhooshMultiplier;
}
