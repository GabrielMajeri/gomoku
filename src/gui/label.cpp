#include "label.hpp"

#include "gfx/renderer.hpp"

Label::Label(Renderer& r, const Font& font, const std::string& text,
             Color color)
    : font(font), text(text), color(color), needsUpdate(false),
      surface(font.render(text, color)), texture(r, surface) {}

int Label::getWidth() const { return surface.getWidth(); }

int Label::getHeight() const { return surface.getHeight(); }

void Label::setText(const std::string& t) {
    text = t;
    needsUpdate = true;
}

void Label::setColor(Color c) {
    color = c;
    needsUpdate = true;
}

void Label::draw(Renderer& r) const {
    if (needsUpdate) {
        surface = font.render(text, color);
        texture = Texture(r, surface);

        needsUpdate = false;
    }

    const auto boundingBox = getBoundingBox();
    r.copyTexture(texture, nullptr, &boundingBox);
}
