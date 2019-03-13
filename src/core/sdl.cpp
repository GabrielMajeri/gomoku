#include "sdl.hpp"

#include "error.hpp"
#include "version.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL::SDL() {
    const Uint32 flags = 0;
    if (SDL_Init(flags) != 0) {
        throw SDLError("Unable to initialize SDL");
    }
}

SDL::~SDL() { SDL_Quit(); }

void SDL::printVersionInfo() {
    std::cout << "Compiled against SDL " << Version::compiled() << '\n'
              << "Dynamically linked against SDL " << Version::linked() << '\n'
              << std::flush;
}
