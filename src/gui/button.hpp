#pragma once

#include "gui/label.hpp"
#include <functional>

using ClickHandler = std::function<void()>;

/// Button which can be clicked by the user.
class Button : public Widget {
    Label label;
    ClickHandler handler;

    void onUpdatePosition() override;

public:
    /// Constructs a new button with a certain text label.
    Button(Renderer& r, const Font& font, const std::string& text);

    /// The click handler is the function which gets called when a click
    /// is registered by this button.
    void setClickHandler(ClickHandler&& h);

    int getWidth() const override;
    int getHeight() const override;

    void draw(Renderer& r) const override;
    void handleEvent(const SDL_Event& e) override;
};
