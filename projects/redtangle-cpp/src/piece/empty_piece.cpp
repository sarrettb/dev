#include "redtangle.h"

// Renders the squares background 
void redtangle::EmptyPiece::render(const std::shared_ptr<RedtangleUI> ui, const Location& location) const {
    const int RECT_WIDTH = ui->get_rectWidth();
    const int RECT_HEIGHT = ui->get_rectHeight(); 
    const int EDGE_SIZE = ui->get_edgeSize(); 
    Rect rect = { location.x * RECT_WIDTH,
                      location.y * RECT_HEIGHT,
                      RECT_WIDTH - EDGE_SIZE,
                      RECT_HEIGHT - EDGE_SIZE
                };              
    ui->render_filledRect(rect, in_redtangle(location) ? RED : GOLD); 
}