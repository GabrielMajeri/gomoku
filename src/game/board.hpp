#pragma once

#include "gfx/drawable.hpp"
#include <memory>

/// Stores a representation of the Gomoku board.
class Board : public Drawable {
    int rows, columns;

    enum class CellState {
        EMPTY,
        PLAYER1,
        PLAYER2,
    };

    std::unique_ptr<CellState[]> cells;

    CellState getCell(int row, int column) const;
    void setCell(int row, int column, CellState state);

public:
    /// Constructs a new Gomoku board of a certain dimension.
    Board(int rows, int columns);

    /// Draws the board to the screen.
    void draw(Renderer& r) const override;
};
