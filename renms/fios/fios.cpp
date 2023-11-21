#include <fios/fios.h>

//----------------------------sceFiosFHGetSize

RENMS_IAT_HOOK(
    sceFiosFHGetSize, "libSceFios2.dll", SceFiosSize __stdcall,
    (SceFiosHandle lFH) { return RENMS_CAST(sceFiosFHGetSize, lFH); });

//----------------------------sceFiosIOFilterAdd

RENMS_IAT_HOOK(
    sceFiosIOFilterAdd, "libSceFios2.dll", uint64_t __stdcall,
    (int unk1, uintptr_t lpIOFilter, SceFiosFilterContext *lpRamCacheContext) {
        return RENMS_CAST(sceFiosIOFilterAdd, unk1, lpIOFilter, lpRamCacheContext);
    });

//----------------------------sceFiosInitialize

RENMS_IAT_HOOK(
    sceFiosInitialize, "libSceFios2.dll", void __stdcall, (SceFiosParams lParams) {
        spdlog::info("sceFiosInitialize: Initializing sceFios");
        return RENMS_CAST(sceFiosInitialize, lParams);
    });

//----------------------------sceFiosIsValidHandle

RENMS_IAT_HOOK(
    sceFiosIsValidHandle, "libSceFios2.dll", uint64_t __stdcall,
    (SceFiosHandle lFH) { return RENMS_CAST(sceFiosIsValidHandle, lFH); });

//----------------------------sceFiosFileGetSizeSync

RENMS_IAT_HOOK(
    sceFiosFileGetSizeSync, "libSceFios2.dll", SceFiosSize __stdcall,
    (uint64_t lAttr, const char *lpacFilename) { return RENMS_CAST(sceFiosFileGetSizeSync, lAttr, lpacFilename); });

//----------------------------sceFiosCachePrefetchFileSync

RENMS_IAT_HOOK(
    sceFiosCachePrefetchFileSync, "libSceFios2.dll", uint64_t __stdcall, (uint64_t lAttr, const char *lpacFilename) {
        return RENMS_CAST(sceFiosCachePrefetchFileSync, lAttr, lpacFilename);
    });

//----------------------------sceFiosExistsSync

RENMS_IAT_HOOK(
    sceFiosExistsSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t lAttr, const char *lpacFilename) { return RENMS_CAST(sceFiosExistsSync, lAttr, lpacFilename); });

//----------------------------sceFiosFileRead

RENMS_IAT_HOOK(
    sceFiosFileRead, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t lAttr, const char *lpacFilename, void *lpData, SceFiosSize liSize, SceFiosOffset liOffset) {
        spdlog::trace("sceFiosFileRead: Reading File: {}", lpacFilename);

        return RENMS_CAST(sceFiosFileRead, lAttr, lpacFilename, lpData, liSize, liOffset);
    });

//----------------------------sceFiosArchiveMountSync

RENMS_IAT_HOOK(
    sceFiosArchiveMountSync, "libSceFios2.dll", uint64_t __stdcall,
    (const void *attr, SceFiosFH *fh, const char *path, const char *mount_point, SceFiosBuffer mount_buffer,
     void *params) {
        spdlog::info("sceFiosArchiveMountSync: Mounting Archive: {}{}", mount_point, path);

        return RENMS_CAST(sceFiosArchiveMountSync, attr, fh, path, mount_point, mount_buffer, params);
    });

//----------------------------sceFiosArchiveGetMountBufferSizeSync

RENMS_IAT_HOOK(
    sceFiosArchiveGetMountBufferSizeSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, const char *lpacFilename, uint64_t unk2) {
        return RENMS_CAST(sceFiosArchiveGetMountBufferSizeSync, unk1, lpacFilename, unk2);
    });

//----------------------------sceFiosFileReadSync

RENMS_IAT_HOOK(
    sceFiosFileReadSync, "libSceFios2.dll", void __stdcall,
    (uint64_t unk1, const char *lpacFilename, void *lpData, uint64_t unk2, SceFiosOffset liOffset) {
        spdlog::trace("sceFiosFileReadSync: Reading file: {}", lpacFilename);

        return RENMS_CAST(sceFiosFileReadSync, unk1, lpacFilename, lpData, unk2, liOffset);
    });

//----------------------------sceFiosOpGetError

RENMS_IAT_HOOK(
    sceFiosOpGetError, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1) { return RENMS_CAST(sceFiosOpGetError, unk1); });

//----------------------------sceFiosOpDelete

RENMS_IAT_HOOK(
    sceFiosOpDelete, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1) { return RENMS_CAST(sceFiosOpDelete, unk1); });

//----------------------------sceFiosOpWait

RENMS_IAT_HOOK(
    sceFiosOpWait, "libSceFios2.dll", uint64_t __stdcall, (uint64_t unk1) { return RENMS_CAST(sceFiosOpWait, unk1); });

//----------------------------sceFiosDHCloseSync

RENMS_IAT_HOOK(
    sceFiosDHCloseSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, unsigned int unk2) { return RENMS_CAST(sceFiosDHCloseSync, unk1, unk2); });

//----------------------------sceFiosDHReadSync

RENMS_IAT_HOOK(
    sceFiosDHReadSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, unsigned int unk2) { return RENMS_CAST(sceFiosDHReadSync, unk1, unk2); });

//----------------------------sceFiosDHOpenSync

