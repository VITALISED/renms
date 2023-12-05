/**
 * @file EgScene.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-05
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