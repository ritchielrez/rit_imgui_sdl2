#pragma once

#include "SDL2/SDL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

namespace rit_imgui_sdl2_app
{

const float font_size = 18.0F;

void init(const char *title, const int width, const int height);

void render();
void update();

void exit();

}; // namespace rit_imgui_sdl2_app
