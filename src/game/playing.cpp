#include "playing.hpp"

#include "game/game.hpp"

std::string PlayingState::formatCurrentPlayerString() const {
    return "Jucător curent: " + std::to_string(currentPlayer);
}

CellState PlayingState::colorToCellState() const {
    return currentColor == Color::RED ? CellState::RED : CellState::BLUE;
}

void PlayingState::flipPlayer() {
    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
    currentPlayerLabel.setText(formatCurrentPlayerString());
}

void PlayingState::flipColor() {
    if (currentColor == Color::RED) {
        currentColor = Color::AQUA;
    } else {
        currentColor = Color::RED;
    }
    currentPlayerLabel.setColor(currentColor);
}

PlayingState::PlayingState(Game& game, Renderer& r, bool swap1)
    : GameState(game), swap1(swap1), currentPlayer(1), currentColor(Color::RED),
      currentPlayerLabel(r, game.getNormalFont(), formatCurrentPlayerString(),
                         Color::RED) {
    game.resetBoard();
    currentPlayerLabel.setPosition(20, 20);
}

int PlayingState::getCurrentPlayer() const { return currentPlayer; }

Color PlayingState::getCurrentColor() const { return currentColor; }

void PlayingState::draw(Renderer& r) const { currentPlayerLabel.draw(r); }

void PlayingState::handleEvent(const SDL_Event& e) {
    currentPlayerLabel.handleEvent(e);
}

void PlayingState::onBoardClicked(Board& b, int row, int col) {
    b.setCell(row, col, colorToCellState());

    b.checkWin();

    flipPlayer();
    flipColor();
}
