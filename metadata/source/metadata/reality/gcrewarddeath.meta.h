#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/gamestate/gcseasonsavestateondeath.meta.h>

class cGcRewardDeath
{
    static unsigned long long muNameHash = 0xAF7590464B3BC984;
    static unsigned long long muTemplateHash = 0x1054EE521BB65CEC;

    TkID<128> mPlayerDamage;
    float mfFadeDuration;
    cTkColour mInitialFadeColour;
    cTkCurveType FadeCurve;
    float mfBlackScreenBeforeQuote;
    float mfTimeToSpendDead;
    TkID<256> mDeathQuote;
    TkID<256> mDeathAuthor;
    cGcAudioWwiseEvents AudioEvent;
    cGcSeasonSaveStateOnDeath SetSeasonSaveState;
    bool mbOverrideShipSpin;
    cTkVector2 mDeathSpinRoll;
    cTkVector2 mDeathSpinPitch;
    TkID<128> mCameraShake;
}
