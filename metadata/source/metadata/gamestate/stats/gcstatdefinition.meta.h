#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcStatDefinition
{
    static unsigned long long muNameHash = 0xC70BF0DB96EC45A3;
    static unsigned long long muTemplateHash = 0xC7EB0E264D2085A6;

    cGcStatType Type;
    cGcStatTrackType TrackType;
    cGcStatDisplayType DisplayType;
    cGcStatValueData DefaultValue;
    TkID<128> mId;
    bool mbTelemetryUpload;
    bool mbIsProgression;
    int miMissionMessageDecimals;
}
