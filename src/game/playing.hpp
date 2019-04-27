#pragma once

#include "game/state.hpp"
#include "gui/button.hpp"
#include "gui/label.hpp"

enum class CellState : unsigned;

/// The state in which the game has been started and is currently playing.
class PlayingState : public GameState {
    int moveCount{0};
    bool swap1, waitingForInput{false};
    int currentPlayer{1};
    Color currentColor{Color::RED};
    Label currentPlayerLabel, messageLabel;
    Button restartButton;
    Button option1Button, option2Button, option3Button;
    bool passOption{false};

    std::string formatCurrentPlayerString() const;
    CellState colorToCellState() const;
    void flipPlayer();
    void flipColor();

public:
    /// Starts a new game with the Swap1 or Swap2 rules.
    PlayingState(Game& game, Renderer& r, bool swap1);

    int getCurrentPlayer() const;
    Color getCurrentColor() const;

    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;

    void onBoardClicked(Board& b, int row, int col);
};
