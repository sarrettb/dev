#pragma once

namespace redtangle_ui {
    struct Rect {
        int x, y, w, h;
    };
    struct Circle {
        int x, y, r;
    };
    struct Color {
        int red, green, blue; 
        bool operator == (const Color& c) const {return this->red == c.red && this->blue == c.blue && this->green == c.green; }
        bool operator != (const Color& c) const {return this->red != c.red && this->blue != c.blue && this->green != c.green; } 
    };

    static const Color BLACK = { 0, 0, 0 }; 
    static const Color WHITE = { 255, 255, 255 }; 
    static const Color RED = {255, 0, 0};
    static const Color GOLD = {255, 215, 0}; 
    static const Color NONE = {-1, -1, -1 }; 
    
    // Interface for rendering the redtangle game
    // One implementation will be to run the game headless (no UI) which will be used by the gRPC Server 
    // Another implementation will use SDL2 to render the UI 
    // Any other rendering libraries could be used by making a class that inherits from Redtangle_UI
    class Redtangle_UI {
        public: 
            virtual void render_filledRect(const Rect& rect, const Color& color) const = 0; 
            virtual void render_filledCircle(const Circle& circle, Color& color) const = 0;
    }; 
}