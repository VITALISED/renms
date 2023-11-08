#include <core/filesystem.h>

using namespace std::filesystem;

RENMS_BEGIN

void CreateTargetDirectories()
{
    path nmsPath   = current_path();
    path renmsPath = nmsPath / "RENMS";

    if (!is_directory(renmsPath))
    {
        spdlog::info("Creating new directories at: {}", renmsPath.string());

        create_directories(renmsPath);
        create_directories(renmsPath / "Plugins");
        create_directories(renmsPath / "Logs");
    }
}

RENMS_END