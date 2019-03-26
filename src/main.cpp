#include <iostream>

#include "core/sdl.hpp"
#include "gui/event.hpp"
#include "gui/renderer.hpp"
#include "gui/window.hpp"

#include <SDL.h>

void runGame() {
    SDL sdl;
    sdl.printVersionInfo();

    Window window;

    Renderer render{window};

    EventLoop loop;

    loop.run();
}

int main(int, char*[]) {
    try {
        runGame();
        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
