#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureFlockMovementData
{
    static unsigned long long muNameHash = 0xED083CF705C39B97;
    static unsigned long long muTemplateHash = 0xA55A702EC8C6D49F;

    int miMinFlockMembers;
    int miMaxFlockMembers;
    float mfFlockFollow;
    float mfFlockHysteresis;
    float mfFlockCohere;
    float mfFlockSeperate;
    float mfFlockSeperateMinDist;
    float mfFlockSeperateMaxDist;
    float mfFlockAlign;
    float mfFlockAvoidTerrain;
    float mfFlockAvoidTerrainMinDist;
    float mfFlockAvoidTerrainMaxDist;
    float mfFlockAvoidPredators;
    float mfFlockAvoidPredatorsMinDist;
    float mfFlockAvoidPredatorsMaxDist;
    float mfFlockAvoidPredatorsSpeedBoost;
    float mfMoveInFacingStrength;
    float mfFlockMoveSpeed;
    float mfFlockMoveDirectionTime;
    float mfFlockTurnAngle;
    float mfMaxBank;
    float mfBankTime;
    float mfMinFlapSpeed;
    float mfMaxFlapSpeed;
}
