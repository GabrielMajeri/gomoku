#include <iostream>

#include "core/sdl.hpp"
#include "gui/renderer.hpp"
#include "gui/window.hpp"

#include <SDL2/SDL.h>

int main() {
    SDL sdl;
    sdl.printVersionInfo();

    Window window;

    Renderer render{window};

    SDL_Delay(3000);
}
