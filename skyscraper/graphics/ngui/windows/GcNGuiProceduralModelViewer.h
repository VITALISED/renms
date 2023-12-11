/**
 * @file GcNGuiProceduralModelViewer.h
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

#include <graphics/ngui/GcNGuiModelRenderer.h>
#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <toolkit/resources/TkResourceDescriptor.h>

#include <toolkit/tkproceduraltexturechosenoptionlist.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiProceduralModelViewer : public cGcNGuiWindow
{
  public:
    bool mbLoadRequest;
    cTkFixedString<256, char> mLoadFilename;
    cTkResourceDescriptor mLoadDescriptor;
    TkID<256> mLoadHint;
    std::array<cTkProceduralTextureChosenOptionList, 32> maTextureDescriptors;
    cTkProceduralTextureChosenOptionList *mpTextureDescriptorOverride;
    cTkMatrix34 mModelMatrix;
    std::array<cGcNGuiModelRenderer, 32> maEntries;
    int miImagesGenerated;
    int miImagesPerFrame;
    int miMaxImages;
    cTkSeed mOverrideSeed;
    int miSelectedEntry;
    int miSelectSeed;
    bool mbArrayLoaded;
    bool mbViewRequest;
    int miViewRequestIndex;
    cTkVector<TkID<256>> maGenerationFilters;
    bool mbForceSeed;
    uint64_t muiForcedSeed;
};

SKYSCRAPER_END