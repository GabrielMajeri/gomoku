#include "finished.hpp"

#include "game/game.hpp"

static std::string formatWinningPlayerString(int winner) {
    if (winner == 0) {
        return "Remiză";
    } else {
        return "Câștigător: jucător " + std::to_string(winner);
    }
}

FinishedState::FinishedState(Game& game, Renderer& r, int winningPlayer,
                             Color winningColor)
    : GameState(game),
      winnerLabel(r, game.getBigFont(),
                  formatWinningPlayerString(winningPlayer), winningColor),
      restartButton(r, game.getNormalFont(), "Restart joc") {
    winnerLabel.setPosition(20, 10);
    restartButton.setPosition(650, 150);
    restartButton.setClickHandler([&] { game.restartGame(); });
}

void FinishedState::draw(Renderer& r) const {
    winnerLabel.draw(r);
    restartButton.draw(r);
}

void FinishedState::handleEvent(const SDL_Event& e) {
    winnerLabel.handleEvent(e);
    restartButton.handleEvent(e);
}
