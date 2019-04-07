#include "error.hpp"

#include <SDL.h>
#include <SDL_image.h>

SDLError::SDLError(const std::string& msg)
    : std::runtime_error(msg + ": " + SDL_GetError()) {}

SDLImageError::SDLImageError(const std::string& msg)
    : std::runtime_error(msg + ": " + IMG_GetError()) {}
