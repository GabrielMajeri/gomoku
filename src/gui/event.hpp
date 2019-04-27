#pragma once

#include "core/sdl.hpp"

class EventHandler {
public:
    virtual void handleEvent(const SDL_Event& e);
};
