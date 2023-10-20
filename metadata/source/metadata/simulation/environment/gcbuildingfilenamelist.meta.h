#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingfilename.meta.h>

class cGcBuildingFilenameList
{
    static unsigned long long muNameHash = 0xC9E2EEA2B81DBE00;
    static unsigned long long muTemplateHash = 0xDFCDD2DF63DBAF40;

    cTkFixedArray<cGcBuildingFilename> maBuildingFiles;
}
