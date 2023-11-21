# renms

## Overview

renms is a No Man's Sky SDK featuring a top down (not yet complete, soontm) type framework for working with any NMS (or frankly Skyscraper in general if they ever use the engine again). Supports a Python scripting framework which you can use to run our stuff embedded or to use monkeyman's [NMS.py](https://github.com/monkeyman192/NMS.py) instead. If you're more technical and like messing around with memory in a real man's language we also have dynamic library loading supported too.

## Building

See [BUILD.md](docs/BUILD.md) for instructions.

## Development State

Project currently only builds for Fractal on GOG (for obvious reasons). Will be ported to OSX (yes I'll add archive mounting from FS) at some point eventually when I get my Mac's charging cable. Supporting future versions of NMS is planned sometime after the 2023 expected expedition redux missions.

We mostly live unofficially in the [No Man's Sky Retro discord](https://discord.gg/tEYNuMmAvR) but please don't come here for tech support. Open an issue or message us on Discord directly at @vitalised or @tractorbeam

## Contributing / Plugin Dev

Contributions are always welcome, there are more types in this engine than planets in the bloody game. We're also always down to support extra platforms too if you have the know-how as well.

Documentation for plugins isn't planned for some time, mostly because it's too time consuming when there are so many types to reverse.

If all this type cut-and-paste stuff is too boring for you to feel bothered to contribute to, we're also looking for shader-smart people to help reverse NMS' Horde3d shader parser. (see [this file](https://github.com/horde3d/Horde3D/blob/master/Horde3D/Source/Horde3DEngine/egShader.cpp#L495) for some context.)

## Some useful links

* [Horde3D](https://github.com/horde3d/Horde3D/)
* [Somewhat recent NMS shader source](https://github.com/EthanRDoesMC/NMS-ShaderCode)
