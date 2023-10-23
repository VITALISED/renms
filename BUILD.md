# Building

## "I want it now!"

Make a build directory, go into it, configure, and then compile as per the below. The last one will take a bit. Oh, and if you're a developer looking to debug, don't forget to append `-DCMAKE_BUILD_TYPE=Debug` to the first cmake command, the extra info will help immensely.

```bash
mkdir build
cd build
cmake .. -DNMS_EXE_DIR="C:/.../No Man's Sky/Binaries"
cmake --build .
```

All binaries will end up in `.../renms/bin`

### "It didn't work"

Read the rest of this file.

### "It still didn't work"

Contact me (@tractorbeam on discord) or, if the issue is something on our end (and you know what you're doing), open an issue on Github.

## Configuring

### "Why does it need to know where No Man's Sky is?"

It's not your average run-of-the-mill build process. Due to the immense number of classes (>2000) it's difficult to track them without bogging the repo down (along with the various potential legal repurcussions of shipping stripped code). Luckily, the extraction and building of these headers can be automagically pulled from No Man's Sky using Heridium by linking itself to the running executable and extracting them all when it loads. Unfortunately, this means that the path to your NMS.exe must be specified to the compiler, and the NMS.exe must run while building, but it's mostly automated with little to no issues.

### OS

* **Windows** - Assuming all the dependencies are there, it should just work.
* **Linux** - **<span style="color:red">(Untested)</span>** renms only works on Windows, but it does have cross-compiling support. It'll run a few more checks and it should otherwise be like Windows.
* **macOS** - **<span style="color:red">(Untested)</span>** Same as with Linux. We know that there is a native macOS version of No Man's Sky, but steps vital to the modding process (Hooking, accessing, attaching, etc) are entirely different with these executables.

### Dependencies

#### Windows

All this requires is Cmake, a build system (like Ninja or Gnu Make), and your choice of C/C++ compiler flavour.

<sub><sup>Please use Ninja, it multithreads by default and takes like 2/3rds the time to compile, it's just better, at least try it out.</sup></sub>

#### Not Windows

You're gonna need a few other things on top of Cmake. I can't say what the packages will be for sure, but you'll need at least `mingw-g++` and `wine64`.

**You will have problems at compile time.** MinGW on Non-windows platforms isn't very well maintained, and as a result there isn't a single distribution that will just work after installing the right packages and running the right commands. For instance, the MinGW suite on Arch Linux is missing all the C++ 2020 standard headers (Despite supporting the `-stdc++20` flag), which *are* required here. At the very least, I can assure you that you won't have to worry about when NMS.exe is launched to extract metadata, it automatically switches to wine and I have tested that much, it works fine. You may specify a custom wine command with `-DWINE_EXECUTABLE="YourCommandHere"`, if required.

## Compiling

```bash
cmake --build .
```

This is why we use cmake. After all of that is done and generated, this is the entire build command, every single time. It will even reconfigure on it's own if you add a few new source files or something like that. Marvelous.

## Known issues

Heridium's (the metadata builder's) launcher will refuse to function if built with **MSBuild**. We have no idea why, and frankly we don't have the energy to fix it. Might I suggest using Ninja?

<center><sup><sub>-tractorbeam wrote this-</sub></sup></center>
