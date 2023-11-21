#pragma once

#include <skyscraper.h>

#include <graphics/ngui/GcNGuiElement.h>
#include <toolkit/graphics/2d/ngui/TkHashedNGuiElement.h>
#include <toolkit/utilities/containers/TkLinearHashTable.h>

#include <graphics/ngui/metadata/gcnguilayerdata.meta.h>
#include <toolkit/ngui/tknguigraphicstyledata.meta.h>

SKYSCRAPER_BEGIN

class cGcNGuiLayer : public cGcNGuiElement
{
  public:
    cTkVector<cGcNGuiElement *> mapElements;
    cTkVector<cGcNGuiLayer *> mapLayerElements;
    cTkVector<cTkVector2> maPinnedPositions;
    cTkNGuiGraphicStyleData mPreviousGraphicsStyle;
    void (*mpRenderFunction)(void *);
    void *mpRenderFunctionData;
    cGcNGuiLayerData *mpLayerData;
    cTkLinearHashTable<cTkHashedNGuiElement, cGcNGuiElement *, cTkHashedNGuiElement> *mpElementHashTable;
    uint64_t muUniqueID;
    bool mbExpanded;

    ~cGcNGuiLayer();
    void Render();
    int GetType() { return NULL; }
    void EditElement();
    bool SelectableInEditor();
    void SetNeedsUpdate();
    void Deselect();
    void Resized();
    void AttachMetadata(cTkClassPointer *);
    void DetachMetadata(cTkClassPointer *);
    eNGuiEditorIcons GetSceneTreeIcon();
    void GetSceneTreeText(cTkFixedString<128, char> *);
    void RenderAdditionalOverlayIcons(const cTkVector2 *, const cTkVector2 *);
    void RenderTreeControls();
};

SKYSCRAPER_END