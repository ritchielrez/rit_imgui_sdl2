cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

project(rit-imgui-sdl2 LANGUAGES CXX)

add_subdirectory(vendor)
add_executable(${PROJECT_NAME} src/main.cpp src/rit_imgui_sdl2.cpp)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address)
  target_link_libraries(${PROJECT_NAME} PRIVATE -fsanitize=address) # Links address sanitizer runtime
endif()

target_include_directories(${PROJECT_NAME} PRIVATE "include/")
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
