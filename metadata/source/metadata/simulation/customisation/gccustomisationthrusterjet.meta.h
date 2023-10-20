#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelresource.meta.h>

class cGcCustomisationThrusterJet
{
    static unsigned long long muNameHash = 0x73B8C106776DC488;
    static unsigned long long muTemplateHash = 0xE9DDAD00F059FF0A;

    TkID<128> mLocatorPrefix;
    TkID<128> mEffect;
    cTkModelResource JetMesh;
    cTkModelResource Trail;
}
