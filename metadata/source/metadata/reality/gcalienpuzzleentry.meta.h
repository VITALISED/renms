#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienrace.meta.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/reality/gcalienpuzzlecategory.meta.h>
enum eAdditionalOptions
{
    EAdditionalOptions_None = 0,
    EAdditionalOptions_LearnWord = 1,
    EAdditionalOptions_SayWord = 2,
}
#include <metadata/reality/gcalienpuzzleoption.meta.h>
#include <metadata/reality/gcalienmood.meta.h>
#include <metadata/simulation/ecosystem/npcs/gcnpcproptype.meta.h>
#include <metadata/reality/gcpuzzletextflow.meta.h>
enum ePersistancyBufferOverride
{
    EPersistancyBufferOverride_None = 0,
    EPersistancyBufferOverride_AlwaysPersonal = 1,
    EPersistancyBufferOverride_AlwaysFireteam = 2,
}
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcAlienPuzzleEntry
{
    static unsigned long long muNameHash = 0xDE1F17CE7E01A8C2;
    static unsigned long long muTemplateHash = 0x7922B45DF52C43C3;

    int miProgressionIndex;
    int miMinProgressionForSelection;
    TkID<256> mId;
    cGcAlienRace Race;
    cGcInteractionType Type;
    cGcAlienPuzzleCategory Category;
    eAdditionalOptions AdditionalOptions;
    TkID<256> mTitle;
    TkID<256> mText;
    TkID<256> mTextAlien;
    bool mbTranslateAlienText;
    bool mbTranslationBrackets;
    bool mbProgressiveDialogue;
    TkID<256> mRequiresScanEvent;
    cTkDynamicArray<cGcAlienPuzzleOption> maOptions;
    cTkDynamicArray<TkID<256>> maAdditionalText;
    cTkDynamicArray<TkID<256>> maAdditionalTextAlien;
    cGcAlienMood Mood;
    cGcNPCPropType Prop;
    cTkDynamicArray<cGcPuzzleTextFlow> maAdvancedInteractionFlow;
    ePersistancyBufferOverride PersistancyBufferOverride;
    int miCustomFreighterTextIndex;
    bool mbRadialInteraction;
    cGcAudioWwiseEvents NextStageAudioEventOverride;
}
