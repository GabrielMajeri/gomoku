#pragma once

#include <memory>

struct SDL_Window;

/// Represents an enclosed rectangular portion of the screen.
class Window {
    struct WindowDeleter {
        void operator()(SDL_Window* window);
    };

    std::unique_ptr<SDL_Window, WindowDeleter> handle;

public:
    /// Opens a new main window.
    Window();
};
