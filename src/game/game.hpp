#pragma once

#include "game/board.hpp"
#include "game/state.hpp"
#include "gui/font.hpp"
#include "gui/image.hpp"
#include "gui/label.hpp"
#include "gui/window.hpp"
#include <memory>

/// Central dispatcher class which owns all the game's resources and handles
/// window creation and the game's lifetime.
class Game {
    Window window;
    Renderer rdr;

    bool running = false;

    Font titleFont, normalFont, bigFont;
    Label titleText;
    Image redPiece, bluePiece;
    Board board;
    std::unique_ptr<GameState> state, deletedState;

public:
    /// Constructs a new game in a new window.
    Game();

    /// Starts the main game loop.
    void run();
    /// Requests the game loop to exit as early as possible.
    void exit();

    /// Informs the game that it has ended.
    void finishGame(int player, Color color);

    /// Brings the game back to the initial state.
    void restartGame();

    /// Retrieves the current game state.
    GameState* getState();
    void changeState(std::unique_ptr<GameState>&& newState);

    /// Retrieves the font used for the game's title.
    const Font& getTitleFont() const;
    /// Retrieves the font used for the game's UI.
    const Font& getNormalFont() const;
    /// Retrieves the font used for big UI components.
    const Font& getBigFont() const;
};
