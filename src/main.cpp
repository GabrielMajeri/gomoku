#include <iostream>

#include "core/sdl.hpp"
#include "gui/window.hpp"

#include <SDL2/SDL.h>

int main() {
    SDL sdl;
    sdl.printVersionInfo();

    Window window;

    SDL_Delay(3000);
}
