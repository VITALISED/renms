# renms

## Overview

renms is a No Man's Sky SDK toolchain. The goal of the project is to provide (eventual) cross platform modding support through hooking No Man's Sky's finite state machines (GcApplication for e.g).

We provide various modules, right now the *metadata* project contains *Heridium*, our metadata class dumper along with an automated build chain to make use pretty straightforward. Along with this *skyscraper* contains manually reversed classes and reimplementations of various No Man's Sky objects.

## Building

See [BUILD.md](BUILD.md) for instructions.

## Development State

Project is currently unfinished as of writing (about 2/3 roughly into reversing the entirety of GcApplication), if you're interested in developing for the platform or are a Mac/Linux (or hell even Switch) user who might want to help maintain a platform for their OS please get in touch! You can message us on Discord (either @vitalised or @tractorbeam).

This is also based mostly off the Fractal debug build so even when we reach a working state there will be extra time needed to port to more modern versions.
