#include "window.hpp"

#include "core/error.hpp"
#include <SDL2/SDL_video.h>

Window::Window() {
    const char title[] = "Connect Five";
    const int x = 0, y = 0;
    const int width = 800, height = 600;
    const Uint32 flags = 0;
    SDL_Window* window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (!window) {
        throw SDLError("Failed to create window");
    }
    handle.reset(window);
}

void Window::WindowDeleter::operator()(SDL_Window* window) {
    SDL_DestroyWindow(window);
}
