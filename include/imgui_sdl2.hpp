#pragma once

#include <SDL2/SDL.h>

#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

namespace imgui_sdl2
{
class Application
{
  private:
    SDL_Window *mWindow{NULL};
    SDL_Renderer *mRenderer{NULL};

  public:
    Application(const char *title, const int width, const int height);
    ~Application();

    void render();
    void update();
};
}; // namespace imgui_sdl2
