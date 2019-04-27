#include "renderer.hpp"

#include "core/error.hpp"
#include "gfx/color.hpp"
#include "gfx/texture.hpp"
#include "gui/window.hpp"

Renderer::Renderer(Window& window) {
    const int index = -1;
    const Uint32 flags = 0;
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window.getHandle(), index, flags);
    if (!renderer) {
        throw SDLError("Failed to create renderer");
    }
    handle.reset(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

template <>
void Wrapper<SDL_Renderer>::Deleter::operator()(SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
}

void Renderer::setDrawColor(const Color& color) {
    if (SDL_SetRenderDrawColor(getHandle(), color.getR8(), color.getG8(),
                               color.getB8(), color.getAlpha8()) != 0) {
        throw SDLError("Failed to set renderer draw color");
    }
}

/// Sets the scale for the renderer's coordinate system.
void Renderer::setScale(float x, float y) {
    if (SDL_RenderSetScale(getHandle(), x, y) != 0) {
        throw SDLError("Failed to set renderer scale");
    }
}

void Renderer::clear() { SDL_RenderClear(getHandle()); }

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    if (SDL_RenderDrawLine(getHandle(), x1, y1, x2, y2) != 0) {
        throw SDLError("Failed to draw line");
    }
}

void Renderer::drawLines(const std::vector<SDL_Point>& points) {
    if (SDL_RenderDrawLines(getHandle(), points.data(), points.size()) != 0) {
        throw SDLError("Failed to draw lines");
    }
}

void Renderer::drawRect(const SDL_Rect& rect) {
    if (SDL_RenderDrawRect(getHandle(), &rect) != 0) {
        throw SDLError("Failed to draw rectangle");
    }
}

void Renderer::fillRect(const SDL_Rect& rect) {
    if (SDL_RenderFillRect(getHandle(), &rect) != 0) {
        throw SDLError("Failed to fill rectangle");
    }
}

void Renderer::copyTexture(const Texture& texture, const SDL_Rect* src,
                           const SDL_Rect* dest) {
    if (SDL_RenderCopy(getHandle(), texture.getHandle(), src, dest) != 0) {
        throw SDLError("Failed to copy texture");
    }
}

void Renderer::present() { SDL_RenderPresent(getHandle()); }
