#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcgeneratedbasedecorationtemplate.meta.h>
#include <metadata/gamestate/basebuilding/gcgeneratedbaseroomtemplate.meta.h>
#include <metadata/gamestate/basebuilding/gcgeneratedbasethemetemplate.meta.h>
#include <metadata/gamestate/basebuilding/gcgeneratedbasepruningrule.meta.h>

class cGcGeneratedBaseTemplatesTable
{
    static unsigned long long muNameHash = 0x7F0943EC9DBC0BDD;
    static unsigned long long muTemplateHash = 0xE28A64C055994FBA;

    cTkDynamicArray<cGcGeneratedBaseDecorationTemplate> maDecorationTemplates;
    cTkDynamicArray<cGcGeneratedBaseRoomTemplate> maRoomTemplates;
    cTkDynamicArray<cGcGeneratedBaseThemeTemplate> maThemeTemplates;
    cTkDynamicArray<cGcGeneratedBasePruningRule> maPruningRules;
}
