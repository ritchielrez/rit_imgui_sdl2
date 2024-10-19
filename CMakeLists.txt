cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

project(rit-imgui-sdl2 LANGUAGES CXX)

add_subdirectory(vendor)
add_executable(${PROJECT_NAME} src/main.cpp src/rit_imgui_sdl2.cpp)
