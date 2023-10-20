#pragma once
#include <metadata/metadata_common.h>
enum eObjectRenderType
{
    EObjectRenderType_Instanced = 0,
    EObjectRenderType_Single = 1,
}
enum eSizeClass
{
    ESizeClass_Tiny = 0,
    ESizeClass_Small = 1,
    ESizeClass_Medium = 2,
    ESizeClass_Large = 3,
    ESizeClass_Massive = 4,
}
enum eObjectCoverageType
{
    EObjectCoverageType_Blanket = 0,
    EObjectCoverageType_Cluster = 1,
    EObjectCoverageType_Solo = 2,
}

class cGcObjectDefinitionData
{
    static unsigned long long muNameHash = 0xF6BC04E88CDBB164;
    static unsigned long long muTemplateHash = 0xFCD04DEEE7D62DFD;

    cTkFixedString<128,char> macFilename;
    eObjectRenderType ObjectRenderType;
    bool mbAutoCollision;
    bool mbMatchGroundColour;
    eSizeClass SizeClass;
    eObjectCoverageType ObjectCoverageType;
    eLifeType LifeType;
    eLocationType LocationType;
    eObjectAlignment ObjectAlignment;
}
