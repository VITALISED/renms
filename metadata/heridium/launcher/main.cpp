
#include "winprocess.h"

#ifdef _MSC_VER
#define HERIDIUM_LIB "Heridium.dll"
#else
#define HERIDIUM_LIB "libHeridium.dll"
#endif

void WaitToClose(int code) {
    if (code == 0) {
        for (int i = 5; i >= 0; i--) {
            std::cout << std::format("\rClosing in {}...", i) << std::flush;
            Sleep(1000);
        }
        std::cout << std::endl;
        exit(code);

    } else {
        std::cout << "\nPress enter to close..." << std::flush;
        std::cin.get();
        exit(code);
    }
}

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
    std::cout << std::endl <<
    "Heridium Launcher by tractorbeam - Developed for the RE:NMS project\n" << std::flush;

    try {
        std::filesystem::path exePath, nmsPath, heridiumPath;
        exePath = argv[0];

        if (argc < 2) {
            nmsPath = exePath.parent_path();
            nmsPath /= "NMS.exe";
        } else
            nmsPath = argv[1];

        heridiumPath = exePath.parent_path();
        heridiumPath /= HERIDIUM_LIB;
        CheckPath(nmsPath, "NMS.exe");
        CheckPath(heridiumPath, HERIDIUM_LIB);

        std::cout << "Loading NMS.exe...\n" << std::flush;
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        std::cout << "Injecting the DLL...\n" << std::flush;
        InjectDLL(heridiumPath, nmsProcess.hProcess);

        std::cout << "Injection successful!\n" << std::endl;
        WaitToClose(0);
    } catch (std::exception& e) {
        std::cout << "Error! " << e.what() << std::endl;
        WaitToClose(1);
    }
}