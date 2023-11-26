#include <graphics/ngui/GcNGuiText.h>

SKYSCRAPER_BEGIN

cGcNGuiText::~cGcNGuiText()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cGcNGuiText::Render()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiText::EditElement()
{
    EMPTY_CALL_VOID();
}

void cGcNGuiText::AttachMetadata(cTkClassPointer *)
{
    EMPTY_CALL_VOID();
}

eNGuiEditorIcons cGcNGuiText::GetSceneTreeIcon()
{
    return EIcon_font;
}

void cGcNGuiText::GetSceneTreeText(cTkFixedString<128, char> *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END