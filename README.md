# ReNMS

[![Hits-of-Code](https://hitsofcode.com/github/VITALISED/renms?branch=main)](https://hitsofcode.com/github/VITALISED/renms/view?branch=main)

## Overview

ReNMS is a No Man's Sky SDK featuring a high-level type framework for working with NMS (or the Skyscraper engine in general). Supports a Python scripting framework which you can use to run our SDK embedded or to use monkeyman's [NMS.py](https://github.com/monkeyman192/NMS.py) if you prefer. If you're more technical and like messing around with memory in a real man's language we also have dynamic library loading supported too, although it's not super field tested yet.

![customised mod warning](docs/banner_a.png)

## Installing

There are no current prebuilt binaries, this will change when we reach a more stable state. You can of course build the project yourself.

## Building

See [BUILD.md](BUILD.md) for instructions. (potentially outdated)

## Development State

The project currently only builds for Fractal 4.13 on GOG. Will be ported to OSX (with archive mounting hopefully) at some point. Supporting future versions of NMS is planned, we're currently working on some workflow things before then so stay tuned! Expect some experimental builds in the coming weeks.

We mostly live unofficially in the [No Man's Sky Retro discord](https://discord.gg/tEYNuMmAvR) but please don't come here for tech support. You can join our [new somewhat official discord](https://discord.gg/SbEQFsJxNV) if you'd like to get in touch directly, or are just interested in development.

## Contributing / Plugin Dev

Contributions are always welcome. we're currently working on fleshing out a proper API. If you have any ideas on calls that might be useful to hook we'd love to hear it. Any help porting structures is also appreciated, please message @vitalised for more details on this.

Documentation for plugins isn't planned for some time, mostly because it's too time consuming. See the example plugin we've provided in `renms/examples`

## Some useful links

* [Horde3D](https://github.com/horde3d/Horde3D/)
* [Somewhat recent NMS shader source](https://github.com/EthanRDoesMC/NMS-ShaderCode)