#pragma once

#include "game/state.hpp"
#include "gui/button.hpp"
#include "gui/label.hpp"

class FinishedState : public GameState {
    Label winnerLabel;
    Button restartButton;

public:
    FinishedState(Game& game, Renderer& r, int winningPlayer,
                  Color winningColor);

    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;
};
