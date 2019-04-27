#include "board.hpp"

#include "game/game.hpp"
#include "game/playing.hpp"
#include "gfx/color.hpp"
#include "gfx/renderer.hpp"
#include "gui/image.hpp"
#include <algorithm>

constexpr auto CELL_WIDTH = 25, CELL_HEIGHT = 25;

void Board::reportWin() {
    auto playing = static_cast<PlayingState*>(game.getState());
    game.finishGame(playing->getCurrentPlayer(), playing->getCurrentColor());
}

void Board::reportDraw() { game.finishGame(0, Color::WHITE); }

Board::Board(Game& game, int r, int c, Image& rp, Image& bp)
    : game{game}, rows{r}, columns{c}, redPiece{rp}, bluePiece{bp},
      cells(rows * columns) {
    setPosition(50, 50);
}

void Board::draw(Renderer& r) const {
    r.setDrawColor(Color::AQUA);

    const int startX = position.x, startY = position.y;
    const int endX = startX + columns * CELL_WIDTH,
              endY = startY + rows * CELL_HEIGHT;

    for (int row = 1; row < rows; ++row) {
        const int y = startY + row * CELL_HEIGHT;
        r.drawLine(startX, y, endX, y);
    }

    for (int col = 1; col < columns; ++col) {
        const int x = startX + col * CELL_WIDTH;
        r.drawLine(x, startY, x, endY);
    }

    r.drawLines({
        {startX, startY},
        {endX, startY},
        {endX, endY},
        {startX, endY},
        {startX, startY},
    });

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            int x = startX + col * CELL_WIDTH + 2,
                y = startY + row * CELL_HEIGHT + 2;
            if (getCell(row, col) == CellState::RED) {
                redPiece.setPosition(x, y);
                redPiece.draw(r);
            } else if (getCell(row, col) == CellState::BLUE) {
                bluePiece.setPosition(x, y);
                bluePiece.draw(r);
            }
        }
    }
}

void Board::handleEvent(const SDL_Event& e) {
    switch (e.type) {
    case SDL_MOUSEBUTTONUP: {
        const auto& mbu = e.button;
        if (mbu.button != SDL_BUTTON_LEFT) {
            break;
        }

        const auto bbox = getBoundingBox();
        const auto pt = SDL_Point{mbu.x, mbu.y};

        if (SDL_PointInRect(&pt, &bbox)) {
            int row = (pt.y - bbox.y) / CELL_HEIGHT,
                col = (pt.x - bbox.x) / CELL_WIDTH;

            if (getCell(row, col) == CellState::EMPTY) {
                auto playing = dynamic_cast<PlayingState*>(game.getState());
                if (playing) {
                    playing->onBoardClicked(*this, row, col);
                }
            }
        }
    } break;
    default:
        break;
    }
}

void Board::checkWin() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns - 4; ++col) {
            auto first = getCell(row, col);

            if (first == CellState::EMPTY) {
                continue;
            }

            bool ok = true;
            for (int k = 1; ok && k < 5; ++k) {
                if (getCell(row, col + k) != first) {
                    ok = false;
                }
            }
            if (ok) {
                reportWin();
                return;
            }
        }
    }

    for (int row = 0; row < rows - 4; ++row) {
        for (int col = 0; col < columns; ++col) {
            auto first = getCell(row, col);

            if (first == CellState::EMPTY) {
                continue;
            }

            bool ok = true;
            for (int k = 1; ok && k < 5; ++k) {
                if (getCell(row + k, col) != first) {
                    ok = false;
                }
            }
            if (ok) {
                reportWin();
                return;
            }
        }
    }

    for (int row = 0; row < rows - 4; ++row) {
        for (int col = 0; col < columns - 4; ++col) {
            auto first = getCell(row, col);

            if (first == CellState::EMPTY) {
                continue;
            }

            bool ok = true;
            for (int k = 1; ok && k < 5; ++k) {
                if (getCell(row + k, col + k) != first) {
                    ok = false;
                }
            }
            if (ok) {
                reportWin();
                return;
            }
        }
    }

    for (int row = 0; row < rows - 4; ++row) {
        for (int col = 4; col < columns; ++col) {
            auto first = getCell(row, col);

            if (first == CellState::EMPTY) {
                continue;
            }

            bool ok = true;
            for (int k = 1; ok && k < 5; ++k) {
                if (getCell(row + k, col - k) != first) {
                    ok = false;
                }
            }
            if (ok) {
                reportWin();
                return;
            }
        }
    }

    // Game is drawn, no more possible moves
    if (std::find(cells.begin(), cells.end(), CellState::EMPTY) ==
        cells.end()) {
        reportDraw();
    }
}

void Board::reset() { std::fill(cells.begin(), cells.end(), CellState::EMPTY); }

CellState Board::getCell(int row, int column) const {
    return cells[row * columns + column];
}

void Board::setCell(int row, int column, CellState state) {
    cells[row * columns + column] = state;
}

int Board::getWidth() const { return columns * CELL_WIDTH; }

int Board::getHeight() const { return rows * CELL_HEIGHT; }
