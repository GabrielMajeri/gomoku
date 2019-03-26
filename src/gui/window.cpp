#include "window.hpp"

#include "core/error.hpp"
#include <SDL.h>

Window::Window() {
    const char title[] = "Connect Five";
    const int x = 200, y = 100;
    const int width = 800, height = 600;
    const Uint32 flags = 0;
    SDL_Window* window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (!window) {
        throw SDLError("Failed to create window");
    }
    handle.reset(window);
}

template <> void Wrapper<SDL_Window>::Deleter::operator()(SDL_Window* window) {
    SDL_DestroyWindow(window);
}
