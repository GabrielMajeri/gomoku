#include "credits.hpp"

#include "game/game.hpp"

CreditsMenuState::CreditsMenuState(Game& game, Renderer& r)
    : GameState(game),
      goBackButton(r, game.getNormalFont(), "Înapoi la meniu") {
    goBackButton.setPosition(100, 20);
    goBackButton.setClickHandler([&] { game.restartGame(); });

    labels.emplace_back(r, game.getNormalFont(),
                        "Joc realizat de Gabriel Majeri de la grupa 132",
                        Color::AQUA);
    labels.back().setPosition(100, 110);

    labels.emplace_back(r, game.getNormalFont(),
                        "Profesori coordonatori: Andrei Păun și Anca Dobrovăț",
                        Color::AQUA);
    labels.back().setPosition(100, 150);

    labels.emplace_back(r, game.getNormalFont(),
                        "Playtesting: Bogdan și Antonia", Color::AQUA);
    labels.back().setPosition(100, 180);

    labels.emplace_back(r, game.getNormalFont(),
                        "Biblioteci folosite: biblioteca standard C++, SDL2, "
                        "SDL_image și SDL_ttf",
                        Color::AQUA);
    labels.back().setPosition(100, 230);

    labels.emplace_back(r, game.getNormalFont(),
                        "Google Fonts pentru font-urile Acme și Roboto",
                        Color::AQUA);
    labels.back().setPosition(100, 260);
}

void CreditsMenuState::draw(Renderer& r) const {
    r.setDrawColor(Color::BLACK);
    r.fillRect(SDL_Rect{0, 0, 800, 600});
    for (const auto& label : labels) {
        label.draw(r);
    }
    goBackButton.draw(r);
}

void CreditsMenuState::handleEvent(const SDL_Event& e) {
    goBackButton.handleEvent(e);
}
