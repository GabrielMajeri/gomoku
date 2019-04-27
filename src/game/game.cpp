#include "game.hpp"

#include "core/error.hpp"
#include "game/main_menu.hpp"
#include "gfx/renderer.hpp"

Game::Game()
    : rdr(window), titleFont("assets/fonts/Acme-Regular.ttf", 32),
      normalFont("assets/fonts/Roboto-Regular.ttf", 20),
      titleText(rdr, titleFont, "Gomoku", Color::AQUA),
      redPiece("assets/images/red.png", rdr, 22, 22),
      bluePiece("assets/images/blue.png", rdr, 22, 22),
      board(*this, 20, 23, redPiece, bluePiece),
      state(std::make_unique<MainMenuState>(*this, rdr)) {
    titleText.setPosition(300, 0);
}

void Game::run() {
    running = true;

    while (running) {
        SDL_Event event;
        if (SDL_WaitEvent(&event) == 0) {
            throw SDLError("Failed to wait for event");
        }

        if (event.type == SDL_QUIT) {
            exit();
        }

        board.handleEvent(event);
        state->handleEvent(event);

        rdr.setDrawColor(Color::BLACK);
        rdr.clear();

        titleText.draw(rdr);
        board.draw(rdr);
        state->draw(rdr);

        rdr.present();

        if (deletedState) {
            deletedState.release();
        }
    }
}

void Game::exit() { running = false; }

void Game::resetBoard() { board.reset(); }

GameState* Game::getState() { return state.get(); }

void Game::changeState(std::unique_ptr<GameState>&& newState) {
    deletedState = std::exchange(state, std::move(newState));
}

const Font& Game::getTitleFont() const { return titleFont; }

const Font& Game::getNormalFont() const { return normalFont; }
