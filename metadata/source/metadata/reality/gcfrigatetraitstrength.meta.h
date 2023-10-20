#pragma once
#include <metadata/metadata_common.h>
enum eFrigateTraitStrength
{
    EFrigateTraitStrength_NegativeLarge = 0,
    EFrigateTraitStrength_NegativeMedium = 1,
    EFrigateTraitStrength_NegativeSmall = 2,
    EFrigateTraitStrength_TertiarySmall = 3,
    EFrigateTraitStrength_TertiaryMedium = 4,
    EFrigateTraitStrength_TertiaryLarge = 5,
    EFrigateTraitStrength_SecondarySmall = 6,
    EFrigateTraitStrength_SecondaryMedium = 7,
    EFrigateTraitStrength_SecondaryLarge = 8,
    EFrigateTraitStrength_Primary = 9,
}

class cGcFrigateTraitStrength
{
    static unsigned long long muNameHash = 0x6B6B42D850BF9519;
    static unsigned long long muTemplateHash = 0xB0B0A7490B06DF04;

    eFrigateTraitStrength FrigateTraitStrength;
}
