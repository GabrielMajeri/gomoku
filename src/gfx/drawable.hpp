#pragma once

class Renderer;

/// Interface representing an object which can be drawn on screen.
class Drawable {
public:
    /// Renders the object onto the screen.
    virtual void draw(Renderer& r) const = 0;
};
