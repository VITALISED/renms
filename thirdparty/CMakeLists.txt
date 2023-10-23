
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

message(STATUS "Fetching and compiling dependencies (This may take a moment)...")
FetchContent_Declare(
    LIB_FMT
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    LIB_SPDLOG
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    LIB_MINHOOK
    GIT_REPOSITORY "https://github.com/TsudaKageyu/minhook.git"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(LIB_FMT LIB_SPDLOG LIB_MINHOOK)