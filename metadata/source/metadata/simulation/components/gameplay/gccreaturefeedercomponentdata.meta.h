#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureFeederComponentData
{
    static unsigned long long muNameHash = 0x32441F8B4528DF91;
    static unsigned long long muTemplateHash = 0x3861907A552DE380;

    cGcMaintenanceComponentData MaintenanceData;
    int miNumInputs;
    int miNumMealsPerBait;
    cTkDynamicArray<cTkFixedString<256,char>> maDispenseNodes;
    float mfDispenseVelocity;
    float mfDispensePeriod;
}
