#pragma once

#include "core/sdl.hpp"
#include <cstdint>

/// An RGB color which also supports transparency.
class Color {
    float red, green, blue, alpha;

public:
    /// Constructs a new color from the individual color channels and
    /// transparency factor.
    Color(float r, float g, float b, float a = 1.0);

    /// Constructs a new 24-bit color with 8 bits for transparency.
    Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);

    /// Constructs a new color from its corresponding color code.
    Color(std::uint32_t hex);

    operator SDL_Color() const;

    float getR() const { return red; }
    float getG() const { return green; }
    float getB() const { return blue; }
    float getAlpha() const { return alpha; }

    std::uint8_t getR8() const { return 255 * red; }
    std::uint8_t getG8() const { return 255 * green; }
    std::uint8_t getB8() const { return 255 * blue; }
    std::uint8_t getAlpha8() const { return 255 * alpha; }

    const static Color WHITE, BLACK, RED, GREEN, BLUE, PINK, AQUA;
};
