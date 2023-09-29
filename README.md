# Audio Visualizer

The **Audio Visualizer** is a C++ project designed to process and visualize sound data in real-time. It utilizes the openFrameworks framework for graphics and audio handling.

## Overview

This project's main purpose is to provide a visual representation of audio data, allowing users to see the sound's amplitude in various ways. The project includes three visualization modes:

1. **Rectangle Height Visualizer:** Displays amplitudes as the heights of colored rectangles.
2. **Circle Radius Visualizer:** Visualizes amplitudes by varying the radii of circles in the center of the screen.
3. **Rectangle Width Visualizer:** Represents amplitudes by altering the widths of colored rectangles.

## Features

- Real-time audio visualization.
- Interactive controls for playing and pausing audio.
- Different visualization modes to explore.
- Recording and replaying user-inputted keys for interactive playback.

## Usage

1. **Compilation**: This project utilizes the openFrameworks framework. Make sure you have openFrameworks properly set up before compiling the project.

2. **Main Configuration**:
   - Modify the `main.cpp` file to set up the initial configuration, such as window size.
   - Include your sound files (e.g., "beat.wav," "geesebeat.wav") in the project's `bin/data/` directory.

3. **Controls**:
   - Press 'p' to play/pause the audio.
   - Press 'r' to start/stop recording keys for replay.
   - Press 't' to start/stop replaying recorded keys.
   - Press '1', '2', or '3' to switch between visualization modes.
   - Adjust the volume using '-' and '=' keys.

## Dependencies

- openFrameworks: [https://openframeworks.cc/](https://openframeworks.cc/)

##Contributors

- [Sofia M. Barrera Vega](https://github.com/smbv)
- [Nestor S. Frontera Rocher](https://github.com/nsfrontera)

---
