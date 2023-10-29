#include "apps/redtangle_builder.h"
#include "game/redtangle.h"
#include "game/redtangle_remote.h"
#include "ui/redtangle_ui_sdl.h"
#include "ui/redtangle_ui_imgui.h"

RedtangleBuilder::RedtangleBuilder(GameType game_type, UIType ui_type) {
    set_gameType(game_type);
    set_UIType(ui_type); 
}

void RedtangleBuilder::build() {
    if (_game_type == GameType::REMOTE) {
        if (_ui_type == UIType::SDL) {
            throw std::invalid_argument("SDL is not supported when running Redtangle remotely\n.");
        }
        std::shared_ptr<RedtangleUI_Imgui> imgui_ui = std::make_shared<RedtangleUI_Imgui>(_icon_path);
        RemotePopupInfo info = imgui_ui->RemotePopup(); 
        auto remote_game = std::make_shared<RedtangleRemote>(info.user_name, info.ip_address, info.port);
        imgui_ui->InitBoard();  
        _game = remote_game;
        _ui = imgui_ui; 
    }
    else {
        _game = std::make_shared<redtangle::RedtangleGame>();
        _ui = _ui_type == UIType::SDL ? std::make_shared<RedtangleUI_SDL>() : std::make_shared<RedtangleUI_Imgui>(_icon_path);
    }
}