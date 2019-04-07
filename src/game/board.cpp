#include "board.hpp"

#include "gfx/color.hpp"
#include "gfx/renderer.hpp"
#include <SDL.h>

Board::Board(int r, int c)
    : rows{r}, columns{c}, cells{new CellState[rows * columns]} {}

Board::CellState Board::getCell(int row, int column) const {
    return cells[row * columns + column];
}

void Board::setCell(int row, int column, Board::CellState state) {
    cells[row * columns + column] = state;
}

void Board::draw(Renderer& r) const {
    r.setDrawColor(Color::AQUA);

    const int startX = 50, startY = 50;
    const int cellWidth = 25, cellHeight = 25;
    const int endX = startX + columns * cellWidth,
              endY = startY + rows * cellHeight;

    for (int row = 1; row < rows; ++row) {
        const int y = startY + row * cellHeight;
        r.drawLine(startX, y, endX, y);
    }

    for (int col = 1; col < columns; ++col) {
        const int x = startX + col * cellWidth;
        r.drawLine(x, startY, x, endY);
    }

    r.drawLines({
        {startX, startY},
        {endX, startY},
        {endX, endY},
        {startX, endY},
        {startX, startY},
    });
}
