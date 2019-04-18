#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

/// RAII wrapper for the SDL2 library
class SDL {
public:
    /// Initializes the library's subsystems
    SDL();
    /// Shuts down SDL and cleans up any remaining resources
    ~SDL();

    /// Prints the version of SDL compiled against and the version of SDL
    /// present at runtime.
    void printVersionInfo();
};
