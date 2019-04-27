#pragma once

#include "gfx/color.hpp"
#include "gfx/drawable.hpp"
#include "gui/event.hpp"

class Board;
class Game;

/// Represents a state which the game could be in.
///
/// At any given point, the game only has one state active. The current state
/// handles input and draws the GUI (except the board and title, which are
/// always drawn).
class GameState : public Drawable, public EventHandler {
protected:
    Game& game;

    GameState(Game& game);

public:
    /// Game states are always dynamically allocated and accessed using runtime
    /// polymorphism, therefore this class requires a virtual destructor.
    virtual ~GameState();
};
