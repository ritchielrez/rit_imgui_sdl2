cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")
set(WARNINGS_AS_ERRORS TRUE)

project(rit-imgui-sdl2 VERSION 1.0)

include(cmake/CompilerWarnings.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/StaticAnalyzers.cmake)

add_executable(main src/main.cpp src/rit_imgui_sdl2.cpp include/rit_imgui_sdl2.hpp)

find_package(imgui CONFIG REQUIRED)

target_include_directories(main PRIVATE "include/")

target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE SDL2main SDL2)
target_link_libraries(main PRIVATE SDL2_image)
