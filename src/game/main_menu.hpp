#pragma once

#include "game/state.hpp"
#include "gui/button.hpp"
#include "gui/label.hpp"

class MainMenuState : public GameState {
    Button swap1Button, swap2Button, creditsButton, exitButton;
    Label mainMenuText;

public:
    MainMenuState(Game& game, Renderer& r);

    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;
};
