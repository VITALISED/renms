#pragma once
#include <metadata/metadata_common.h>
enum eCrime
{
    ECrime_AttackCreature = 0,
    ECrime_AttackSentinel = 1,
    ECrime_AttackSentinelLaser = 2,
    ECrime_KillCreature = 3,
    ECrime_KillSentinel = 4,
    ECrime_MineResources = 5,
    ECrime_HitResources = 6,
    ECrime_AttackSpaceStation = 7,
    ECrime_AttackShip = 8,
    ECrime_AttackPolice = 9,
    ECrime_KillShip = 10,
    ECrime_KillPolice = 11,
    ECrime_TimedShootable = 12,
}

class cGcMessageCrime
{
    static unsigned long long muNameHash = 0xC64AF7F76101CD0;
    static unsigned long long muTemplateHash = 0x6C85ED98FDA49EF4;

    eCrime Crime;
    cTkVector3 mPosition;
    TkHandle mCriminal;
    TkHandle mVictim;
    int miValue;
}
