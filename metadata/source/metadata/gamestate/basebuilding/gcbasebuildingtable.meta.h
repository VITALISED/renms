#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcBaseBuildingTable
{
    static unsigned long long muNameHash = 0x69B43206529CA591;
    static unsigned long long muTemplateHash = 0x699CA7FB32674596;

    cTkModelResource LegModel;
    cTkModelResource GhostHeart;
    cTkModelResource GhostHeartSelected;
    cTkMaterialResource BuildEffectMaterial;
    cTkModelResource RotateScaleGizmo;
    cTkModelResource WiringFirefly;
    cTkModelResource WiringSnapPoint;
    cTkModelResource WiringSnapSelected;
    cTkDynamicArray<cGcBaseBuildingEntry> maObjects;
    cTkDynamicArray<cGcBaseBuildingGroup> maGroups;
    cTkDynamicArray<cGcBaseBuildingPalette> maPalettes;
    cTkDynamicArray<cGcId256List> maPaletteGroups;
    cTkDynamicArray<cGcBaseBuildingMaterial> maMaterials;
    cTkDynamicArray<cGcId256List> maMaterialGroups;
    cGcBaseBuildingProperties Properties;
    cTkDynamicArray<cGcBaseBuildingFamily> maFamilies;
    cGcBaseBuildingGroup RelativesTabSetupData;
}
