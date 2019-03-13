#pragma once

/// RAII wrapper for the SDL2 library
class SDL {
  public:
    /// Initializes the library's subsystems
    SDL();
    /// Shuts down SDL and cleans up any remaining resources
    ~SDL();
};
