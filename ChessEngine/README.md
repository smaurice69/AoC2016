# Chess Engine Skeleton

This directory contains a minimal C++ project for a UCI-compatible chess engine. It is intended as a starting point for further development.

## Build Requirements

- CMake 3.10+
- A C++17 compiler (Clang++ or MSVC)

## Building with VS Code on macOS

1. Install [Xcode Command Line Tools](https://developer.apple.com/xcode/).
2. Install [CMake](https://cmake.org/) (e.g. using Homebrew: `brew install cmake`).
3. Open this folder in VS Code.
4. Install the VS Code extensions **C/C++** and **CMake Tools**.
5. Press `Ctrl+Shift+P` and run `CMake: Configure`. Select the available Clang kit.
6. Build with `CMake: Build`.
7. Run the engine from the terminal: `./build/chessengine`.

## Building with Visual Studio 2022 on Windows

1. Install [Visual Studio 2022](https://visualstudio.microsoft.com/) with the *Desktop development with C++* workload and the *C++ CMake tools for Windows* component.
2. Open Visual Studio and select **File → Open → CMake...** and choose this `ChessEngine` folder.
3. Visual Studio will configure the CMake project automatically.
4. Build the `chessengine` target.
5. Run from the VS terminal or debugger.

The engine implements a basic UCI protocol with support for the `position fen` command.
It can parse a FEN string and store the resulting board state. Extend `Engine.cpp`
to add actual search logic and a more complete UCI feature set.
