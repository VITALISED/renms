#include <graphics/ngui/GcNGuiLayer.h>

SKYSCRAPER_BEGIN

cGcNGuiLayer::~cGcNGuiLayer()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcNGuiLayer::Render()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::EditElement()
{
    EMPTY_CALL_VOID();
}

bool cGcNGuiLayer::SelectableInEditor()
{
    EMPTY_CALL();
}

void cGcNGuiLayer::SetNeedsUpdate()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::Deselect()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::Resized()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::AttachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::DetachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

eNGuiEditorIcons cGcNGuiLayer::GetSceneTreeIcon()
{
    if (this->mapElements.size()) { return static_cast<eNGuiEditorIcons>(this->mbExpanded + EIcon_folder3); }
    else
        return EIcon_folder;
}

void cGcNGuiLayer::GetSceneTreeText(cTkFixedString<128, char> *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::RenderAdditionalOverlayIcons(const cTkVector2 *, const cTkVector2 *)
{
    EMPTY_CALL_VOID();
}

void cGcNGuiLayer::RenderTreeControls()
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END