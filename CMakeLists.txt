cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

project(rit-imgui-sdl2 VERSION 1.0)

include(cmake/CompilerWarnings.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/StaticAnalyzers.cmake)

if(WIN32)
	include(cmake/SDL2Windows.cmake)
endif()

add_executable(main src/main.cpp src/rit_imgui_sdl2.cpp include/rit_imgui_sdl2.hpp 
  vendor/imgui.cpp
  vendor/imgui_demo.cpp
  vendor/imgui_draw.cpp
  vendor/imgui_tables.cpp
  vendor/imgui_widgets.cpp
  vendor/imgui_impl_sdl2.cpp
  vendor/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(main PRIVATE "include/")
target_include_directories(main PRIVATE "vendor/")

target_link_libraries(main PRIVATE SDL2main SDL2)

# Fix MinGW / MSYS build for SDL2
if(WIN32)
  if(NOT MSVC)
    target_link_libraries(main PRIVATE mingw32)
  endif()
endif()
