#pragma once

#include <memory>

/// Base class for classes which wrap SDL resources.
template <typename T> class Wrapper {
protected:
    /// Functor for releasing an SDL handle.
    struct Deleter {
        void operator()(T* rawHandle);
    };

    std::unique_ptr<T, Deleter> handle;

    Wrapper() = default;
    Wrapper(T* rawHandle) : handle(rawHandle) {}

public:
    /// Retrieves the owned handle.
    T* getHandle() const { return handle.get(); }
};
