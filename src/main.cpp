#include <iostream>

#include "core/sdl.hpp"
#include "game/game.hpp"

void runGame() {
    SDL sdl;
    sdl.printVersionInfo();

    Game game;
    game.run();
}

int main(int, char*[]) {
    try {
        runGame();
        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;

        std::string title = "Eroare Gomoku";
        std::string message =
            "Jocul a întâmpinat o eroare și a trebuit să se inchidă:\n";
        message += e.what();

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title.c_str(),
                                 message.c_str(), nullptr);

        return EXIT_FAILURE;
    }
}
