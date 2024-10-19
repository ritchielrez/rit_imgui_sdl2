#include "rit_imgui_sdl2.hpp"

#include <iostream>

int main(int /*argc*/, char ** /*argv*/)
{
    const int width = 1280;
    const int height = 720;

    rit_imgui_sdl2_app::init("Window", width, height);

    bool running{true};
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            break;
        }

        rit_imgui_sdl2_app::update();

        // Create a panel with specific window configuration
        // ImGui::SetNextWindowClass(&window_class);

        ImGui::Begin("Some panel", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
        ImGui::Text("Hello World");
        ImGui::End();

        ImGui::ShowMetricsWindow();

        rit_imgui_sdl2_app::render();
    }

    rit_imgui_sdl2_app::exit();

    return 0;
}
