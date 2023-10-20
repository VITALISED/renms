#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcAntagonistComponentData
{
    static unsigned long long muNameHash = 0xFAE78D5DE55087ED;
    static unsigned long long muTemplateHash = 0xB4F5A3CBC47938A4;

    cGcAntagonistGroup Group;
    float mfScarinessFactor;
    float mfShockedFactor;
    float mfComprehensionFactor;
    float mfCommunicationDelay;
    cTkFixedArray<cGcAntagonistFriend> maFriends;
    cTkFixedArray<cGcAntagonistEnemy> maEnemies;
    cTkDynamicArray<cGcAntagonistPerception> maPerceptions;
}
