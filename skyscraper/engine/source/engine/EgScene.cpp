#include <engine/source/engine/EgScene.h>

SKYSCRAPER_BEGIN

cEgNodeAttachment::~cEgNodeAttachment()
{
    EMPTY_CALL_DESTRUCTOR();
}

cEgSceneNode::~cEgSceneNode()
{
    EMPTY_CALL_DESTRUCTOR();
}

int cEgSceneNode::GetParameterInt(int)
{
    EMPTY_CALL();
}

void cEgSceneNode::SetParameterInt(int, int)
{
    EMPTY_CALL_VOID();
}

float cEgSceneNode::GetParameterFloat(int, int)
{
    EMPTY_CALL();
}

void cEgSceneNode::SetParameterFloat(int, int, float)
{
    EMPTY_CALL_VOID();
}

cTkVector3 *cEgSceneNode::GetParameterVec3(cTkVector3 *result, int, int)
{
    EMPTY_CALL();
}

void cEgSceneNode::SetParameterVec3(int, int, const cTkVector3 *)
{
    EMPTY_CALL_VOID();
}

const char *cEgSceneNode::GetParameterStr(int)
{
    EMPTY_CALL();
}

void cEgSceneNode::SetParameterStr(int, const char *)
{
    EMPTY_CALL_VOID();
}

void cEgSceneNode::GetVisibleBBox(cEgBoundingBox *)
{
    EMPTY_CALL_VOID();
}

int cEgSceneNode::GetClassOverride()
{
    EMPTY_CALL();
}

cEgRenderableSceneNode::~cEgRenderableSceneNode()
{
    EMPTY_CALL_DESTRUCTOR();
}

void cEgRenderableSceneNode::OnAttach(cEgSceneNode *)
{
    EMPTY_CALL_VOID();
}

void cEgRenderableSceneNode::OnDetach(cEgSceneNode *)
{
    EMPTY_CALL_VOID();
}

SKYSCRAPER_END