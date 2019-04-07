#pragma once

#include <vector>
#include "core/wrapper.hpp"

class Color;
class Window;
struct SDL_Point;

/// Basic interface for rendering to a surface.
class Renderer : public Wrapper<struct SDL_Renderer> {
public:
    /// Constructs a new renderer presenting its output to a window.
    Renderer(Window& window);

    /// Sets the color used for draw operations.
    void setDrawColor(const Color& color);

    /// Clears the whole surface to the currently set draw color.
    void clear();

    /// Draws a set of lines connecting the given points.
    void drawLines(const std::vector<SDL_Point>& points);

    /// Flips the back buffer with the front buffer, presenting a new frame
    /// onto the screen.
    void present();
};
