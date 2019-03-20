#pragma once

#include "core/wrapper.hpp"

class Window;

class Renderer : public Wrapper<struct SDL_Renderer> {
public:
    Renderer(Window& window);
};
