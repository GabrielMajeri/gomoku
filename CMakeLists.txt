cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Gomoku VERSION 0.1.0 LANGUAGES CXX)

# Include additional CMake scripts
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include("clang-tools")
include("out-of-source")

# Enumerate all the source files
set(SRCS
    "src/main.cpp"
    "src/core/error.hpp" "src/core/error.cpp"
    "src/core/sdl.hpp" "src/core/sdl.cpp"
    "src/core/version.hpp" "src/core/version.cpp"
    "src/core/wrapper.hpp"
    "src/game/board.hpp" "src/game/board.cpp"
    "src/gfx/color.hpp" "src/gfx/color.cpp"
    "src/gfx/drawable.hpp"
    "src/gfx/renderer.hpp" "src/gfx/renderer.cpp"
    "src/gui/event.hpp" "src/gui/event.cpp"
    "src/gui/window.hpp" "src/gui/window.cpp"
)

# Create the main executable target of this project
add_executable(Gomoku WIN32 ${SRCS})

# Add clang-format support
add_clang_format_target("${SRCS}")

# Enable modern C++ features
target_compile_features(Gomoku PRIVATE cxx_std_14)

# Allow including relative to the root source directory
target_include_directories(Gomoku PRIVATE "src")

# Add the SDL2 dependency
find_package(SDL2 REQUIRED)
target_include_directories(Gomoku PRIVATE "${SDL2_INCLUDE_DIR}")
target_link_libraries(Gomoku PRIVATE "${SDL2_LIBRARY}")

if(WIN32)
    target_link_libraries(Gomoku PRIVATE
        "SDL2main"
        "dinput8" "gdi32" "imm32" "shell32"
        "winmm" "user32" "ole32" "uuid" "version"
        "setupapi"
    )
endif()

# Enable extra compiler warnings and treat warnings as errors
if(MSVC)
    target_compile_options(Gomoku PRIVATE "/W4" "/WX")
else()
    target_compile_options(Gomoku PRIVATE "-Wall" "-Wextra" "-pedantic" "-Werror")
endif()
