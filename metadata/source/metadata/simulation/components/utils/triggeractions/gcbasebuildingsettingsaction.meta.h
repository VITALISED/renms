#pragma once
#include <metadata/metadata_common.h>
enum eUseCorePartsOnly
{
    EUseCorePartsOnly_False = 0,
    EUseCorePartsOnly_True = 1,
    EUseCorePartsOnly_DontCare = 2,
}
#include <metadata/enginesettings/tkgraphicsdetailtypes.meta.h>

class cGcBaseBuildingSettingsAction
{
    static unsigned long long muNameHash = 0x1250AC356CE3B7B;
    static unsigned long long muTemplateHash = 0xB7932103D79C6EBB;

    eUseCorePartsOnly UseCorePartsOnly;
    cTkGraphicsDetailTypes MaxAffectedDetail;
}
