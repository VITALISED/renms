#pragma once
#include <metadata/metadata_common.h>
enum eMissionMarkup
{
    EMissionMarkup_KillFiend = 0,
    EMissionMarkup_KillPirate = 1,
    EMissionMarkup_KillSentinel = 2,
    EMissionMarkup_KillHazardousPlants = 3,
    EMissionMarkup_KillTraders = 4,
    EMissionMarkup_KillCreatures = 5,
    EMissionMarkup_KillPredators = 6,
    EMissionMarkup_KillDepot = 7,
    EMissionMarkup_KillWorms = 8,
    EMissionMarkup_FeedCreature = 9,
    EMissionMarkup_CollectBones = 10,
    EMissionMarkup_CollectScrap = 11,
    EMissionMarkup_Discover = 12,
    EMissionMarkup_CollectSubstanceProduct = 13,
    EMissionMarkup_Build = 14,
    EMissionMarkup_Always = 15,
    EMissionMarkup_None = 16,
}

class cGcStatusMessageMissionMarkup
{
    static unsigned long long muNameHash = 0x8E8EC2C807363E97;
    static unsigned long long muTemplateHash = 0xBE39D03F2CDE8335;

    eMissionMarkup MissionMarkup;
}
