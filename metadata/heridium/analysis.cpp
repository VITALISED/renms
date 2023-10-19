#include "analysis.h"
#include <memory/hooks.h>

INIT_HOOK()

void RegisterHook(const cTkMetaDataClass* lpClassMetadata,
    void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
    void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
    void(* lValidateFunction)(cTkClassPointer*),
    void(* lRenderFunction)(cTkClassPointer*),
    bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
    void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
    cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
    unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
    void(* lDestroyFunction)(cTkClassPointer*))
{
    typedef void(*HOOK_TYPE)(
        const cTkMetaDataClass* lpClassMetadata,
        void(* lDefaultFunction)(cTkClassPointer*, cTkLinearMemoryPool*),
        void(* lFixingFunction)(cTkClassPointer*, bool, unsigned __int64),
        void(* lValidateFunction)(cTkClassPointer*),
        void(* lRenderFunction)(cTkClassPointer*),
        bool(* lEqualsFunction)(const cTkClassPointer*, const cTkClassPointer*),
        void(* lCopyFunction)(cTkClassPointer*, const cTkClassPointer*),
        cTkClassPointer* (* lCreateFunction)(cTkClassPointer* result),
        unsigned __int64(* lHashFunction)(const cTkClassPointer*, unsigned __int64, bool),
        void(* lDestroyFunction)(cTkClassPointer*)
        );

    CALL_ORIGINAL(cTkMetaData::Register, lpClassMetadata, lDefaultFunction, lFixingFunction, lValidateFunction, lRenderFunction, lEqualsFunction, lCopyFunction, lCreateFunction, lHashFunction, lDestroyFunction);
}

MH_STATUS DISPATCH_HOOK()
{
    HOOK(OFFSET(0x248ABC0), RegisterHook, cTkMetaData::Register);

    return HOOK_STATUS();
}

void AnalysisInit()
{
    if(DISPATCH_HOOK() == MH_OK)
    {
        spdlog::info("Analysis starting");
    }
}

// HERIDIUM_BEGIN

// void DoLookupIter()
// {
//     typedef cTkMetaDataFunctionLookup*(*__cTkMetaData__GetLookup__)(const unsigned __int64 luiNameHash);

//     for(std::pair<const char*, const char*> items : classPaths)
//     {
//         std::string fullName = items.first;
//     }
// }

// uintptr_t UnpackClassPointerWriteFunc(LPVOID ClassPointerWriteFunction)
// {
//     //Get the call to Cast() from the Write function
//     uintptr_t castCallInstruction = (uintptr_t)ClassPointerWriteFunction + 0x11;
//     LPVOID castPtr = renms::RelToAbsolute(castCallInstruction);

//     // return address of what's in the mov call in Cast()
//     uintptr_t hashAddr = (uintptr_t)castPtr + 0xC;

//     return hashAddr;
// }

// HERIDIUM_END