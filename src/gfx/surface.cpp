#include "surface.hpp"

Surface::Surface(SDL_Surface* rawHandle) : Wrapper(rawHandle) {}

template <>
void Wrapper<SDL_Surface>::Deleter::operator()(SDL_Surface* surface) {
    SDL_FreeSurface(surface);
}
