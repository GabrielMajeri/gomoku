#include "sdl.hpp"

#include "version.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL::SDL() {
    const Uint32 flags = 0;
    if (SDL_Init(flags) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

SDL::~SDL() { SDL_Quit(); }

void SDL::printVersionInfo() {
    std::cout << "Compiled against SDL " << Version::compiled() << '\n'
              << "Dynamically linked against SDL " << Version::linked() << '\n'
              << std::flush;
}
