# Building

## "I want it now!"

This is really easy. See the `config-template.cmake`? Copy it into a file called `config.cmake`, and change any values you think need changed (at the very least NMS_EXE_DIR must be changed). Then sync the submodules, configure, and build. If it's in the shell:

```sh
git submodules update --init --recursive
mkdir build && cd build
cmake ..
cmake --build .
```

All binaries will end up in `./bin`

### "It didn't work"

Read the rest of this file.

### "It still didn't work"

Contact me (@tractorbeam on discord) or, if the issue is something on our end (and you know what you're doing), open an issue on Github.

## Configuring

```sh
git submodules update --init --recursive
mkdir build && cd build
cmake ..
```

### OS

* **Windows** - Assuming all the dependencies are there, it should just work.
* **macOS/Other** - We currently do not have a way of making this compile natively on mac. Unfortunately, a lot of the processes that make this work on Windows and whatnot is impossible given macOS's entirely different software *and* hardware architectures. You can, however, run it under a translation layer such as wine or proton, however this is **untested** and there are no garuntees.

### Dependencies

All this requires is Cmake, a build system (like Ninja or Gnu Make), and your choice of C/C++ compiler flavour. Everything else is managed by the git submodules system.

## Compiling

```bash
cmake --build .
```

This is why we use cmake. After all of this is done and generated, this is the entire build command, every single time. It will even reconfigure on it's own if you add a few new source files or something like that. Marvelous.

## Q&A

### "Why does it need to know where No Man's Sky is?"

It's not your average run-of-the-mill build process. Due to the immense number of classes (>2000) it's difficult to track them without bogging the repo down (along with the various potential legal repurcussions of shipping stripped code directly from the exe). Luckily, the extraction and building of these headers can be automagically pulled from No Man's Sky using Heridium by attaching it to the running executable and extracting them all when it loads. Even better, this all happens at compile time without any extra input from you, aside from the path to the NMS.exe in the config.cmake.

### "CMake subdirectory version??!?!11?!?!"

I would change it if I could, but unfortunately MinHook hasn't been updated in 7 years.

<sup><sub>-tractorbeam wrote this-</sub></sup>
