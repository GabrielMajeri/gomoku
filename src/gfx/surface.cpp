#include "surface.hpp"

#include "core/error.hpp"

Surface::Surface(SDL_Surface* rawHandle) : Wrapper(rawHandle) {}

Surface::Surface(const std::string& path) {
    auto* image = IMG_Load(path.c_str());
    if (image == nullptr) {
        throw SDLImageError("Failed to load image");
    }
    handle.reset(image);
}

template <>
void Wrapper<SDL_Surface>::Deleter::operator()(SDL_Surface* surface) {
    SDL_FreeSurface(surface);
}
