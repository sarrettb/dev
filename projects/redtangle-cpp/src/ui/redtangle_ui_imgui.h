#pragma once
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include "redtangle_ui_sdl.h"

// Extend the RedtangleUI_SDL to provide a status message and menu options 
class RedtangleUI_Imgui : public RedtangleUI_SDL {
    protected: 
        redtangle::Rect _menuBar_surface;  
        redtangle::Rect _statusBar_surface;
        std::string _status; 
        ImGuiIO _io; 
        void calculate_surfaces(); 
        void render_menuBar();
        void render_statusBar(); 
        void resizeWindow() override; 
    public:
        RedtangleUI_Imgui(int width, int height, std::filesystem::path exe_path = std::filesystem::path());
        void set_status(const std::string& status) override { _status = status; }
        bool poll_event() override;   
        void show() override; 
};