#pragma once

#include "gfx/drawable.hpp"
#include "gui/event.hpp"
#include <core/sdl.hpp>

/// Component in the UI hierarchy. Contained in a rectangular box, derivatives
/// of this class can draw themselves and respond to user input.
class Widget : public Drawable, public EventHandler {
protected:
    SDL_Point position;

    Widget();

    virtual void onUpdatePosition();

public:
    virtual ~Widget();

    SDL_Point getPosition() const;
    void setPosition(int x, int y);
    void setPosition(SDL_Point p);

    /// The width of the content of this widget.
    virtual int getWidth() const = 0;
    /// The height of the content of this widget.
    virtual int getHeight() const = 0;

    /// Returns the computed bounding box of this widget.
    SDL_Rect getBoundingBox() const;
};
