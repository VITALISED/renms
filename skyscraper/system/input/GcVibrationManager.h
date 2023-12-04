#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkUnorderedMap.h>

#include <user/gctriggerfeedbackstatetable.meta.h>
#include <user/gcvibrationdatatable.meta.h>

SKYSCRAPER_BEGIN

class cGcVibrationChannel : AutoPooled<18>
{
  public:
    struct MotorOutput
    {
        float mfCurrentValue;
        float mfTargetValue;
        float mfTargetRate;
        float mfTargetChangeTime;
        float mfDecayRate;
        float mfMultiplier;
        eCurve meOutputCurve;
        float mfAutoVarianceScale;
        float mfAutoVarianceContrast;
    };

    cGcVibrationChannelData *mpData;
    std::array<cGcVibrationChannel::MotorOutput, 2> mMotorOutputs;
};

class cGcVibrationManager
{
  public:
    struct sTriggerFeedbackStateInstance
    {
        float mfDuration;
        float mfStrengthModifier;
        float mfFrequencyModifier;
        float mfPositionModifier;
    };

    cGcVibrationDataTable *mpVibrationTable;
    cGcVibrationDataTable *mpVibrationOverrideTable;
    cTkUnorderedMap<TkID<128>, cGcVibrationChannel *, TkIDUnorderedMap::Hash128> mIdToChannelMap;
    cGcTriggerFeedbackStateTable *mpTriggerFeedbackTable;
    std::map<cGcTriggerFeedbackState *, cGcVibrationManager::sTriggerFeedbackStateInstance>
        mActiveTriggerFeedbackStates;
};

SKYSCRAPER_END