#include "font.hpp"

#include "core/error.hpp"

Font::Font(const std::string& path, int pointSize) {
    auto* font = TTF_OpenFont(path.c_str(), pointSize);
    if (!font) {
        throw SDLFontError("Failed to load font");
    }
    handle.reset(font);
}

template <> void Wrapper<TTF_Font>::Deleter::operator()(TTF_Font* font) {
    TTF_CloseFont(font);
}

Surface Font::render(const std::string& text, Color color) const {
    auto* surface = TTF_RenderUTF8_Blended(getHandle(), text.c_str(), color);

    if (!surface) {
        throw SDLFontError("Failed to render text");
    }

    return Surface(surface);
}

Surface Font::renderWrapped(const std::string& text, Color color,
                            int width) const {
    auto* surface =
        TTF_RenderUTF8_Blended_Wrapped(getHandle(), text.c_str(), color, width);

    if (!surface) {
        throw SDLFontError("Failed to render wrapped text");
    }

    return Surface(surface);
}
