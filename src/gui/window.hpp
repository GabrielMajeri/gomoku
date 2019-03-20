#pragma once

#include "core/wrapper.hpp"

/// Represents an enclosed rectangular portion of the screen.
class Window : public Wrapper<struct SDL_Window> {
public:
    /// Opens a new main window.
    Window();
};
