#include "renderer.hpp"

#include "gfx/color.hpp"
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

void Renderer::setDrawColor(const Color& color) {
    SDL_SetRenderDrawColor(getHandle(), color.getR8(), color.getG8(), color.getB8(), color.getAlpha8());
}

void Renderer::clear() {
    SDL_RenderClear(getHandle());
}

void Renderer::drawLines(const std::vector<SDL_Point>& points) {
    SDL_RenderDrawLines(getHandle(), points.data(), points.size());
}

void Renderer::present() {
    SDL_RenderPresent(getHandle());
}
