#pragma once

#include <functional>
#include <unordered_map>

#include "core/sdl.hpp"

/// Interface to the main event loop of the application.
///
/// This class should only be used on the main thread, and be treated as
/// a singleton, since multiple instances of it will conflict.
class EventLoop {
    using EventHandler = std::function<void(const SDL_Event& event)>;
    using EventHandlerMap = std::unordered_map<unsigned, EventHandler>;
    EventHandlerMap handlers;

    bool running;

public:
    /// Initializes the event loop which stops when the user quits the app.
    EventLoop();

    /// Sets a handler for an SDL event type.
    void setEventHandler(SDL_EventType type, EventHandler&& handler);

    /// Start the event loop.
    ///
    /// The event loop keeps pumping events until stop has been requested.
    void run();

    /// Stop the event loop from handling more events.
    ///
    /// This will finish processing the current iteration and then
    /// the event loop will exit.
    void requestStop();
};
