#pragma once

#include <stdexcept>

/// Custom exception for SDL2 API errors
class SDLError : public std::runtime_error {
public:
    /// Constructs a new error with the description taken from the last
    /// error status set by an SDL API call.
    SDLError();

    /// Constructs a new error by concatenating an error message with the last
    /// SDL error message.
    SDLError(const std::string& msg);
};
