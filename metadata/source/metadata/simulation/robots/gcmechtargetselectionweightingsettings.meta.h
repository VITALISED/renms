#pragma once
#include <metadata/metadata_common.h>

class cGcMechTargetSelectionWeightingSettings
{
    static unsigned long long muNameHash = 0x5CE6C6E85ABBB6DB;
    static unsigned long long muTemplateHash = 0x88B34845F702A880;

    float mfThreatWeightFactorBase;
    float mfFwdDirectionWeightFactorBase;
    float mfDistanceWeightFactorBase;
    float mfVeryCloseDistance;
    float mfVeryCloseDistanceWeightFactorExponent;
    float mfCloseDistance;
    float mfCloseDistanceWeightFactorExponent;
    float mfMidDistance;
    float mfMidDistanceWeightFactorExponent;
    float mfFarDistance;
    float mfFarDistanceWeightFactorExponent;
    float mfVeryFarDistanceWeightFactorExponent;
}
