#include "redtangle_app.h"
#include "redtangle.h"
#include "redtangle_ui_sdl.h"

static const int WINDOW_WIDTH = 600;
static const int WINDOW_HEIGHT = 600; 

// Main loop
void redtangle_app::run() {
    std::shared_ptr<redtangle::RedtangleUI> ui = std::make_shared<RedtangleUI_SDL>(WINDOW_WIDTH, WINDOW_HEIGHT); 
    std::unique_ptr<redtangle::Redtangle> game = std::make_unique<redtangle::RedtangleGame>(); 
    game->render_board(ui); 
    bool quit = false;
    while (!quit && ui->wait_onEvent()) {
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
        game->render_board(ui); 
    }
}