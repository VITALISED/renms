/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <spdlog/spdlog.h>

#include <memory/hooks.h>
#include <plugins/plugin.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>

using namespace nms;

#define SIGNATURE                                                                                                     \
    /*  A ptr to the function's own class   */                                                                        \
    const cTkMetaDataClass *lpClassMetadata, /*  Function pointer........................That function's arguments */ \
        void (*lDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *),                                           \
        void (*lFixingFunction)(cTkClassPointer *, bool, unsigned __int64),                                           \
        void (*lValidateFunction)(cTkClassPointer *), void (*lRenderFunction)(cTkClassPointer *),                     \
        bool (*lEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *),                                    \
        void (*lCopyFunction)(cTkClassPointer *, const cTkClassPointer *),                                            \
        cTkClassPointer *(*lCreateFunction)(cTkClassPointer * result),                                                \
        unsigned __int64 (*lHashFunction)(const cTkClassPointer *, __int64, bool...),                                 \
        void (*lDestroyFunction)(cTkClassPointer *)

typedef void (*cTkMetadataClass_Register_S)(SIGNATURE);

void cTkMetadataClass_Register_D(SIGNATURE)
{
    spdlog::info("MetadataScanner: Found class: {}", lpClassMetadata->mpacName);
}

class MetadataProber : public renms::PluginTemplate
{
  public:
    std::string lpacPluginId    = "MetadataProber";
    std::string mpacDisplayName = "Metadata Prober";
    std::string mpacAuthor      = "tractorbeam & VITALISED";
    std::string mpacDescription =
        "Scans the cTkMetadata class's Register function for pointers to all the different classes, because we can.";
    HOOK(cTkMetadataClass_Register_H, cTkMetadataClass_Register_S, LPVOID(cTkMetadataClass_Register_D),renms::RelToAbsolute(0x248ABC0));
};

void OnLoad()
{
    MetadataProber plugin;
    plugin.cTkMetadataClass_Register_H.IsEnabled(true);
    spdlog::info("MetadataScanner loaded.");
}