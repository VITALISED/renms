// im not an osx user, this is just idk test moment or something based on random garbage information that might not even
// be correct. If you know what you're doing please fix this and get it to work for goodness sake

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <vector>

#define NMS_IMAGE_NAME "No Man's Sky" // I don't actually know what it's called lol

uintptr_t *thingy_ptr     = nullptr;
uintptr_t thingy_original = NULL;

struct cTkBankInfo
{
    char msPath[256];
    unsigned __int64 mLength;
};

struct TheData
{
    char guh[0x2AF0];
}

typedef void (*cTkFileSystem__Construct)(TheData **thiscall);
typedef __int64 (*sceFiosFileGetSizeSync)(uintptr_t attrs_ptr, const char *file);
typedef std::vector<cTkBankInfo> *(*cTkFileSystem__Data__EnumerateBanks)(
    uintptr_t thiscall, std::vector<cTkBankInfo> *result, const char *lArchiveRoot);

void __cTkFileSystem__Construct__(TheData **thiscall)
{
    // ideally call original first, then the hook
    cTkFileSystem__Construct original = reinterpret_cast<cTkFileSystem__Construct>(thingy_original);
    original(thiscall);

    sceFiosGetFileSizeSync fiosFileGetSizeSync =
        reinterpret_cast<sceFiosGetFileSizeSync>(dlsym(RTLD_DEFAULT, "cTkFileSystem::Construct"));

    TheData *mpData = (TheData *)malloc(sizeof(TheData));

    std::vector<cTkBankInfo> laModBankInfo = std::vector<cTkBankInfo>();

    mpData = *thiscall;

    // also making the incredibly bold assumption hgpaks arent mounted to PCBANKS but from root search path

    if (fiosFileGetSizeSync(0, "DISABLEMODS.TXT") < 0)
    {
        cTkFileSystem__Data__EnumerateBanks enumerateBanksFn = reinterpret_cast<cTkFileSystem__Data__EnumerateBanks>(
            dlsym(RTLD_DEFAULT, "cTkFileSystem::Data::EnumerateBanks"));

        enumerateBanksFn(mpData, &laModBankInfo, "MODS/");

        for (int i = 0; i < laModBankInfo.size(); i++)
        {
            // lazy
        }
    }
}

std::string GetFileNameFromPath(const std::string &path)
{
    int pos = (int)path.length();
    while (pos && path[pos] != '/') --pos;
    return path.substr(pos + 1);
}

int __attribute__((constructor)) attach()
{
    uintptr_t memoryPtr = reinterpret_cast<uintptr_t>(dlsym(RTLD_DEFAULT, "cTkFileSystem::Construct"));
    uintptr_t nmsmodule = 0;
    int size            = 0x4; // is this size of the pointer? might need to be a qword (0x8)
    int startingOffset  = 0xF; // im too dumb to understand, need to consult smart people

    for (int i = 0; i < _dyld_image_count(); i++)
    {
        mach_header *lHeader = (mach_header *)_dyld_get_image_header(i);

        const char *imageName = _dyld_get_image_name(i);
        if (!imageName) continue;

        std::string shortName = GetFileNameFromPath(std::string(imageName));
        if (shortName != NMS_IMAGE_NAME) continue;

        struct stat sb;
        if (stat(imageName, &sb))
        {
            break; // what
        }

        nmsmodule = header;
    }

    uintptr_t signatureAddress = memoryPtr + startingOffset;
    uintptr_t fileOffset       = signatureAddress - nmsmodule;
    uintptr_t offset           = reinterpret_cast<uint32_t>(signatureAddress);
    uintptr_t absolute_address = nmsmodule + (offset + fileOffset) + size;

    thingy_ptr      = reinterpret_cast<uintptr_t *>(absolute_address);
    thingy_original = *thingy_ptr;
    *thingy_ptr     = reinterpret_cast<uintptr_t>(__cTkFileSystem__Construct__);

    return 0;
}

void __attribute__((constructor)) detach() {}