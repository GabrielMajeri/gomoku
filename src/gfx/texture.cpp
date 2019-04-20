#include "texture.hpp"

#include "core/error.hpp"

Texture::Texture(const Renderer& renderer, const Surface& surface) {
    auto* texture =
        SDL_CreateTextureFromSurface(renderer.getHandle(), surface.getHandle());

    if (!texture) {
        throw SDLError("Failed to create texture from surface");
    }

    handle.reset(texture);
}

template <>
void Wrapper<SDL_Texture>::Deleter::operator()(SDL_Texture* texture) {
    SDL_DestroyTexture(texture);
}
