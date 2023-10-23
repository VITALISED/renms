
#include "winprocess.h"

#ifdef _MSC_VER
#define HERIDIUM_LIB "Heridium.dll"
#else
#define HERIDIUM_LIB "libHeridium.dll"
#endif

void printDebug(std::string input) {
    #ifdef _DEBUG
    std::cout << input << std::endl;
    #else
    do {} while (input != input);   //This is a really dumb way to make the compiler not complain about unused variables. I love it.
    #endif
}

void CheckPath(std::filesystem::path path, std::string filename) {
    if (std::filesystem::is_directory(path)) {
        path /= filename;
    }
    
    if (!std::filesystem::exists(path)) {
        throw std::runtime_error(
            std::string("File not found: {}") + path.string());
    }

    if (!std::filesystem::is_regular_file(path)) {
        throw std::runtime_error(
            std::string("Not a file: {}") + path.string());
    }

    if (path.filename() != filename) {
        throw std::runtime_error(
            std::string("Not the right kind of file: got ") + path.filename().string() + ", expected " + filename);
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

        heridiumPath = exePath.parent_path();
        heridiumPath /= HERIDIUM_LIB;
        CheckPath(nmsPath, "NMS.exe");
        CheckPath(heridiumPath, HERIDIUM_LIB);

        printDebug("Loading NMS.exe...\n");
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        printDebug("Injecting the DLL...\n");
        InjectDLL(heridiumPath, nmsProcess.hProcess);

        printDebug("Injection successful!\n");
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