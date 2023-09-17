#include <SDL2/SDL.h>
#include "redtangle_ui_sdl.h"

using redtangle::Point; 
using redtangle::Circle; 
using redtangle::Rect; 
using redtangle::Color; 

bool in_circle(const SDL_Point& point, const Circle& circle); 
void add_circlePoints(std::vector<SDL_Point>& points, const Circle& circle); 
void add_filledCirclePoints(std::vector<SDL_Point>& points, const Circle& circle);
SDL_Color color_toSDLColor(const Color& color);  
void insert_sdlError(); 

// Create the window and renderer
RedtangleUI_SDL::RedtangleUI_SDL(int width, int height) : RedtangleUI(width, height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        insert_sdlError(); 
    }
    _window = SDL_CreateWindow("Redtangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0); 
    _renderer = SDL_CreateRenderer(_window, -1, 0); 
}

bool RedtangleUI_SDL::wait_onEvent(){
    return SDL_WaitEvent(&_event);
}

redtangle::Location RedtangleUI_SDL::get_location() const {
    return { _event.button.x / _rect_width, _event.button.y / _rect_height }; 
}

// Show the updated screen 
void RedtangleUI_SDL::show() {
    SDL_RenderPresent(_renderer); 
}

// Clear the screen 
void RedtangleUI_SDL::clear() { 
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer); 
}

redtangle::RedtangleUI::EventType RedtangleUI_SDL::get_eventType() const {
    switch (_event.type) {
        case SDL_QUIT:
            return redtangle::RedtangleUI::EventType::QUIT; 
        case SDL_MOUSEBUTTONDOWN:
            if (_event.button.button == SDL_BUTTON_LEFT) {
                return RedtangleUI::EventType::SELECTION; 
            }
            else if (_event.button.button == SDL_BUTTON_RIGHT) {
                return RedtangleUI::EventType::END_TURN; 
            }
            else {
                return RedtangleUI::EventType::UNKNOWN; 
            }
        case SDL_MOUSEWHEEL:
            std::cout << "Rotation detected" << std::endl; 
            return _event.wheel.y > 0 ? RedtangleUI::EventType::ROTATION_CLOCKWISE : RedtangleUI::EventType::ROTATION_COUNTERCLOCKWISE;
        default:
            return RedtangleUI::EventType::UNKNOWN;
    }
}

// Render a filled rectangle with given color 
void RedtangleUI_SDL::render_filledRect(const Rect& rect, const Color& color) const {
    SDL_Rect sdl_rect = { rect.top_left.x, rect.top_left.y, rect.w, rect.h }; 
    SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, 255); 
    SDL_RenderFillRect(_renderer, &sdl_rect); 
}

// Render a filled circle with given color 
void RedtangleUI_SDL::render_filledCircle(const redtangle::Circle& circle, const redtangle::Color& color) const {
    std::vector<SDL_Point> points;
    add_filledCirclePoints(points, circle); // adds points on the edge of the circle
    add_circlePoints(points, circle); // adds points inside the edge
    SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, 255); 
    SDL_RenderDrawPoints(_renderer, points.data(), points.size());
}

// Renders a filled triangle with given color 
void RedtangleUI_SDL::render_filledTriangle(const std::vector<Point>& vertices, const Color& color) const  {
    SDL_Color c = color_toSDLColor(color); 
    SDL_Vertex verts[3] = {
                            { SDL_FPoint{ (float) vertices[0].x, (float) vertices[0].y }, c, SDL_FPoint{ 0 } },
                            { SDL_FPoint{ (float) vertices[1].x, (float) vertices[1].y }, c, SDL_FPoint{ 0 } },
                            { SDL_FPoint{ (float) vertices[2].x, (float) vertices[2].y }, c, SDL_FPoint{ 0 } }
                          };
    SDL_RenderGeometry(_renderer, nullptr, verts, 3, nullptr, 0); 
}

// Destroy UI 
RedtangleUI_SDL::~RedtangleUI_SDL() {
  SDL_DestroyRenderer(_renderer); 
  SDL_DestroyWindow(_window);
  SDL_Quit(); 
}

// return true if the point lies on or inside the circle
bool in_circle(const SDL_Point& point, const Circle& circle) {
    return pow(point.x - circle.center.x, 2) + pow(point.y - circle.center.y, 2) - circle.r * circle.r <= 0; 
}

// Adapted mid-point circle drawing algorithm for SDL2
// Source: https://www.geeksforgeeks.org/mid-point-circle-drawing-algorithm/
// Detailed Algorithm Explanation: https://sachithradangalla.medium.com/mid-point-algorithm-how-to-draw-a-circle-b6ed7c47c803 
void add_circlePoints(std::vector<SDL_Point>& points, const Circle& circle) {
    int x = circle.r;
    int y = 0;

    if (circle.r > 0) {
        points.push_back({x + circle.center.x, y + circle.center.y}); 
        points.push_back({y + circle.center.x, x + circle.center.y}); 
        points.push_back({-y + circle.center.x, x + circle.center.y}); 
    }
     
    // Initialize the value of P
    int P = 1 - circle.r;
    while (x > y)
    {
        y++;
         
        // Mid-point is inside or on the perimeter
        if (P <= 0) {
            P = P + 2*y + 1;
        }
        // Mid-point is outside the perimeter
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
         
        // All the perimeter points have already been printed
        if (x < y) {
            break;
        }
         
        // Generated points and its reflection in the other octants after translation
        points.push_back({x + circle.center.x, y + circle.center.y});
        points.push_back({-x + circle.center.x, y + circle.center.y});
        points.push_back({x + circle.center.x, -y + circle.center.y});
        points.push_back({-x + circle.center.x, -y + circle.center.y});
         
        // If the generated point is on the line x = y then the perimeter points have already been generated
        if (x != y) {
            points.push_back({y + circle.center.x, x + circle.center.y});
            points.push_back({-y + circle.center.x, x + circle.center.y});
            points.push_back({y + circle.center.x, -x + circle.center.y});
            points.push_back({-y + circle.center.x, -x + circle.center.y});
        }
    }
}

// Traverses a rectangle bounded by a circle. 
// If the point is on or inside the circle, then add it to the list of points
void add_filledCirclePoints(std::vector<SDL_Point>& points, const Circle& circle) {
   for (int y = circle.center.y - circle.r; y <= circle.center.y + circle.r; y++) {
       for (int x = circle.center.x - circle.r; x <= circle.center.x + circle.r; x++) {
            SDL_Point point = {x, y}; 
            if (in_circle(point, circle)) {
                points.push_back(point); 
            }
        }
   }
}

// Converts redtangle::Color to SDL_Color
SDL_Color color_toSDLColor(const Color& color) {
    return { color.red, color.green, color.blue, 255 }; 
}

void insert_sdlError() {
    throw std::runtime_error(SDL_GetError()); 
}