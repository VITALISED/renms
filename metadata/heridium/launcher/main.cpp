
#include "winprocess.h"

#ifdef _MSC_VER
#define HERIDIUM_LIB "Heridium.dll"
#else
#define HERIDIUM_LIB "libHeridium.dll"
#endif

void CheckPath(std::filesystem::path path, std::string filename) {
    if (std::filesystem::is_directory(path)) {
        path /= filename;
    }
    
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error(
            std::format("File not found: {}", path.string()));
    }

    if (!std::filesystem::is_regular_file(path)) {
        throw std::runtime_error(
            std::format("Not a file: {}", path.string()));
    }

    if (path.filename() != filename) {
        throw std::runtime_error(
            std::format("Not the right kind of file: got {}, expected {}", path.filename().string(), filename));
    }
}

int main(int argc, char** argv) {
    try {
        if (argc < 0) { //I put this easter egg in every one of my command-line programs, almost forgot to put it in here - tractorbeam
            throw std::runtime_error("Achievement Unlocked: \"How did we get here?\" (You somehow managed to run this with a negative number of arguments)");
        }

        std::filesystem::path exePath, nmsPath, heridiumPath;
        exePath = argv[0];

        if (argc < 2) {
            nmsPath = exePath.parent_path();
            nmsPath /= "NMS.exe";
        } else
            nmsPath = argv[1];

        heridiumPath = exePath.parent_path().parent_path();
        heridiumPath /= HERIDIUM_LIB;
        CheckPath(nmsPath, "NMS.exe");
        CheckPath(heridiumPath, HERIDIUM_LIB);

        std::cout << "Loading NMS.exe...\n" << std::flush;
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        std::cout << "Injecting the DLL...\n" << std::flush;
        InjectDLL(heridiumPath, nmsProcess.hProcess);

        std::cout << "Injection successful!\n" << std::endl;
        //Wait for NMS.exe to get closed
        WaitForSingleObject(nmsProcess.hProcess, INFINITE);
        CloseHandle(nmsProcess.hProcess);
        CloseHandle(nmsProcess.hThread);
        exit(0);
    } catch (std::exception& e) {
        std::cout << "Error! " << e.what() << std::endl;
        exit(1);
    }
}