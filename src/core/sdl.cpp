#include "sdl.hpp"

#include <SDL2/SDL.h>

SDL::SDL() {
    const Uint32 flags = 0;
    if (SDL_Init(flags) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

SDL::~SDL() { SDL_Quit(); }
