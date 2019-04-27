#include "main_menu.hpp"

#include "game/credits.hpp"
#include "game/game.hpp"
#include "game/playing.hpp"

MainMenuState::MainMenuState(Game& game, Renderer& r)
    : GameState(game), swap1Button(r, game.getNormalFont(), "Joc cu SWAP1"),
      swap2Button(r, game.getNormalFont(), "Joc cu SWAP2"),
      creditsButton(r, game.getNormalFont(), "Credits"),
      exitButton(r, game.getNormalFont(), "Ieși din joc"),
      mainMenuText(r, game.getNormalFont(), "Meniu principal", Color::WHITE) {
    mainMenuText.setPosition(650, 100);

    swap1Button.setPosition(640, 150);
    swap1Button.setClickHandler([&] {
        game.changeState(std::make_unique<PlayingState>(game, r, true));
    });

    swap2Button.setPosition(640, 220);
    swap2Button.setClickHandler([&] {
        game.changeState(std::make_unique<PlayingState>(game, r, false));
    });

    creditsButton.setPosition(650, 300);
    creditsButton.setClickHandler(
        [&] { game.changeState(std::make_unique<CreditsMenuState>(game, r)); });

    exitButton.setPosition(650, 380);
    exitButton.setClickHandler([&] { game.exit(); });
}

void MainMenuState::draw(Renderer& r) const {
    mainMenuText.draw(r);
    swap1Button.draw(r);
    swap2Button.draw(r);
    creditsButton.draw(r);
    exitButton.draw(r);
}

void MainMenuState::handleEvent(const SDL_Event& e) {
    swap1Button.handleEvent(e);
    swap2Button.handleEvent(e);
    creditsButton.handleEvent(e);
    exitButton.handleEvent(e);
}
