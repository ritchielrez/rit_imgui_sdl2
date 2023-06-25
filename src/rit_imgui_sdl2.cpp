#include "rit_imgui_sdl2.hpp"

#include "SDL2/SDL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <iostream>

namespace rit_imgui_sdl2_app
{

namespace
{
SDL_Window *window{nullptr};
SDL_Renderer *renderer{nullptr};
}; // namespace

void init(const char *title, const int width, const int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL Video initilization failed, " << SDL_GetError() << "\n";
        return;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    auto &imguiIO = ImGui::GetIO();

    // Enable keyboard navigation, docking and multiple viewports in imgui
    imguiIO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // NOLINT
    imguiIO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // NOLINT
    imguiIO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // NOLINT

    imguiIO.ConfigDockingWithShift = true;

    imguiIO.Fonts->AddFontFromFileTTF("CascadiaCode.ttf", font_size);

    // No tabbars on the top
    // ImGuiWindowClass window_class;
    // window_class.DockNodeFlagsOverrideSet = 1 << 12;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == nullptr)
    {
        std::cerr << "Windows initilization failed, " << SDL_GetError() << "\n";
        return;
    }

    if (renderer == nullptr)
    {
        std::cerr << "Renderer initilization failed, " << SDL_GetError() << "\n";
        return;
    }

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);
}

void update()
{
    // Tell imgui to create a new frame
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport();
}

void render()
{
    ImGui::Render();
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(renderer);
}

void exit()
{
    // Destruction!!!!!!!!!!!
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
}; // namespace rit_imgui_sdl2_app
