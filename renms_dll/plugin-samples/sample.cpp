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

#include <toolkit/data/TkMetaDataClasses.h>
#include <plugins/plugin.h>

#define Signature \
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
    unsigned __int64(* lHashFunction)       (const cTkClassPointer*, ... __int64, bool),\
    void(* lDestroyFunction)                (cTkClassPointer*)

typedef void(*S_cTkMetadataClass)(Signature);

void D_cTkMetadataClass(Signature)
{
    spdlog::info("MetadataScanner: Found class: {}", lpClassMetadata->mName);
}


class MetadataProber : renms::PluginTemplate {
    char* lpacPluginId      = "MetadataProber";
    char* mpacDisplayName   = "Metadata Prober";
    char* mpacAuthor        = "tractorbeam & VITALISED";
    char* mpacDescription   = "Scans the cTkMetadata class's constructor for pointers to all the different classes, because we can.";
    //   V- Hook_etc         V- Signature_etc             V- Detour_etc
    Hook(H_cTkMetadataClass, S_cTkMetadataClass, (LPVOID)(D_cTkMetadataClass), RelToAbsPtr(0x248ABC0))

    void OnLoad() {
        H_cTkMetadataClass.IsEnabled(true);
        spdlog::info("MetadataScanner loaded.");
    }
};