/**
 * @file GcNGuiProceduralTextureViewer.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcNGuiProceduralTextureViewer : public cGcNGuiWindow
{
  public:
    enum eTextureType
    {
        ETexture_Diffuse,
        ETexture_Normal,
        ETexture_Mask,
        ETexture_Parallax,
        ETexture_Feature,
        ETexture_NumTypes,
    };

    class cGcProceduralTextureRecord
    {
      public:
        int miReferences;
        cGcNGuiProceduralTextureViewer::eTextureType meType;
        cTkSmartResHandle mTextureRes;
        cTkVector<cTkSmartResHandle> mMaterialRes;
        cTkVector<cTkSmartResHandle> mModelRes;
    };

    cTkVector<cGcNGuiProceduralTextureViewer::cGcProceduralTextureRecord> mRecords;
    int miFirstTextureToShow;
    int miTexturesToShow;
    int miSelectedTexture;
    bool mbShowSelectedFullscreen;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mSelectedModel;
    cTkVector<int> mSelectedModelRecords;
    int miNumTexturesOfType[5];
};

SKYSCRAPER_END