#pragma once
#include <metadata/metadata_common.h>
enum eGcStatEnum
{
    EGcStatEnum_None = 0,
    EGcStatEnum_DEPOTS_BROKEN = 1,
    EGcStatEnum_FPODS_BROKEN = 2,
    EGcStatEnum_PLANTS_PLANTED = 3,
    EGcStatEnum_SALVAGE_LOOTED = 4,
    EGcStatEnum_TREASURE_FOUND = 5,
    EGcStatEnum_QUADS_KILLED = 6,
    EGcStatEnum_WALKERS_KILLED = 7,
    EGcStatEnum_FLORA_KILLED = 8,
    EGcStatEnum_PLANTS_GATHERED = 9,
    EGcStatEnum_BONES_FOUND = 10,
    EGcStatEnum_C_SENT_KILLS = 11,
    EGcStatEnum_STORM_CRYSTALS = 12,
    EGcStatEnum_BURIED_PROPS = 13,
    EGcStatEnum_MINIWORM_KILL = 14,
    EGcStatEnum_POOP_COLLECTED = 15,
    EGcStatEnum_GRAVBALLS = 16,
    EGcStatEnum_EGG_PODS = 17,
}

class cGcStatsEnum
{
    static unsigned long long muNameHash = 0xACDE6E8DA19EC2E2;
    static unsigned long long muTemplateHash = 0xA5C5AEF74A763E5;

    eGcStatEnum GcStatEnum;
}
