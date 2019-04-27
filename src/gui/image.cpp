#include "image.hpp"

#include "gfx/renderer.hpp"

Image::Image(Surface surf, Renderer& r, int width, int height)
    : surface(std::move(surf)), texture(r, surface), width(width),
      height(height) {}

Image::Image(const std::string& path, Renderer& r, int width, int height)
    : Image(Surface(path), r, width, height) {}

int Image::getWidth() const { return width; }

int Image::getHeight() const { return height; }

void Image::draw(Renderer& r) const {
    const auto bbox = getBoundingBox();

    r.copyTexture(texture, nullptr, &bbox);
}
