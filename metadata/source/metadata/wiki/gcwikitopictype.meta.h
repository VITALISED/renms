#pragma once
#include <metadata/metadata_common.h>
enum eWikiTopicType
{
    EWikiTopicType_Substances = 0,
    EWikiTopicType_CustomSubstanceList = 1,
    EWikiTopicType_Products = 2,
    EWikiTopicType_CustomProductList = 3,
    EWikiTopicType_CustomItemList = 4,
    EWikiTopicType_Technologies = 5,
    EWikiTopicType_CustomTechnologyList = 6,
    EWikiTopicType_BuildableTech = 7,
    EWikiTopicType_Construction = 8,
    EWikiTopicType_TradeCommodities = 9,
    EWikiTopicType_Curiosities = 10,
    EWikiTopicType_Cooking = 11,
    EWikiTopicType_StoneRunes = 12,
    EWikiTopicType_Words = 13,
    EWikiTopicType_RecipesAll = 14,
    EWikiTopicType_RecipesCooker = 15,
    EWikiTopicType_RecipesRefiner1 = 16,
    EWikiTopicType_RecipesRefiner2 = 17,
    EWikiTopicType_RecipesRefiner3 = 18,
    EWikiTopicType_Guide = 19,
    EWikiTopicType_Stories = 20,
    EWikiTopicType_TreasureWonders = 21,
    EWikiTopicType_WeirdBasePartWonders = 22,
    EWikiTopicType_PlanetWonders = 23,
    EWikiTopicType_CreatureWonders = 24,
    EWikiTopicType_FloraWonders = 25,
    EWikiTopicType_MineralWonders = 26,
    EWikiTopicType_CustomWonders = 27,
    EWikiTopicType_DebugSweep = 28,
}

class cGcWikiTopicType
{
    static unsigned long long muNameHash = 0x72439AF10F4C849F;
    static unsigned long long muTemplateHash = 0x89F7B9EF1A67D94F;

    eWikiTopicType WikiTopicType;
}
