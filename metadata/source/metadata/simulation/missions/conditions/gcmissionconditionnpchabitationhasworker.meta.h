#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eWorkerInCurrentBase
{
    EWorkerInCurrentBase_DontCare = 0,
    EWorkerInCurrentBase_Yes = 1,
    EWorkerInCurrentBase_No = 2,
}

class cGcMissionConditionNPCHabitationHasWorker
{
    static unsigned long long muNameHash = 0x41BFFB2F8544AD51;
    static unsigned long long muTemplateHash = 0x5B414C643A992848;

    cGcNPCHabitationType WorkerType;
    eWorkerInCurrentBase WorkerInCurrentBase;
}
