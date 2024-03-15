# imgui_sdl2

## For the stable version, use the `main` branch.

This is a template project, to start your [Dear Imgui](https://github.com/ocornut/imgui) + [SDL2](https://www.libsdl.org/) journey. This combination of libraries
will allow you to make cross platform GUI Desktop applications with **C++**, with the added benefit of having *immediate UI*. The builds are managed by [CMake](https://cmake.org/) and the source code VCS is done by [git](https://git-scm.com/).

If you want to build this project, you need to install **SDL 2.30** from their github repository. This only applies if you are using **Windows**. Then copy
the `i686-w64-mingw32` folder from the installed folder of SDL2 to the `vendor` folder inside this project.
Rename the folder to `SDL2.30`. Then run the following commands to configure and build the project:

```cmd
cmake -S. -Bbuild -G"<insert the name of the generator>"
cmake --build build
```

Then run this executable `build/main` to see **ImGUI** and **SDL2** in action.
