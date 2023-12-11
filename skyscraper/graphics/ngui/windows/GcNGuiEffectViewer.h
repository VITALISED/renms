/**
 * @file GcNGuiEffectViewer.h
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
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/graphics/utilities/TkModelResourceRenderer.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/system/filesystem/TkFileSystem.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <toolkit/scene/materials/tkmaterialdata.meta.h>
#include <toolkit/utilities/data/tkparticledata.meta.h>

SKYSCRAPER_BEGIN

enum eMaterialClass
{
    EMaterialClassAdditive,
    EMaterialClassAdditiveHighQuality,
    EMaterialClassTranslucent,
    EMaterialClassGlowTranslucent,
    EMaterialClassOpaque,
    EMaterialClass_NumTypes,
};

class cGcNGuiEffectViewer : public cGcNGuiWindow
{
  public:
    struct EmitterData
    {
        cTkFixedString<128, char> macName;
        cTkMatrix34 mTransformMatrix;
        cTkParticleData *mpEmitterData;
        cTkFixedString<512, char> macEmitterFilename;
        cTkMaterialData *mpMaterialData;
        cTkFixedString<512, char> macMaterialFilename;
        TkHandle mNodeHandle;
        TkHandle mRemovalNodeHandle;
        cTkSmartResHandle mMaterial;
        cTkVector<cTkSmartResHandle> maTexures;
        bool mbActive;
        eMaterialClass meMaterialClass;
    };

    struct EmitterDisplayData
    {
        bool mbShow;
    };

    bool mbClickToPlay;
    cTkFilename macFilename;
    TkID<128> mTableEntry;
    bool mbBrowseLibrary;
    bool mbLoopEffect;
    bool mbBigTextureMode;
    TkHandle mEffectRootNode;
    TkHandle mEffectModelNode;
    bool mbEffectIsFromMaya;
    cTkSmartResHandle mEffectResource;
    cTkVector<cGcNGuiEffectViewer::EmitterData> maEmitters;
    cTkVector<cGcNGuiEffectViewer::EmitterDisplayData> maEmitterDisplays;
    TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> mRendererHandle;
    cTkModelResourceRenderer mRenderer;
    cTkVector<TkHandle> maClickToPlayEffects;
    bool mbShowWarning;
    cTkFixedString<128, char> macWarningMessage;
};

SKYSCRAPER_END