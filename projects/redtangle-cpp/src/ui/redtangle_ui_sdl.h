#pragma once
#include <SDL2/SDL.h>
#include "redtangle.h"

// Redtangle UI implemenation using the SDL library 
class RedtangleUI_SDL : public redtangle::RedtangleUI {
    protected:
        SDL_Window* _window; 
        SDL_Renderer* _renderer; 
        SDL_Event _event; 
    public: 
        RedtangleUI_SDL(int width, int height); 
        ~RedtangleUI_SDL() override; 
        RedtangleUI::EventType get_eventType() const override;
        redtangle::Location get_location() const override; 
        bool wait_onEvent() override; 
        void show() override; 
        void clear() override; 
        void render_filledRect(const redtangle::Rect& rect, const redtangle::Color& color) const override;
        void render_filledCircle(const redtangle::Circle& circle, const redtangle::Color& color) const override;
        void render_filledTriangle(const std::vector<redtangle::Point>& vertices, const redtangle::Color& color) const override;
}; 