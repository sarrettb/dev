set(REDTANGLE_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS}
                           "."
                           "app"
                           "game"
                           "piece"
                           "ui"
    )
set(REDTANGLE_SOURCES redtangle.cpp
            app/redtangle_app.cpp
            game/redtangle_local.cpp
            piece/empty_piece.cpp
            piece/redtangle_piece.cpp
            ui/redtangle_ui_sdl.cpp
    )
add_executable(redtangle ${REDTANGLE_SOURCES}) 
include_directories(redtangle ${REDTANGLE_INCLUDE_DIRS})
target_link_libraries(redtangle ${SDL2_LIBRARIES})