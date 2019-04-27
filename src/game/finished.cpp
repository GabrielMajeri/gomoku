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
                  formatWinningPlayerString(winningPlayer), winningColor) {
    winnerLabel.setPosition(20, 10);
}

void FinishedState::draw(Renderer& r) const { winnerLabel.draw(r); }

void FinishedState::handleEvent(const SDL_Event& e) {
    winnerLabel.handleEvent(e);
}