RENMS_IAT_HOOK(
    sceFiosDHOpenSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, uint64_t unk2, const char *lpacArchiveRoot, void *lpData) {
        spdlog::info("sceFiosDHOpenSync: Loading Archive Directory: {}", lpacArchiveRoot);
        return RENMS_CAST(sceFiosDHOpenSync, unk1, unk2, lpacArchiveRoot, lpData);
    });

//----------------------------sceFiosDHOpen

RENMS_IAT_HOOK(
    sceFiosDHOpen, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, uint64_t unk2, const char *lpacArchiveRoot, void *lpData) {
        spdlog::info("sceFiosDHOpen: Loading Archive Directory: {}", lpacArchiveRoot);

        return RENMS_CAST(sceFiosDHOpen, unk1, unk2, lpacArchiveRoot, lpData);
    });

//----------------------------sceFiosOpGetActualCount

RENMS_IAT_HOOK(
    sceFiosOpGetActualCount, "libSceFios2.dll", uint64_t __stdcall,
    (unsigned int unk1) { return RENMS_CAST(sceFiosOpGetActualCount, unk1); });

//----------------------------sceFiosFHGetPath

RENMS_IAT_HOOK(
    sceFiosFHGetPath, "libSceFios2.dll", const char *__stdcall,
    (SceFiosHandle lFH) { return RENMS_CAST(sceFiosFHGetPath, lFH); });

//----------------------------sceFiosFHTell

RENMS_IAT_HOOK(
    sceFiosFHTell, "libSceFios2.dll", uint64_t __stdcall,
    (SceFiosHandle lFH) { return RENMS_CAST(sceFiosFHTell, lFH); });

//----------------------------sceFiosFHSeek

RENMS_IAT_HOOK(
    sceFiosFHSeek, "libSceFios2.dll", uint64_t __stdcall,
    (SceFiosHandle lFH, uint64_t lpStart, uint64_t lpEnd) { return RENMS_CAST(sceFiosFHSeek, lFH, lpStart, lpEnd); });

//----------------------------sceFiosFHCloseSync

RENMS_IAT_HOOK(
    sceFiosFHCloseSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, SceFiosHandle lFh) { return RENMS_CAST(sceFiosFHCloseSync, unk1, lFh); });

//----------------------------sceFiosFHWriteSync

RENMS_IAT_HOOK(
    sceFiosFHWriteSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, SceFiosHandle lFh, void *lpData, uint64_t liSize) {
        return RENMS_CAST(sceFiosFHWriteSync, unk1, lFh, lpData, liSize);
    });

//----------------------------sceFiosFHReadSync

RENMS_IAT_HOOK(
    sceFiosFHReadSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, SceFiosHandle lFh, void *lpData, uint64_t liSize) {
        return RENMS_CAST(sceFiosFHReadSync, unk1, lFh, lpData, liSize);
    });

//----------------------------sceFiosFHOpenSync

RENMS_IAT_HOOK(
    sceFiosFHOpenSync, "libSceFios2.dll", uint64_t __stdcall,
    (uint64_t unk1, uint64_t unk2, const char *lpacFilename, uint64_t unk3) {
        return PLH::FnCast(sceFiosFHOpenSync__TRAMPOLINE, sceFiosFHOpenSync__DETOUR)(unk1, unk2, lpacFilename, unk3);
    });

RENMS_BEGIN

void CreateFiosHooks()
{
    RENMS_DISPATCH_HOOK(sceFiosFHGetSize);
    RENMS_DISPATCH_HOOK(sceFiosIOFilterAdd);
    RENMS_DISPATCH_HOOK(sceFiosInitialize);
    RENMS_DISPATCH_HOOK(sceFiosIsValidHandle);
    RENMS_DISPATCH_HOOK(sceFiosFileGetSizeSync);
    RENMS_DISPATCH_HOOK(sceFiosCachePrefetchFileSync);
    RENMS_DISPATCH_HOOK(sceFiosExistsSync);
    RENMS_DISPATCH_HOOK(sceFiosFileRead);
    RENMS_DISPATCH_HOOK(sceFiosArchiveMountSync);
    RENMS_DISPATCH_HOOK(sceFiosArchiveGetMountBufferSizeSync);
    RENMS_DISPATCH_HOOK(sceFiosFileReadSync);
    RENMS_DISPATCH_HOOK(sceFiosOpGetError);
    RENMS_DISPATCH_HOOK(sceFiosOpDelete);
    RENMS_DISPATCH_HOOK(sceFiosOpWait);
    RENMS_DISPATCH_HOOK(sceFiosDHCloseSync);
    RENMS_DISPATCH_HOOK(sceFiosDHReadSync);
    RENMS_DISPATCH_HOOK(sceFiosDHOpenSync);
    RENMS_DISPATCH_HOOK(sceFiosDHOpen);
    RENMS_DISPATCH_HOOK(sceFiosOpGetActualCount);
    RENMS_DISPATCH_HOOK(sceFiosFHTell);
    RENMS_DISPATCH_HOOK(sceFiosFHSeek);
    RENMS_DISPATCH_HOOK(sceFiosFHCloseSync);
    RENMS_DISPATCH_HOOK(sceFiosFHWriteSync);
    RENMS_DISPATCH_HOOK(sceFiosFHReadSync);
    RENMS_DISPATCH_HOOK(sceFiosFHOpenSync);
}

RENMS_END