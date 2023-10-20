#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcantagonistgroup.meta.h>
#include <metadata/gameplay/gcantagonistfriend.meta.h>
#include <metadata/gameplay/gcantagonistenemy.meta.h>
#include <metadata/gameplay/gcantagonistperception.meta.h>

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
