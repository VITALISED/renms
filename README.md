# ReNMS

[![Hits-of-Code](https://hitsofcode.com/github/VITALISED/renms?branch=main)](https://hitsofcode.com/github/VITALISED/renms/view?branch=main)

## Overview

ReNMS is a No Man's Sky SDK modding framework featuring a high-level type framework for working with No Man's Sky or the Skyscraper engine. Supports complete access to most of the game's runtime memory and classes (including those in metadata mods), a header generator for metadata classes with around ~2400 headers and a further manually recreated 200-300 headers. Supports a dynamic plugin loading system for you to load libraries at runtime with a fairly ergonomic and native C++ interface.

![customised mod warning](docs/banner_a.png)

## Installing

Check the releases tab. You'll need a specific version of No Man's Sky to play (either Fractal 4.13 on Steam or GOG), which we provide an installer for; it uses [DepotDownloader](https://github.com/SteamRE/DepotDownloader), kudos to those guys for making this pretty seamless to distribute.

Also check out [NMS.py](https://github.com/monkeyman192/NMS.py) if you play on the GOG version of Fractal, it's pretty cool.

## Building

See [BUILD.md](BUILD.md) for instructions. (potentially outdated)

## Development State

We're currently working on polishing existing headers and adding new calls to the game. It would be cool to port some definitions to a standalone version agnostic platform but this is time consuming and inconvenient to maintain with the handful of people working on the project right now.

Feel free to show off what you make to us in our ["official" discord](https://discord.gg/SbEQFsJxNV). We also live in [No Man's Sky Retro discord](https://discord.gg/tEYNuMmAvR).

## Contributing / Plugin Dev

Contributions are always welcome. we're currently working on fleshing out a proper API. If you have any ideas on calls that might be useful to hook we'd love to hear it. Any help porting structures is also appreciated, please message @vitalised for more details on this.

Documentation for plugins isn't planned for some time, mostly because it's too time consuming. However, you can check out the [renms example plugin repo](https://github.com/VITALISED/renms_plugin_example)

## Some useful links

* [Horde3D](https://github.com/horde3d/Horde3D/)
* [Somewhat recent NMS shader source](https://github.com/EthanRDoesMC/NMS-ShaderCode)