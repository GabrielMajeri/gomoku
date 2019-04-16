#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"

/// Represents an enclosed rectangular portion of the screen.
class Window : public Wrapper<SDL_Window> {
public:
    /// Opens a new main window.
    Window();
};
