#pragma once

#include "gfx/surface.hpp"
#include "gfx/texture.hpp"
#include "gui/widget.hpp"

/// UI component which holds and draws an image.
class Image : public Widget {
    Surface surface;
    Texture texture;
    int width, height;

public:
    /// Constructs a new image from a loaded surface.
    Image(Surface surface, Renderer& r, int width, int height);

    /// Loads a new image from disk and draws it at a certain resolution.
    Image(const std::string& path, Renderer& r, int width, int height);

    int getWidth() const override;
    int getHeight() const override;

    void draw(Renderer& r) const override;
};
