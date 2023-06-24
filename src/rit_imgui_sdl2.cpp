#include "rit_imgui_sdl2.hpp"

#include "SDL2/SDL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <iostream>

namespace imgui_sdl2
{
Application::Application(const char *title, const int width, const int height)
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
    imguiIO.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // NOLINT
    imguiIO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // NOLINT

    imguiIO.ConfigDockingWithShift = true;

    imguiIO.Fonts->AddFontFromFileTTF("CascadiaCode.ttf", fontSize);

    // No tabbars on the top
    // ImGuiWindowClass window_class;
    // window_class.DockNodeFlagsOverrideSet = 1 << 12;

    mWindow =
        SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    sRenderer_ = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    if (mWindow == nullptr)
    {
        std::cerr << "Windows initilization failed, " << SDL_GetError() << "\n";
        return;
    }

    if (sRenderer_ == nullptr)
    {
        std::cerr << "Renderer initilization failed, " << SDL_GetError() << "\n";
        return;
    }

    ImGui_ImplSDL2_InitForSDLRenderer(mWindow, sRenderer_);
    ImGui_ImplSDLRenderer2_Init(sRenderer_);
}

void Application::update()
{
    // Tell imgui to create a new frame
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport();
}

void Application::render()
{
    ImGui::Render();
    SDL_RenderClear(sRenderer_);
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(sRenderer_);
}

Application::~Application()
{
    // Destruction!!!!!!!!!!!
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(sRenderer_);
    SDL_Quit();
}
}; // namespace imgui_sdl2
