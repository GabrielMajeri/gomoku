#pragma once

#include "gfx/color.hpp"
#include "gfx/surface.hpp"
#include "gfx/texture.hpp"
#include "gui/font.hpp"
#include "gui/widget.hpp"
#include <string>

class Label : public Widget {
    const Font& font;
    std::string text;
    Color color;

    mutable bool needsUpdate;
    mutable Surface surface;
    mutable Texture texture;

public:
    Label(Renderer& r, const Font& font, const std::string& text, Color color);

    int getWidth() const;
    int getHeight() const;

    void setText(const std::string& text);
    void setColor(Color color);

    void draw(Renderer& r) const;
};
