#include <iat/fios.h>

// FIXME: this file is a horror

//----------------------------sceFiosFHGetSize

uint64_t sceFiosFHGetSize__TRAMPOLINE = NULL;

SceFiosSize WINAPI sceFiosFHGetSize__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosFHGetSize__TRAMPOLINE, sceFiosFHGetSize__DETOUR)(lFH);
}

PLH::IatHook sceFiosFHGetSize__HOOK(
    "libSceFios2.dll", "sceFiosFHGetSize", reinterpret_cast<uint64_t>(sceFiosFHGetSize__DETOUR),
    &sceFiosFHGetSize__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosIOFilterAdd

uint64_t sceFiosIOFilterAdd__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosIOFilterAdd__DETOUR(int unk1, uintptr_t lpIOFilter, SceFiosFilterContext *lpRamCacheContext)
{
    return PLH::FnCast(sceFiosIOFilterAdd__TRAMPOLINE, sceFiosIOFilterAdd__DETOUR)(unk1, lpIOFilter, lpRamCacheContext);
}

PLH::IatHook sceFiosIOFilterAdd__HOOK(
    "libSceFios2.dll", "sceFiosIOFilterAdd", reinterpret_cast<uint64_t>(sceFiosIOFilterAdd__DETOUR),
    &sceFiosIOFilterAdd__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosInitialize

uint64_t sceFiosInitialize__TRAMPOLINE = NULL;

void WINAPI sceFiosInitialize__DETOUR(SceFiosParams lParams)
{
    spdlog::info("sceFiosInitialize: Initializing sceFios");
    return PLH::FnCast(sceFiosInitialize__TRAMPOLINE, sceFiosInitialize__DETOUR)(lParams);
}

PLH::IatHook sceFiosInitialize__HOOK(
    "libSceFios2.dll", "sceFiosInitialize", reinterpret_cast<uint64_t>(sceFiosInitialize__DETOUR),
    &sceFiosInitialize__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosIsValidHandle

uint64_t sceFiosIsValidHandle__TRAMPOLINE = NULL;

bool WINAPI sceFiosIsValidHandle__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosIsValidHandle__TRAMPOLINE, sceFiosIsValidHandle__DETOUR)(lFH);
}

PLH::IatHook sceFiosIsValidHandle__HOOK(
    "libSceFios2.dll", "sceFiosIsValidHandle", reinterpret_cast<uint64_t>(sceFiosIsValidHandle__DETOUR),
    &sceFiosIsValidHandle__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFileGetSizeSync

uint64_t sceFiosFileGetSizeSync__TRAMPOLINE = NULL;

SceFiosSize WINAPI sceFiosFileGetSizeSync__DETOUR(uint64_t lAttr, const char *lpacFilename)
{
    return PLH::FnCast(sceFiosFileGetSizeSync__TRAMPOLINE, sceFiosFileGetSizeSync__DETOUR)(lAttr, lpacFilename);
}

PLH::IatHook sceFiosFileGetSizeSync__HOOK(
    "libSceFios2.dll", "sceFiosFileGetSizeSync", reinterpret_cast<uint64_t>(sceFiosFileGetSizeSync__DETOUR),
    &sceFiosFileGetSizeSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosCachePrefetchFileSync

uint64_t sceFiosCachePrefetchFileSync__TRAMPOLINE = NULL;

__int64 WINAPI sceFiosCachePrefetchFileSync__DETOUR(uint64_t lAttr, const char *lpacFilename)
{
    return PLH::FnCast(sceFiosCachePrefetchFileSync__TRAMPOLINE, sceFiosCachePrefetchFileSync__DETOUR)(
        lAttr, lpacFilename);
}

PLH::IatHook sceFiosCachePrefetchFileSync__HOOK(
    "libSceFios2.dll", "sceFiosCachePrefetchFileSync", reinterpret_cast<uint64_t>(sceFiosCachePrefetchFileSync__DETOUR),
    &sceFiosCachePrefetchFileSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosExistsSync

uint64_t sceFiosExistsSync__TRAMPOLINE = NULL;

__int64 WINAPI sceFiosExistsSync__DETOUR(uint64_t lAttr, const char *lpacFilename)
{
    return PLH::FnCast(sceFiosExistsSync__TRAMPOLINE, sceFiosExistsSync__DETOUR)(lAttr, lpacFilename);
}

PLH::IatHook sceFiosExistsSync__HOOK(
    "libSceFios2.dll", "sceFiosExistsSync", reinterpret_cast<uint64_t>(sceFiosExistsSync__DETOUR),
    &sceFiosExistsSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFileRead

uint64_t sceFiosFileRead__TRAMPOLINE = NULL;

__int64 WINAPI sceFiosFileRead__DETOUR(
    uint64_t lAttr, const char *lpacFilename, void *lpData, SceFiosSize liSize, SceFiosOffset liOffset)
{
    spdlog::trace("sceFiosFileRead: Reading File: {}", lpacFilename);

    for (std::pair<std::string, std::pair<void *, uint64_t>> lOverride : renms::config::aModFileOverrides)
    {
        if (std::filesystem::path(lOverride.first).compare(lpacFilename) == 0)
        {
            spdlog::info("Overriding File {}", lOverride.first);
        }
    }

    return PLH::FnCast(sceFiosFileRead__TRAMPOLINE, sceFiosFileRead__DETOUR)(
        lAttr, lpacFilename, lpData, liSize, liOffset);
}

PLH::IatHook sceFiosFileRead__HOOK(
    "libSceFios2.dll", "sceFiosFileRead", reinterpret_cast<uint64_t>(sceFiosFileRead__DETOUR),
    &sceFiosFileRead__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosArchiveMountSync

uint64_t sceFiosArchiveMountSync__TRAMPOLINE = NULL;

__int64 WINAPI sceFiosArchiveMountSync__DETOUR(
    const void *attr, SceFiosFH *fh, const char *path, const char *mount_point, SceFiosBuffer mount_buffer,
    void *params)
{
    spdlog::info("sceFiosArchiveMountSync: Mounting Archive: {}{}", mount_point, path);

    return PLH::FnCast(sceFiosArchiveMountSync__TRAMPOLINE, sceFiosArchiveMountSync__DETOUR)(
        attr, fh, path, mount_point, mount_buffer, params);
}

PLH::IatHook sceFiosArchiveMountSync__HOOK(
    "libSceFios2.dll", "sceFiosArchiveMountSync", reinterpret_cast<uint64_t>(sceFiosArchiveMountSync__DETOUR),
    &sceFiosArchiveMountSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosArchiveGetMountBufferSizeSync

uint64_t sceFiosArchiveGetMountBufferSizeSync__TRAMPOLINE = NULL;

SceFiosSize WINAPI sceFiosArchiveGetMountBufferSizeSync__DETOUR(uint64_t unk1, const char *lpacFilename, uint64_t unk2)
{
    return PLH::FnCast(sceFiosArchiveGetMountBufferSizeSync__TRAMPOLINE, sceFiosArchiveGetMountBufferSizeSync__DETOUR)(
        unk1, lpacFilename, unk2);
}

PLH::IatHook sceFiosArchiveGetMountBufferSizeSync__HOOK(
    "libSceFios2.dll", "sceFiosArchiveGetMountBufferSizeSync",
    reinterpret_cast<uint64_t>(sceFiosArchiveGetMountBufferSizeSync__DETOUR),
    &sceFiosArchiveGetMountBufferSizeSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFileReadSync

uint64_t sceFiosFileReadSync__TRAMPOLINE = NULL;

void WINAPI
sceFiosFileReadSync__DETOUR(__int64 unk1, const char *lpacFilename, void *lpData, __int64 unk2, SceFiosOffset liOffset)
{
    spdlog::trace("sceFiosFileReadSync: Reading file: {}", lpacFilename);

    return PLH::FnCast(sceFiosFileReadSync__TRAMPOLINE, sceFiosFileReadSync__DETOUR)(
        unk1, lpacFilename, lpData, unk2, liOffset);
}

PLH::IatHook sceFiosFileReadSync__HOOK(
    "libSceFios2.dll", "sceFiosFileReadSync", reinterpret_cast<uint64_t>(sceFiosFileReadSync__DETOUR),
    &sceFiosFileReadSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosOpGetError

uint64_t sceFiosOpGetError__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosOpGetError__DETOUR(uint64_t unk1)
{
    return PLH::FnCast(sceFiosOpGetError__TRAMPOLINE, sceFiosOpGetError__DETOUR)(unk1);
}

PLH::IatHook sceFiosOpGetError__HOOK(
    "libSceFios2.dll", "sceFiosOpGetError", reinterpret_cast<uint64_t>(sceFiosOpGetError__DETOUR),
    &sceFiosOpGetError__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosOpDelete

uint64_t sceFiosOpDelete__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosOpDelete__DETOUR(uint64_t unk1)
{
    return PLH::FnCast(sceFiosOpDelete__TRAMPOLINE, sceFiosOpDelete__DETOUR)(unk1);
}

PLH::IatHook sceFiosOpDelete__HOOK(
    "libSceFios2.dll", "sceFiosOpDelete", reinterpret_cast<uint64_t>(sceFiosOpDelete__DETOUR),
    &sceFiosOpDelete__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosOpWait

uint64_t sceFiosOpWait__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosOpWait__DETOUR(uint64_t unk1)
{
    return PLH::FnCast(sceFiosOpWait__TRAMPOLINE, sceFiosOpWait__DETOUR)(unk1);
}

PLH::IatHook sceFiosOpWait__HOOK(
    "libSceFios2.dll", "sceFiosOpWait", reinterpret_cast<uint64_t>(sceFiosOpWait__DETOUR), &sceFiosOpWait__TRAMPOLINE,
    L"NMS.exe");

//----------------------------sceFiosDHCloseSync

uint64_t sceFiosDHCloseSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosDHCloseSync__DETOUR(uint64_t unk1, unsigned int unk2)
{
    return PLH::FnCast(sceFiosDHCloseSync__TRAMPOLINE, sceFiosDHCloseSync__DETOUR)(unk1, unk2);
}

PLH::IatHook sceFiosDHCloseSync__HOOK(
    "libSceFios2.dll", "sceFiosDHCloseSync", reinterpret_cast<uint64_t>(sceFiosDHCloseSync__DETOUR),
    &sceFiosDHCloseSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosDHReadSync

uint64_t sceFiosDHReadSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosDHReadSync__DETOUR(uint64_t unk1, unsigned int unk2)
{
    return PLH::FnCast(sceFiosDHReadSync__TRAMPOLINE, sceFiosDHReadSync__DETOUR)(unk1, unk2);
}

PLH::IatHook sceFiosDHReadSync__HOOK(
    "libSceFios2.dll", "sceFiosDHReadSync", reinterpret_cast<uint64_t>(sceFiosDHReadSync__DETOUR),
    &sceFiosDHReadSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosDHOpenSync

uint64_t sceFiosDHOpenSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosDHOpenSync__DETOUR(uint64_t unk1, uint64_t unk2, const char *lpacArchiveRoot, void *lpData)
{
    spdlog::info("sceFiosDHOpenSync: Loading Archive Directory: {}", lpacArchiveRoot);
    return PLH::FnCast(sceFiosDHOpenSync__TRAMPOLINE, sceFiosDHOpenSync__DETOUR)(unk1, unk2, lpacArchiveRoot, lpData);
}

PLH::IatHook sceFiosDHOpenSync__HOOK(
    "libSceFios2.dll", "sceFiosDHOpenSync", reinterpret_cast<uint64_t>(sceFiosDHOpenSync__DETOUR),
    &sceFiosDHOpenSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosDHOpen

uint64_t sceFiosDHOpen__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosDHOpen__DETOUR(uint64_t unk1, uint64_t unk2, const char *lpacArchiveRoot, void *lpData)
{
    spdlog::info("sceFiosDHOpen: Loading Archive Directory: {}", lpacArchiveRoot);

    return PLH::FnCast(sceFiosDHOpen__TRAMPOLINE, sceFiosDHOpen__DETOUR)(unk1, unk2, lpacArchiveRoot, lpData);
}

PLH::IatHook sceFiosDHOpen__HOOK(
    "libSceFios2.dll", "sceFiosDHOpen", reinterpret_cast<uint64_t>(sceFiosDHOpen__DETOUR), &sceFiosDHOpen__TRAMPOLINE,
    L"NMS.exe");

//----------------------------sceFiosOpGetActualCount

uint64_t sceFiosOpGetActualCount__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosOpGetActualCount__DETOUR(unsigned int unk1)
{
    return PLH::FnCast(sceFiosOpGetActualCount__TRAMPOLINE, sceFiosOpGetActualCount__DETOUR)(unk1);
}

PLH::IatHook sceFiosOpGetActualCount__HOOK(
    "libSceFios2.dll", "sceFiosOpGetActualCount", reinterpret_cast<uint64_t>(sceFiosOpGetActualCount__DETOUR),
    &sceFiosOpGetActualCount__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFHGetPath

uint64_t sceFiosFHGetPath__TRAMPOLINE = NULL;

const char *WINAPI sceFiosFHGetPath__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosFHGetPath__TRAMPOLINE, sceFiosFHGetPath__DETOUR)(lFH);
}

PLH::IatHook sceFiosFHGetPath__HOOK(
    "libSceFios2.dll", "sceFiosFHGetPath", reinterpret_cast<uint64_t>(sceFiosFHGetPath__DETOUR),
    &sceFiosFHGetPath__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFHTell

uint64_t sceFiosFHTell__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHTell__DETOUR(SceFiosHandle lFH)
{
    return PLH::FnCast(sceFiosFHTell__TRAMPOLINE, sceFiosFHTell__DETOUR)(lFH);
}

PLH::IatHook sceFiosFHTell__HOOK(
    "libSceFios2.dll", "sceFiosFHTell", reinterpret_cast<uint64_t>(sceFiosFHTell__DETOUR), &sceFiosFHTell__TRAMPOLINE,
    L"NMS.exe");

//----------------------------sceFiosFHSeek

uint64_t sceFiosFHSeek__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHSeek__DETOUR(SceFiosHandle lFH, uint64_t lpStart, uint64_t lpEnd)
{
    return PLH::FnCast(sceFiosFHSeek__TRAMPOLINE, sceFiosFHSeek__DETOUR)(lFH, lpStart, lpEnd);
}

PLH::IatHook sceFiosFHSeek__HOOK(
    "libSceFios2.dll", "sceFiosFHSeek", reinterpret_cast<uint64_t>(sceFiosFHSeek__DETOUR), &sceFiosFHSeek__TRAMPOLINE,
    L"NMS.exe");

//----------------------------sceFiosFHCloseSync

uint64_t sceFiosFHCloseSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHCloseSync__DETOUR(__int64 unk1, SceFiosHandle lFh)
{
    return PLH::FnCast(sceFiosFHCloseSync__TRAMPOLINE, sceFiosFHCloseSync__DETOUR)(unk1, lFh);
}

PLH::IatHook sceFiosFHCloseSync__HOOK(
    "libSceFios2.dll", "sceFiosFHCloseSync", reinterpret_cast<uint64_t>(sceFiosFHCloseSync__DETOUR),
    &sceFiosFHCloseSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFHWriteSync

uint64_t sceFiosFHWriteSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHWriteSync__DETOUR(uint64_t unk1, SceFiosHandle lFh, void *lpData, uint64_t liSize)
{
    return PLH::FnCast(sceFiosFHWriteSync__TRAMPOLINE, sceFiosFHWriteSync__DETOUR)(unk1, lFh, lpData, liSize);
}

PLH::IatHook sceFiosFHWriteSync__HOOK(
    "libSceFios2.dll", "sceFiosFHWriteSync", reinterpret_cast<uint64_t>(sceFiosFHWriteSync__DETOUR),
    &sceFiosFHWriteSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFHReadSync

uint64_t sceFiosFHReadSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHReadSync__DETOUR(uint64_t unk1, SceFiosHandle lFh, void *lpData, uint64_t liSize)
{
    return PLH::FnCast(sceFiosFHReadSync__TRAMPOLINE, sceFiosFHReadSync__DETOUR)(unk1, lFh, lpData, liSize);
}

PLH::IatHook sceFiosFHReadSync__HOOK(
    "libSceFios2.dll", "sceFiosFHReadSync", reinterpret_cast<uint64_t>(sceFiosFHReadSync__DETOUR),
    &sceFiosFHReadSync__TRAMPOLINE, L"NMS.exe");

//----------------------------sceFiosFHOpenSync

uint64_t sceFiosFHOpenSync__TRAMPOLINE = NULL;

uint64_t WINAPI sceFiosFHOpenSync__DETOUR(uint64_t unk1, uint64_t unk2, const char *lpacFilename, uint64_t unk3)
{
    return PLH::FnCast(sceFiosFHOpenSync__TRAMPOLINE, sceFiosFHOpenSync__DETOUR)(unk1, unk2, lpacFilename, unk3);
}

PLH::IatHook sceFiosFHOpenSync__HOOK(
    "libSceFios2.dll", "sceFiosFHOpenSync", reinterpret_cast<uint64_t>(sceFiosFHOpenSync__DETOUR),
    &sceFiosFHOpenSync__TRAMPOLINE, L"NMS.exe");

RENMS_BEGIN

void CreateFiosHooks()
{
    sceFiosFHGetSize__HOOK.hook();
    sceFiosIOFilterAdd__HOOK.hook();
    sceFiosInitialize__HOOK.hook();
    sceFiosIsValidHandle__HOOK.hook();
    sceFiosFileGetSizeSync__HOOK.hook();
    sceFiosCachePrefetchFileSync__HOOK.hook();
    sceFiosExistsSync__HOOK.hook();
    sceFiosFileRead__HOOK.hook();
    sceFiosArchiveMountSync__HOOK.hook();
    sceFiosArchiveGetMountBufferSizeSync__HOOK.hook();
    sceFiosFileReadSync__HOOK.hook();
    sceFiosOpGetError__HOOK.hook();
    sceFiosOpDelete__HOOK.hook();
    sceFiosOpWait__HOOK.hook();
    sceFiosDHCloseSync__HOOK.hook();
    sceFiosDHReadSync__HOOK.hook();
    sceFiosDHOpenSync__HOOK.hook();
    sceFiosDHOpen__HOOK.hook();
    sceFiosOpGetActualCount__HOOK.hook();
    sceFiosFHTell__HOOK.hook();
    sceFiosFHSeek__HOOK.hook();
    sceFiosFHCloseSync__HOOK.hook();
    sceFiosFHWriteSync__HOOK.hook();
    sceFiosFHReadSync__HOOK.hook();
    sceFiosFHOpenSync__HOOK.hook();
}

RENMS_END