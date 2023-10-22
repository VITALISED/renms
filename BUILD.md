# Building

## "I want it now!"

Make a build directory, go into it, configure, and then compile as per the below. The last one will take a bit. Oh, and if you're a developer looking to debug, don't forget to append `-DCMAKE_BUILD_TYPE=Debug` to the command, the extra info will help immensely.

```bash
mkdir build
cd build
cmake .. -DNMS_EXE_PATH="C:/.../No Man's Sky/Binaries"
cmake --build .
```

All binaries will end up in `.../renms/bin`

### "It didn't work"

Read the rest of this file.

### "It still didn't work"

Contact me (@tractorbeam on discord) or, if the issue is something on our end (and you know what you're doing), open an issue on Github.

## Configuring

### "Why does it need to know where No Man's Sky is?"

It's not your average run-of-the-mill build process. For legal reasons, (or maybe not, not gonna risk it either way), we can't include a lot of the headers that are needed for renms to build. It's based off of metadata we extracted from a leaked developer build, and as such it isn't ours, and we shouldn't distribute it. Luckily, the extraction and building of these headers can be automagically pulled from No Man's Sky using Heridium! Unfortunately, this means that the path to your NMS.exe must be specified to the compiler, but aside from that it's easy rolling.

### OS

* **Windows** - Assuming all the dependencies are there, it should just work.
* **Linux** - **<span style="color:red">(Untested)</span>** renms only works on Windows, but it does have cross-compiling support. It'll run a few more checks and it should otherwise be like Windows.
* **macOS** - **<span style="color:red">(Untested)</span>** Same as with Linux. We know that there is a native macOS version of No Man's Sky, but steps vital to the modding process (Hooking, accessing, attaching, etc) are entirely different with these executables, and it simply isn't worth porting. You'll have to stick to wine/proton.

### Dependencies

#### Windows

All this requires is Cmake, a build system (like Ninja or Gnu Make), and your choice of C/C++ compiler flavour.

<sub><sup>Please use Ninja, it multithreads by default and takes like 2/3rds the time to compile, it's just better, at least try it out.</sup></sub>

#### Not Windows

You're gonna need a few other things on top of Cmake. In short, the packages for the vast majority of package managers should be `cmake g++-mingw-w64 gcc-mingw-w64 wine32 wine64`. This will install a few GB worth of things because all that is meant to allow building C++ apps for Windows in a Not-Windows environment, including another tool for running Windows applications on Not-Windows.

Wine32 is required because lot of basic Windows system exes are in 32-bit. If your package manager is complaining that the wine32 package doesn't exist, you need to enable installing 32-bit packages on your distro and then run whatever you run to update everything before installing it.

Finally, append `-DCMAKE_TOOLCHAIN_FILE="./toolchain-win.cmake"` to the end of your cmake configure command, and run it.

## Compiling

```bash
cmake --build .
```

This is why we use cmake. After all of that is done and generated, this is the entire build command, every single time. It will even reconfigure on it's own if you add a few new source files or something like that. Marvelous.

<center><sup><sub>-tractorbeam wrote this-</sub></sup></center>
