#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienmood.meta.h>
enum eTranslateAlienTextOverride
{
    ETranslateAlienTextOverride_None = 0,
    ETranslateAlienTextOverride_Translate = 1,
    ETranslateAlienTextOverride_DoNotTranslate = 2,
}
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcPuzzleTextFlow
{
    static unsigned long long muNameHash = 0x44CB81CE83D73B16;
    static unsigned long long muTemplateHash = 0x6322BA74C87A2DBB;

    TkID<256> mText;
    bool mbIsAlien;
    TkID<256> mTitle;
    cGcAlienMood Mood;
    eTranslateAlienTextOverride TranslateAlienTextOverride;
    eBracketsOverride BracketsOverride;
    cGcAudioWwiseEvents AudioEvent;
    bool mbShowHologram;
}
