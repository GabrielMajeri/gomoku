#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"

/// A surface is a rectangular array of pixels which are used for graphics ops.
class Surface : public Wrapper<SDL_Surface> {
public:
    /// Takes ownership of a raw SDL surface handle.
    Surface(SDL_Surface* rawHandle);

    int getWidth() const { return getHandle()->w; }
    int getHeight() const { return getHandle()->h; }
};
