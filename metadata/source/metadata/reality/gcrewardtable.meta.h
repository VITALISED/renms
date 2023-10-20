#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcgenericrewardtableentry.meta.h>
#include <metadata/reality/reward/gcrewardtableentitlementitem.meta.h>
#include <metadata/reality/gcrewardtableentry.meta.h>

class cGcRewardTable
{
    static unsigned long long muNameHash = 0x2ECD4E3663FDB26F;
    static unsigned long long muTemplateHash = 0xCF9D3230D28DA639;

    cTkDynamicArray<cGcGenericRewardTableEntry> maGenericTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maDestructionTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maInteractionTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maOldInteractionTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSpecialRewardTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maMissionBoardTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maFleetTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maWikiProgressTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maShipSalvageTable;
    cTkDynamicArray<cGcRewardTableEntitlementItem> maEntitlementTable;
    cTkDynamicArray<cGcRewardTableEntry> maTable;
    cTkDynamicArray<TkID<128>> maTechRewardOrder;
    cTkDynamicArray<TkID<128>> maProductRewardOrder;
    cTkDynamicArray<cGcGenericRewardTableEntry> maMixerRewardTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maTwitchRewardTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maNPCPlanetSiteTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSettlementTable;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable1;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable2;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable3;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable4;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable5;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable6;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable7;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable8;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable9;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable10;
    cTkDynamicArray<cGcGenericRewardTableEntry> maSeasonRewardTable11;
}
