/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "winprocess.h"

#define HERIDIUM_LIB "Heridium.dll"

void printDebug(std::string input)
{
#ifdef _DEBUG
    std::cout << "[ ReLauncher ] " << input << std::endl;
#else
    UNREFERENCED_PARAMETER(input)
#endif
}

void CheckPath(std::filesystem::path path)
{
    if (!std::filesystem::is_regular_file(path))
    {
        throw std::runtime_error(std::string("Not a file: ") + path.string());
    }

    if (!std::filesystem::exists(path)) { throw std::runtime_error(std::string("File not found: ") + path.string()); }
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 0)
        { // I put this easter egg in every one of my command-line programs, almost forgot to put it in here -
          // tractorbeam
            throw std::runtime_error("Achievement Unlocked: \"How did we get here?\" (You somehow managed to run this "
                                     "with a negative number of arguments)");
        }

        std::filesystem::path launcherPath, nmsPath, heridiumPath;
        launcherPath = argv[0];

        if (argc < 2)
        {
            nmsPath = launcherPath.parent_path();
            nmsPath /= "NMS.exe";
        }
        else
            nmsPath = argv[1];

        heridiumPath = launcherPath.parent_path();
        heridiumPath /= HERIDIUM_LIB;
        CheckPath(nmsPath);
        CheckPath(heridiumPath);

        printDebug("Paths found:");
        printDebug("NMS Executable..... " + nmsPath.string());
        printDebug("DLL Injectee....... " + heridiumPath.string());
        printDebug("Current Directory.. " + std::filesystem::current_path().string());

        printDebug("Loading NMS.exe...");
        auto nmsProcess = CreateProcessFrozen(argv[1]);
        printDebug("Injecting the DLL...");
        InjectDLL(heridiumPath, nmsProcess.hProcess);

        printDebug("Injection successful!");
        // Wait for NMS.exe to get closed
        WaitForSingleObject(nmsProcess.hProcess, INFINITE);
        CloseHandle(nmsProcess.hProcess);
        CloseHandle(nmsProcess.hThread);
        exit(0);
    }
    catch (std::exception &e)
    {
        std::cout << "[ ReLauncher ] Error! " << e.what() << std::endl;
        exit(1);
    }
}