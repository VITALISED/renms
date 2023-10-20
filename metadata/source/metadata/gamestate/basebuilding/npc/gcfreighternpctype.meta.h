#pragma once
#include <metadata/metadata_common.h>
enum eFreighterNPCType
{
    EFreighterNPCType_SquadronPilot = 0,
    EFreighterNPCType_FrigateCaptain = 1,
    EFreighterNPCType_WorkerBio = 2,
    EFreighterNPCType_WorkerTech = 3,
    EFreighterNPCType_WorkerIndustry = 4,
}

class cGcFreighterNPCType
{
    static unsigned long long muNameHash = 0xC53DA60AB5E3B8A5;
    static unsigned long long muTemplateHash = 0xFB83EA1F426900E2;

    eFreighterNPCType FreighterNPCType;
}
