#include "error.hpp"

#include <SDL2/SDL_error.h>

SDLError::SDLError() : std::runtime_error(SDL_GetError()) {}

SDLError::SDLError(const std::string& msg)
    : std::runtime_error(msg + ": " + SDL_GetError()) {}
