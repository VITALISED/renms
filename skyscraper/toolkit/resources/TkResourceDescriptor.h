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