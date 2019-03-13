#pragma once

#include <SDL2/SDL_version.h>
#include <iostream>

/// Stores a version of the SDL library.
class Version : private SDL_version {
    Version() = default;

  public:
    /// Retrieves the version of the library the code was compiled with.
    static Version compiled();
    /// Retrieves the version of the library currently loaded dynamically
    /// in the process.
    static Version linked();

    friend std::ostream& operator<<(std::ostream& os, const Version& ver);
};
