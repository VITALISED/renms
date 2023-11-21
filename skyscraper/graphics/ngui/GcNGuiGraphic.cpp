#include <graphics/ngui/GcNGuiGraphic.h>

SKYSCRAPER_BEGIN

cGcNGuiGraphic::~cGcNGuiGraphic()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcNGuiGraphic::Render()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiGraphic::EditElement()
{
    EMPTY_CALL_VOID();
}

bool cGcNGuiGraphic::SelectableInEditor()
{
    EMPTY_CALL();
}

void cGcNGuiGraphic::AttachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

eNGuiEditorIcons cGcNGuiGraphic::GetSceneTreeIcon()
{
    return EIcon_photo;
}

void cGcNGuiGraphic::GetSceneTreeText(cTkFixedString<128, char> *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END