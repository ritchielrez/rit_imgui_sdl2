if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(MINGW)
    set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vendor/SDL2-2.30.8-mingw/cmake")
  endif()
elseif(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(FATAL_ERROR "Unknown platform") 
endif()

find_package(SDL2 REQUIRED)
message(STATUS "SDL2 found: ${SDL2_INCLUDE_DIRS}")

add_library(imgui STATIC
  imgui/imgui.cpp
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_tables.cpp
  imgui/imgui_widgets.cpp
  imgui/backends/imgui_impl_sdl2.cpp
  imgui/backends/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_LIST_DIR}/imgui/")
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_LIST_DIR}/imgui/backends/")
target_include_directories(imgui PUBLIC "${SDL2_INCLUDE_DIRS}")
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_link_libraries(imgui PUBLIC "${SDL2_STATIC_LIBRARIES}")
else()
  target_link_libraries(imgui PUBLIC "${SDL2_LIBRARIES}")
endif()
