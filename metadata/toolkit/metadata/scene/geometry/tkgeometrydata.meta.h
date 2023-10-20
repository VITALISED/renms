#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cTkGeometryData
{
    static unsigned long long muNameHash = 0xA74EA06001E7577E;
    static unsigned long long muTemplateHash = 0x3705D946A3B218D4;

    int miVertexCount;
    int miIndexCount;
    int miIndices16Bit;
    int miCollisionIndexCount;
    cTkDynamicArray<cTkJointBindingData> maJointBindings;
    cTkDynamicArray<cTkJointExtentData> maJointExtents;
    cTkDynamicArray<int> maJointMirrorPairs;
    cTkDynamicArray<cTkJointMirrorAxis> maJointMirrorAxes;
    cTkDynamicArray<int> maSkinMatrixLayout;
    cTkDynamicArray<int> maMeshVertRStart;
    cTkDynamicArray<int> maMeshVertREnd;
    cTkDynamicArray<int> maBoundHullVertSt;
    cTkDynamicArray<int> maBoundHullVertEd;
    cTkDynamicArray<int> maMeshBaseSkinMat;
    cTkDynamicArray<cTkVector4> maMeshAABBMin;
    cTkDynamicArray<cTkVector4> maMeshAABBMax;
    cTkDynamicArray<cTkVector4> maBoundHullVerts;
    cTkVertexLayout VertexLayout;
    cTkVertexLayout SmallVertexLayout;
    cTkDynamicArray<int> maIndexBuffer;
    cTkDynamicArray<cTkMeshMetaData> maStreamMetaDataArray;
}
