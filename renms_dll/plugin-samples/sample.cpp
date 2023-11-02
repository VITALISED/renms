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

#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>
#include <plugins/plugin.h>

using namespace nms;

#define Signature\
/*  A ptr to the function's own class   */\
    const cTkMetaDataClass* lpClassMetadata,\
/*  Function pointer........................That function's arguments   */\
    void(* lDefaultFunction)                (cTkClassPointer*, cTkLinearMemoryPool*),\
    void(* lFixingFunction)                 (cTkClassPointer*, bool, unsigned __int64),\
    void(* lValidateFunction)               (cTkClassPointer*),\
    void(* lRenderFunction)                 (cTkClassPointer*),\
    bool(* lEqualsFunction)                 (const cTkClassPointer*, const cTkClassPointer*),\
    void(* lCopyFunction)                   (cTkClassPointer*, const cTkClassPointer*),\
    cTkClassPointer* (* lCreateFunction)    (cTkClassPointer* result),\
    unsigned __int64(* lHashFunction)       (const cTkClassPointer*, __int64, bool ...),\
    void(* lDestroyFunction)                (cTkClassPointer*)

typedef void(*S_cTkMetadataClass_Register)(Signature);

void D_cTkMetadataClass_Register(Signature)
{
    spdlog::info("MetadataScanner: Found class: {}", lpClassMetadata->mpacName);
}

class MetadataProber : renms::PluginTemplate {
    public:
    std::string lpacPluginId      = "MetadataProber";
    std::string mpacDisplayName   = "Metadata Prober";
    std::string mpacAuthor        = "tractorbeam & VITALISED";
    std::string mpacDescription   = "Scans the cTkMetadata class's Register function for pointers to all the different classes, because we can.";
    //   V- Hook_etc                  V- Signature_etc                      V- Detour_etc
    HOOK(H_cTkMetadataClass_Register, S_cTkMetadataClass_Register, (LPVOID)(D_cTkMetadataClass_Register), RelToAbsPtr(0x248ABC0))
};

void OnLoad() {
    MetadataProber plugin;
    plugin.H_cTkMetadataClass_Register.IsEnabled(true);
    spdlog::info("MetadataScanner loaded.");
}