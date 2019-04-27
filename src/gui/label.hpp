#pragma once

#include "gfx/color.hpp"
#include "gfx/surface.hpp"
#include "gfx/texture.hpp"
#include "gui/font.hpp"
#include "gui/widget.hpp"
#include <string>

/// Static UI component for displaying colored text.
class Label : public Widget {
    const Font& font;
    std::string text;
    Color color;
    int maxWidth;

    mutable bool needsUpdate;
    mutable Surface surface;
    mutable Texture texture;

public:
    /// Constructs a new label with text written in a certain color.
    /// Max width can be used to make the text wrap.
    Label(Renderer& r, const Font& font, const std::string& text, Color color,
          int maxWidth = 0);

    int getWidth() const;
    int getHeight() const;

    void setText(const std::string& text);
    void setColor(Color color);

    void draw(Renderer& r) const;
};
