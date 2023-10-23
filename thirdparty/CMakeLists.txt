
include(FetchContent)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(FETCHCONTENT_QUIET OFF)
else()
    set(FETCHCONTENT_QUIET ON)
endif()

set (LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib")

message(STATUS "Fetching and compiling dependencies (This may take a moment)...")
FetchContent_Declare(
    LIB_FMT
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_PROGRESS TRUE
    BINARY_DIR "${LIB}/fmt"
)

FetchContent_Declare(
    LIB_SPDLOG
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_PROGRESS TRUE
    BINARY_DIR "${LIB}/spdlog"
)

FetchContent_Declare(
    LIB_MINHOOK
    GIT_REPOSITORY "https://github.com/TsudaKageyu/minhook.git"
    GIT_PROGRESS TRUE
    BINARY_DIR "${LIB}/minhook"
)

FetchContent_Declare(
    LIB_ROBINHOOD
    GIT_REPOSITORY "https://github.com/martinus/robin-hood-hashing.git"
    GIT_PROGRESS TRUE
    BINARY_DIR "${LIB}/robinhood"
)

FetchContent_MakeAvailable(LIB_FMT LIB_SPDLOG LIB_MINHOOK LIB_ROBINHOOD)

link_directories(${LIB})
