#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"
#include <vector>

class Color;
class Window;

/// Basic interface for rendering to a surface.
class Renderer : public Wrapper<SDL_Renderer> {
public:
    /// Constructs a new renderer presenting its output to a window.
    Renderer(Window& window);

    /// Sets the color used for draw operations.
    void setDrawColor(const Color& color);

    /// Sets the scale for the renderer's coordinate system.
    void setScale(float x, float y);

    /// Clears the whole surface to the currently set draw color.
    void clear();

    /// Draws a line connecting two points.
    void drawLine(int x1, int y1, int x2, int y2);

    /// Draws a set of lines connecting the given points.
    void drawLines(const std::vector<SDL_Point>& points);

    /// Flips the back buffer with the front buffer, presenting a new frame
    /// onto the screen.
    void present();
};
