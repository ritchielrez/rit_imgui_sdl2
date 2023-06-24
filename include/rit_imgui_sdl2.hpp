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
    SDL_Window *mWindow{nullptr};
    inline static SDL_Renderer *sRenderer_{nullptr};

  public:
    Application(const Application &) = default;
    Application(Application &&) = delete;
    Application &operator=(const Application &) = delete;
    Application &operator=(Application &&) = delete;
    Application(const char *title, int width, int height);
    ~Application();

    static void render();
    static void update();

    inline static SDL_Renderer *&sRenderer = sRenderer_;

    float fontSize = 18.0F;
};
}; // namespace imgui_sdl2
