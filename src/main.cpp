#include "rit_imgui_sdl2.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    imgui_sdl2::Application app("Window", 1280, 720);

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                running = false;
            break;
        }

        app.update();

        // Create a panel with specific window configuration
        // ImGui::SetNextWindowClass(&window_class);

        ImGui::Begin("Some panel", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
        ImGui::Text("Hello World");
        ImGui::End();

        ImGui::ShowMetricsWindow();

        app.render();
    }

    return 0;
}
