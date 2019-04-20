#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"
#include "gfx/renderer.hpp"
#include "gfx/surface.hpp"

/// Represents a 2D array of pixels stored in graphics memory.
class Texture : public Wrapper<SDL_Texture> {
public:
    /// Constructs a new texture from a given surface's pixel data,
    /// loaded in the renderer's graphics memory.
    Texture(const Renderer& renderer, const Surface& surface);
};
