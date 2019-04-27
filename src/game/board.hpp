#pragma once

#include "gui/widget.hpp"
#include <functional>
#include <vector>

class Game;
class Image;

enum class CellState : unsigned {
    EMPTY,
    RED,
    BLUE,
};

/// Stores a representation of the Gomoku board.
class Board : public Widget {
    Game& game;

    int rows, columns;
    Image& redPiece;
    Image& bluePiece;

    std::vector<CellState> cells;

public:
    /// Constructs a new Gomoku board of a certain dimension.
    Board(Game& game, int rows, int columns, Image& p1, Image& p2);

    /// Draws the board to the screen.
    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;

    /// Clears all the cells to be empty.
    void reset();

    CellState getCell(int row, int column) const;
    void setCell(int row, int column, CellState state);

    int getWidth() const override;
    int getHeight() const override;
};
