#include "event.hpp"

#include "core/error.hpp"

EventLoop::EventLoop() : handlers{}, running{false} {
    // Set up the default quit handler
    setEventHandler(SDL_QUIT, [this](const SDL_Event&) { requestStop(); });
}

void EventLoop::setEventHandler(SDL_EventType type, EventHandler&& handler) {
    handlers[type] = std::move(handler);
}

void EventLoop::run() {
    running = true;

    const auto eventFilter = [](void* userData, SDL_Event* event) {
        const auto& handlers =
            *reinterpret_cast<const EventHandlerMap*>(userData);

        int handled = handlers.count(SDL_EventType(event->type));

        return handled;
    };
    SDL_SetEventFilter(eventFilter, &handlers);

    while (running) {
        SDL_Event event;
        if (SDL_WaitEvent(&event) == 0) {
            throw SDLError("Failed to wait for event");
        }

        // Safe because we filter unknown events
        handlers[event.type](event);
    }

    SDL_SetEventFilter(nullptr, nullptr);
}

void EventLoop::requestStop() { running = false; }
