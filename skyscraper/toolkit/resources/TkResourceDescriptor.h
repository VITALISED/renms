#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/simulation/TkSeed.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cTkResourceDescriptor
{
	// TODO: This is probably a sum of multiple inline funcs
	bool inline IsValid(cTkResourceDescriptor *descriptor, cTkResourceDescriptor *existing)
	{
		if (descriptor->mSeed.mbValid == existing->mSeed.mbValid)
		{
			if (descriptor->mSecondarySeed.mbValid == existing->mSecondarySeed.mbValid && (!descriptor->mSeed.mbValid || !existing->mSeed.mbValid || descriptor->mSeed.mbValid == existing->mSeed.mbValid && descriptor->mSeed.mu64SeedValue && existing->mSeed.mu64SeedValue) && (!descriptor->mSeed.mbValid || !existing->mSeed.mbValid || descriptor->mSecondarySeed.mbValid == existing->mSecondarySeed.mbValid && descriptor->mSecondarySeed.mu64SeedValue == existing->mSecondarySeed.mu64SeedValue) && (existing->maDescriptors.size() == descriptor->maDescriptors.size()))
			{
				return true;
			}
		}

		return false;
	}

public:
	cTkVector<TkID<256>> maDescriptors;
	cTkSeed mSeed;
	cTkSeed mSecondarySeed;
};

SKYSCRAPER_END