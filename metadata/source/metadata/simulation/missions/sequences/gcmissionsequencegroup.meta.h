#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
enum eRepeatLogic
{
    ERepeatLogic_None = 0,
    ERepeatLogic_Loop = 1,
    ERepeatLogic_RestartOnConditionFail = 2,
}
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcMissionSequenceGroup
{
    static unsigned long long muNameHash = 0x51B3554FFBEBED66;
    static unsigned long long muTemplateHash = 0xB370FD96C3A251EC;

    bool mbSilent;
    cTkTextureResource Icon;
    cGcMissionPageHint PageHint;
    TkID<256> mPageDataLocID;
    TkID<128> mBuildMenuHint;
    TkID<128> mInventoryHint;
    cTkFixedString<128,char> macDebugText;
    TkID<256> mObjectiveID;
    TkID<256> mObjectiveTipID;
    bool mbHasCategoryOverride;
    cGcMissionCategory OverrideCategory;
    bool mbHasColourOverride;
    cTkColour mColourOverride;
    bool mbPrefixTitle;
    TkID<256> mPrefixTitleText;
    bool mbBlockPinning;
    cGcMissionConditionTest ConditionTest;
    bool mbHideFromLogIfConditionsMet;
    eRepeatLogic RepeatLogic;
    eIconStyle IconStyle;
    cTkInputEnum SpecialButtonIcon;
    cGcObjectiveTextFormatOptions ObjectiveFormatting;
    cGcTargetMissionSurveyOptions SurveyTarget;
    cGcCustomNotifyTimerOptions CustomNotifyTimers;
    cTkDynamicArray<cTkClassPointer> maConditions;
    cTkDynamicArray<cTkClassPointer> maConsequences;
    cTkDynamicArray<cGcGenericMissionStage> maStages;
}
