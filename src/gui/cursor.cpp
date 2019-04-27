#include "cursor.hpp"

#include "core/error.hpp"

Cursor::Cursor(SDL_SystemCursor id) {
    auto* cursor = SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(id));
    if (!cursor) {
        throw SDLError("Cannot create system cursor");
    }
    handle.reset(cursor);
}

const Cursor& Cursor::arrow() {
    static const Cursor cursor{SDL_SYSTEM_CURSOR_ARROW};
    return cursor;
}

const Cursor& Cursor::hand() {
    static const Cursor cursor{SDL_SYSTEM_CURSOR_HAND};
    return cursor;
}

const Cursor& Cursor::forbidden() {
    static const Cursor cursor{SDL_SYSTEM_CURSOR_NO};
    return cursor;
}

void Cursor::set() const { SDL_SetCursor(getHandle()); }

template <> void Wrapper<SDL_Cursor>::Deleter::operator()(SDL_Cursor* cursor) {
    SDL_FreeCursor(cursor);
}
