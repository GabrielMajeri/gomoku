#include "renderer.hpp"

#include "gui/window.hpp"
#include <SDL.h>

Renderer::Renderer(Window& window) {
    const int index = -1;
    const Uint32 flags = 0;
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window.getHandle(), index, flags);
    handle.reset(renderer);
}

template <>
void Wrapper<SDL_Renderer>::Deleter::operator()(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}
