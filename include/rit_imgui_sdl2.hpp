#pragma once

#include "SDL2/SDL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

namespace imgui_sdl2
{
class Application
{
  private:
    SDL_Window *mWindow;
    inline static SDL_Renderer *sRenderer_{nullptr};

  public:
    Application(const char *title, const int width, const int height);
    ~Application();

    static void render();
    static void update();

    inline static SDL_Renderer *&sRenderer = sRenderer_;
};
}; // namespace imgui_sdl2
