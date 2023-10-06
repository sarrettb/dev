#include "redtangle_ui_imgui.h"

using redtangle::Point; 

static const int STATUS_BAR_HEIGHT = 50;
static const int BORDER_WIDTH = 2; 

RedtangleUI_Imgui::RedtangleUI_Imgui(int width, int height) :  RedtangleUI_SDL(width, height) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    _io = ImGui::GetIO();
    _io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     
    _io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    ImGui::StyleColorsLight(); 
    ImGui_ImplSDL2_InitForSDLRenderer(_window, _renderer);
    ImGui_ImplSDLRenderer2_Init(_renderer); 
    calculate_surfaces(); 
}

void RedtangleUI_Imgui::calculate_surfaces() {
    // Call show to update width height of surfaces
    // This is the only known way to get the height of the menu bar
    show();
    SDL_GetWindowSize(_window, &_window_width, &_window_height);
    _redtangle_surface = { BORDER_WIDTH, 
                           _menuBar_surface.top_left.y + _menuBar_surface.h + 1, 
                           _window_width - BORDER_WIDTH + 1, 
                           _window_height - _menuBar_surface.h - STATUS_BAR_HEIGHT
                         }; 
    coerce_redtangleSurface(); 
    SDL_SetWindowSize(_window, 2 * BORDER_WIDTH + _redtangle_surface.w, _window_height); 
    SDL_GetWindowSize(_window, &_window_width, &_window_height);
    _statusBar_surface = {0, 
                          _redtangle_surface.top_left.y + _redtangle_surface.h + 1,
                          _window_width,
                          _window_height - (_redtangle_surface.top_left.y + _redtangle_surface.h)
                         };
}

bool RedtangleUI_Imgui::poll_event() {
    bool result = RedtangleUI_SDL::poll_event(); 
    ImGui_ImplSDL2_ProcessEvent(&_event);
    return result;
}

void RedtangleUI_Imgui::show() {
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame(); 
    render_menuBar();
    render_statusBar(); 
    ImGui::Render();
    SDL_RenderSetScale(_renderer, _io.DisplayFramebufferScale.x, _io.DisplayFramebufferScale.y);
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    SDL_RenderPresent(_renderer); 
}

void RedtangleUI_Imgui::render_menuBar() {
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("Redtangle Directions")) {
                system("xdg-open https://github.com/sarrettb/dev/blob/main/projects/redtangle-cpp/docs/directions.pdf");
            }
            if (ImGui::MenuItem("Redtangle Controls")) {
                system("xdg-open https://github.com/sarrettb/dev/blob/main/projects/redtangle-cpp/docs/controls.md");
            } 
            ImGui::EndMenu();
        }
        auto size = ImGui::GetWindowSize();
        _menuBar_surface.w = size.x;
        _menuBar_surface.h = size.y;
        ImGui::EndMainMenuBar();
    }
}

void RedtangleUI_Imgui::render_statusBar() {
    bool is_open = false;
    ImGui::Begin("Redtangle Status", &is_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);   
    ImGui::SetWindowPos({_statusBar_surface.top_left.x, _statusBar_surface.top_left.y });  
    ImGui::SetWindowSize({_statusBar_surface.w, _statusBar_surface.h}); 
    ImGui::Text(_status.c_str());
    ImGui::End();
}

void RedtangleUI_Imgui::resizeWindow() {
    calculate_surfaces(); 
}

