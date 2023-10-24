set_directory_properties(PROPERTIES COMPILE_OPTIONS "")

include(FetchContent)

message(STATUS "Fetching dependencies...")
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
