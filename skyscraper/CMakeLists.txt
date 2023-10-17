add_library(
    renms_skyscraper
    "engine/source/engine/EgShader.h"
    "engine/source/engine/EgShader.cpp"
    "engine/source/shared/rapidxml.h"
    "engine/source/shared/rapidxml_print.h"
    "engine/source/shared/utxmlparser.h"
    "toolkit/attachments/TkHandle.h"
    "toolkit/data/TkClassPointer.h"
    "toolkit/data/TkID.h"
    "toolkit/data/TkMetaData.h"
    "toolkit/data/TkMetaDataClasses.h"
    "toolkit/data/TkMetaDataXML.h"
    "toolkit/graphics/TkColour.h"
    "toolkit/maths/geometry/TkAABB.h"
    "toolkit/maths/geometry/TkBBox2d.h"
    "toolkit/maths/geometry/TkPhysRelVec3.h"
    "toolkit/maths/numeric/generic/TkMatrix34Generic.h"
    "toolkit/maths/numeric/generic/TkVector2Generic.h"
    "toolkit/maths/numeric/generic/TkVector2Generic.cpp"
    "toolkit/maths/numeric/generic/TkVector3Generic.h" 
    "toolkit/maths/numeric/generic/TkVector4Generic.h"
    "toolkit/resources/TkResource.h"
    "toolkit/resources/TkResourceDescriptor.h"
    "toolkit/resources/TkSmartResHandle.h"
    "toolkit/simulation/physics/havok/TkRigidBody.h"
    "toolkit/simulation/TkSeed.h"
    "toolkit/system/memory/pools/TkLinearMemoryPool.h"
    "toolkit/system/memory/pools/TkMemoryPool.h"
    "toolkit/system/TkMemoryManager.h"
    "toolkit/utilities/containers/TkVector.h"
    "toolkit/utilities/TkString.h"
    "toolkit/utilities/TkString.cpp"
    "toolkit/utilities/TkStrongType.h"
    "toolkit/utilities/TkArray.h"
    "toolkit/voxel/TkHalfVectors.h"
)

target_include_directories(
    renms_skyscraper PRIVATE
    ${CMAKE_SOURCE_DIR}/skyscraper
)

# set_target_properties(renms_skyscraper PROPERTIES LINKER_LANGUAGE CXX)
