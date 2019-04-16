#include "sdl.hpp"

#include "error.hpp"
#include "version.hpp"
#include <iostream>

SDL::SDL() {
    const Uint32 flags = SDL_INIT_EVENTS | SDL_INIT_VIDEO;
    if (SDL_Init(flags) != 0) {
        throw SDLError("Unable to initialize SDL");
    }
    const Uint32 imgFlags = IMG_INIT_PNG;
    if (IMG_Init(imgFlags) != imgFlags) {
        throw SDLImageError("Unable to initialize SDL_image");
    }
    if (TTF_Init() != 0) {
        throw SDLFontError("Unable to initialize SDL_ttf");
    }
}

SDL::~SDL() { SDL_Quit(); }

void SDL::printVersionInfo() {
    std::cout << "Compiled against SDL " << Version::compiled() << '\n'
              << "Dynamically linked against SDL " << Version::linked() << '\n'
              << std::flush;
}
