#pragma once
#include <metadata/metadata_common.h>
enum eNavAreaType
{
    ENavAreaType_Normal = 0,
    ENavAreaType_BuildingWithExterior = 1,
    ENavAreaType_Debris = 2,
    ENavAreaType_Ship = 3,
    ENavAreaType_Mech = 4,
    ENavAreaType_PlanetMech = 5,
    ENavAreaType_Demo = 6,
    ENavAreaType_WFCBase = 7,
    ENavAreaType_FreighterBase = 8,
}

class cGcNPCNavigationAreaComponentData
{
    static unsigned long long muNameHash = 0xB4FC959D6A910DEB;
    static unsigned long long muTemplateHash = 0xA0E00875B7A6ABD0;

    eNavAreaType NavAreaType;
    float mfMinRadius;
    float mfMaxRadius;
    float mfSphereCastHeightClearance;
    float mfNeighbourCandidateDistance;
    float mfMaxNeighbourSlope;
    float mfConnectionLengthFactor;
}
