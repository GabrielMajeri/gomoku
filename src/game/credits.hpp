#pragma once

#include "game/state.hpp"
#include "gui/button.hpp"
#include "gui/label.hpp"
#include <vector>

/// Screen displaying credits for the game.
class CreditsMenuState : public GameState {
    std::vector<Label> labels;
    Button goBackButton;

public:
    CreditsMenuState(Game& game, Renderer& r);

    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;
};
