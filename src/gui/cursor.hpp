#pragma once

#include "core/sdl.hpp"
#include "core/wrapper.hpp"

/// Custom application cursor which can replace the default arrow.
class Cursor : public Wrapper<SDL_Cursor> {
    /// Constructs a new handle to a system cursor.
    Cursor(SDL_SystemCursor id);

public:
    /// The default arrow-like cursor.
    static const Cursor& arrow();
    /// A hand pointing to something.
    static const Cursor& hand();
    /// Cursor indicating an action which is not possible.
    static const Cursor& forbidden();

    /// Sets this cursor as the currently active one.
    void set() const;
};
