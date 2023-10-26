#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaDataClasses.h>
#include <toolkit/data/TkClassPointer.h>
#include <toolkit/system/memory/pools/TkLinearMemoryPool.h>

#include <toolkit/simulation/TkSeed.h>
#include <toolkit/graphics/TkColour.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/numeric/generic/TkVector4Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkVector2Generic.h>
#include <toolkit/voxel/TkHalfVectors.h>

SKYSCRAPER_BEGIN

template <unsigned int uiSize>
union TkID
{
	TkID()
	{ }
    
	TkID(const char *lpacString)
	{
		// uses hashes pretty sure, gonna have to figure out spookyhash later
		strcpy_s(mChars, uiSize, lpacString);
	}

	char mChars[uiSize / 8];
	unsigned __int64 mUInt64[uiSize / 64];
};

class cTkMetaDataFunctionLookup
{
public:
    const cTkMetaDataClass *mpClassMetadata;
    void (*mCreateDefaultFunction)(cTkClassPointer *, cTkLinearMemoryPool *);
    void (*mRenderFunction)(cTkClassPointer *);
    void (*mFixingFunction)(cTkClassPointer *, bool, unsigned __int64);
    void (*mValidateDataFunction)(cTkClassPointer *);
    bool (*mEqualsFunction)(const cTkClassPointer *, const cTkClassPointer *);
    void (*mCopyFunction)(cTkClassPointer *, const cTkClassPointer *);
    cTkClassPointer *(*mCreatePtrFunction)(cTkClassPointer *result);
    unsigned __int64 (*mHashFunction)(const cTkClassPointer *, unsigned __int64, bool);
    void (*mDestroyFunction)(cTkClassPointer *);
};

SKYSCRAPER_END