#include "color.hpp"

#include <cassert>

Color::Color(float r, float g, float b, float a)
    : red{r}, green{g}, blue{b}, alpha{a} {}

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
    : red{float(r) / 255}, green{float(g) / 255}, blue{float(b) / 255},
      alpha{float(a) / 255} {}

Color::Color(std::uint32_t hex)
    : Color(static_cast<std::uint8_t>((hex & 0xFF0000) >> 16),
            static_cast<std::uint8_t>((hex & 0xFF00) >> 8),
            static_cast<std::uint8_t>((hex & 0xFF))) {
    assert(((hex & 0xFF000000) == 0) &&
           "Hex constructor does not support transparency");
}

const Color Color::WHITE{0xFFFFFF};
const Color Color::BLACK{0x000000};
const Color Color::RED{0xFF0000};
const Color Color::GREEN{0x00FF00};
const Color Color::BLUE{0x0000FF};
const Color Color::PINK{0xFFC0CB};
const Color Color::AQUA{0xC0FFEE};
