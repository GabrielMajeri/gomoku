#include "button.hpp"

#include "gfx/color.hpp"
#include "gui/cursor.hpp"

static constexpr auto BUTTON_PADDING_X = 10, BUTTON_PADDING_Y = 5;

static const auto& TEXT_COLOR = Color::BLACK;
static const auto& BACKGROUND_COLOR = Color::AQUA;
static const auto& BORDER_COLOR = Color::GREEN;

void Button::onUpdatePosition() {
    label.setPosition(position.x + BUTTON_PADDING_X,
                      position.y + BUTTON_PADDING_Y);
}

Button::Button(Renderer& r, const Font& font, const std::string& text)
    : label(r, font, text, TEXT_COLOR) {}

void Button::setClickHandler(ClickHandler&& h) { handler = h; }

int Button::getWidth() const { return 2 * BUTTON_PADDING_X + label.getWidth(); }

int Button::getHeight() const {
    return 2 * BUTTON_PADDING_Y + label.getHeight();
}

void Button::draw(Renderer& r) const {
    const auto bbox = getBoundingBox();
    r.setDrawColor(BACKGROUND_COLOR);
    r.fillRect(bbox);

    r.setDrawColor(BORDER_COLOR);
    r.drawRect(bbox);

    label.draw(r);
}

void Button::handleEvent(const SDL_Event& e) {
    switch (e.type) {
    case SDL_MOUSEBUTTONUP: {
        const auto& mbu = e.button;

        if (mbu.button != SDL_BUTTON_LEFT) {
            break;
        }

        const auto pt = SDL_Point{mbu.x, mbu.y};
        const auto bbox = getBoundingBox();
        if (SDL_PointInRect(&pt, &bbox)) {
            if (handler) {
                handler();
            }
        }
    } break;
    default:
        break;
    }
}
