# imgui_sdl2

### Warning: Only MinGW and Linux are supported as platforms.

This is a template project, to start your [Dear Imgui](https://github.com/ocornut/imgui) + [SDL2](https://www.libsdl.org/) journey. This combination of libraries
will allow you to make cross platform GUI Desktop applications with **C++**, with the added benefit of having *immediate UI*. The libraries are managed with
manually, the builds are managed by [CMake](https://cmake.org/) and the source code VCS is done by [git](https://git-scm.com/).

To get started, clone this repository to your computer and `cd` into it. If you are using **Linux**, make sure to install **SDL2** with your distribution's system packager manager.
Then run these commands to compile this project.
```bash
cmake -B build -S.
cmake --build build/
```
The executable now should be ready in `build/` folder, run it. And .-. now you have **imgui** with **SDL2** working.
