#pragma once

#include "core/sdl.hpp"

/// Interface implemented by classes which listen to and respond to user input.
class EventHandler {
public:
    virtual void handleEvent(const SDL_Event& e);
};
