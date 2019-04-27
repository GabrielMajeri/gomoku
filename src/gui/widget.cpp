#include "widget.hpp"

Widget::Widget() : position{0, 0} {}

Widget::~Widget() = default;

void Widget::onUpdatePosition() {}

SDL_Point Widget::getPosition() const { return position; }

void Widget::setPosition(int x, int y) {
    position = {x, y};
    onUpdatePosition();
}

void Widget::setPosition(SDL_Point p) {
    position = p;
    onUpdatePosition();
}

SDL_Rect Widget::getBoundingBox() const {
    int x = position.x, y = position.y;
    return {x, y, getWidth(), getHeight()};
}
