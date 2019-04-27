#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"
#include "gfx/color.hpp"
#include "gfx/surface.hpp"

/// Represents a typeface with which text can be rendered on screen.
class Font : public Wrapper<TTF_Font> {
public:
    /// Loads the first font from a given file, at a certain point size.
    Font(const std::string& path, int pointSize);

    /// Renders a string using the current font in a given color.
    Surface render(const std::string& text, Color color) const;

    /// Renders a string by wrapping the text after a certain width.
    Surface renderWrapped(const std::string& text, Color color,
                          int width) const;
};
