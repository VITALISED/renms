#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tklsystemglobalrestriction.meta.h>
#include <metadata/utilities/data/tklsystemglobalvariation.meta.h>
#include <metadata/utilities/data/tklsystemrule.meta.h>
#include <metadata/utilities/data/tklsystemruletemplate.meta.h>

class cTkLSystemRulesData
{
    static unsigned long long muNameHash = 0x8ECE9ECB68A7E994;
    static unsigned long long muTemplateHash = 0x7BEC79BB9EE655A1;

    cTkDynamicArray<cTkLSystemGlobalRestriction> maGlobalRestriction;
    cTkDynamicArray<cTkLSystemGlobalVariation> maGlobalVariation;
    cTkDynamicArray<cTkLSystemRule> maRules;
    cTkDynamicArray<cTkLSystemRuleTemplate> maTemplates;
}
