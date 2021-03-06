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

void PlayingState::goToNextMove() {
    if (moveCount == 2) {
        waitingForInput = true;
    }

    if (passOption && moveCount == 4) {
        waitingForInput = true;
        swap1 = true;
        passOption = false;
        flipColor();
    }

    ++moveCount;

    if (moveCount < 3 || passOption) {
        flipColor();
    } else {
        flipPlayer();
        flipColor();
    }
}

PlayingState::PlayingState(Game& game, Renderer& r, bool swap1)
    : GameState(game), swap1(swap1),
      currentPlayerLabel(r, game.getNormalFont(), formatCurrentPlayerString(),
                         Color::RED),
      messageLabel(r, game.getNormalFont(), "Alegeți o opțiune:", Color::WHITE,
                   120),
      restartButton(r, game.getNormalFont(), "Restart joc"),
      skipButton(r, game.getNormalFont(), "Pas"),
      drawButton(r, game.getNormalFont(), "Propune remiză"),
      acceptDrawButton(r, game.getNormalFont(), "Acceptă remiză"),
      rejectDrawButton(r, game.getNormalFont(), "Refuză remiză"),
      option1Button(r, game.getNormalFont(), "Păstrează culoarea"),
      option2Button(r, game.getNormalFont(), "Schimbă culoarea"),
      option3Button(r, game.getNormalFont(),
                    "Mai pune piese și lasă oponentul să aleagă culoarea") {
    currentPlayerLabel.setPosition(20, 20);

    messageLabel.setPosition(650, 100);

    restartButton.setPosition(650, 400);
    restartButton.setClickHandler([&] { game.restartGame(); });

    skipButton.setPosition(650, 150);
    skipButton.setClickHandler([&] { goToNextMove(); });

    drawButton.setPosition(650, 210);
    drawButton.setClickHandler([&] {
        drawProposed = true;
        flipPlayer();
        flipColor();
    });

    acceptDrawButton.setPosition(650, 150);
    acceptDrawButton.setClickHandler([&] { game.finishGame(0, Color::WHITE); });

    rejectDrawButton.setPosition(650, 210);
    rejectDrawButton.setClickHandler([&] {
        drawProposed = false;
        flipPlayer();
        flipColor();
    });

    option1Button.setPosition(650, 150);
    option1Button.setClickHandler([&] { waitingForInput = false; });

    option2Button.setPosition(650, 210);
    option2Button.setClickHandler([&] {
        flipColor();
        waitingForInput = false;
    });

    option3Button.setPosition(650, 270);
    option3Button.setClickHandler([&] {
        passOption = true;
        waitingForInput = false;
    });
}

int PlayingState::getCurrentPlayer() const { return currentPlayer; }

Color PlayingState::getCurrentColor() const { return currentColor; }

void PlayingState::draw(Renderer& r) const {
    currentPlayerLabel.draw(r);
    restartButton.draw(r);
    if (waitingForInput) {
        messageLabel.draw(r);
        option1Button.draw(r);
        option2Button.draw(r);
        if (!swap1) {
            option3Button.draw(r);
        }
    } else {
        if (drawProposed) {
            acceptDrawButton.draw(r);
            rejectDrawButton.draw(r);
        } else {
            skipButton.draw(r);
            drawButton.draw(r);
        }
    }
}

void PlayingState::handleEvent(const SDL_Event& e) {
    currentPlayerLabel.handleEvent(e);
    restartButton.handleEvent(e);
    if (waitingForInput) {
        option1Button.handleEvent(e);
        option2Button.handleEvent(e);
        if (!swap1) {
            option3Button.handleEvent(e);
        }
    } else {
        if (drawProposed) {
            acceptDrawButton.handleEvent(e);
            rejectDrawButton.handleEvent(e);
        } else {
            skipButton.handleEvent(e);
            drawButton.handleEvent(e);
        }
    }
}

void PlayingState::onBoardClicked(Board& b, int row, int col) {
    if (waitingForInput || drawProposed) {
        return;
    }

    b.setCell(row, col, colorToCellState());

    b.checkWin();

    goToNextMove();
}
