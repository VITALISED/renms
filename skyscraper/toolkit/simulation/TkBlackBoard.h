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
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>
#include <metadata/simulation/tkblackboardtype.meta.h>

SKYSCRAPER_BEGIN

class cTkBlackboardValue
{
	eBlackboardType meType;
	union
	{
		float mFloat;
		int miInteger;
		bool mBool;
		cTkVector3 mVector;
		cTkAttachmentPtr mpAttachment;
		TkID<128> mId;
	};
};

class cTkBlackboard
{
	eBlackboardCategory meCategory;
	cTkUnorderedMap<TkID<128>, cTkBlackboardValue, TkIDUnorderedMap::Hash128> maValues;
};

SKYSCRAPER_END