#include "redtangle_app.h"
#include "redtangle.h"
#include "redtangle_ui_sdl.h"
#include "redtangle_ui_imgui.h"

static const int WINDOW_WIDTH = 1000;
static const int WINDOW_HEIGHT = 800; 

#define IMGUI_IMPL

// Main loop
void redtangle_app::run() {

    #ifndef IMGUI_IMPL
        std::shared_ptr<redtangle::RedtangleUI> ui = std::make_shared<RedtangleUI_SDL>(WINDOW_WIDTH, WINDOW_HEIGHT); 
    #else 
        std::shared_ptr<redtangle::RedtangleUI> ui = std::make_shared<RedtangleUI_Imgui>(WINDOW_WIDTH, WINDOW_HEIGHT); 
    #endif 
    std::unique_ptr<redtangle::Redtangle> game = std::make_unique<redtangle::RedtangleGame>(); 
    game->render_board(ui); 
    bool quit = false;
    while (!quit) {
        while (ui->poll_event()) {
            switch (ui->get_eventType()) {
                case redtangle::RedtangleUI::EventType::QUIT : {
                    quit = true;
                    break;
                }
                case redtangle::RedtangleUI::EventType::SELECTION : {
                    game->select(ui->get_location()); 
                    break;
                }
                case redtangle::RedtangleUI::EventType::ROTATION_CLOCKWISE : {
                    game->rotate(true);
                    break;
                }
                case redtangle::RedtangleUI::EventType::ROTATION_COUNTERCLOCKWISE : {
                    game->rotate(false); 
                    break;
                }
                case redtangle::RedtangleUI::EventType::END_TURN : {
                    game->end_turn(); 
                    break;
                }
            }
        }
        game->render_board(ui); 
    }
}