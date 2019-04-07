#pragma once

#include <stdexcept>

/// Custom exception for SDL2 API errors
class SDLError : public std::runtime_error {
public:
    /// Constructs a new error by concatenating an error message with the last
    /// SDL error message.
    SDLError(const std::string& msg);
};

/// Custom exception class for SDL_image API errors
class SDLImageError : public std::runtime_error {
public:
    /// Constructs a new error from the given message and the last reported
    /// SDL_image error.
    SDLImageError(const std::string& msg);
};
