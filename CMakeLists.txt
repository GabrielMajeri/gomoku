cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Connect5 VERSION 0.1.0 LANGUAGES CXX)

add_executable(Connect5
    "src/main.cpp"
    "src/core/error.hpp" "src/core/error.cpp"
    "src/core/sdl.hpp" "src/core/sdl.cpp"
    "src/core/version.hpp" "src/core/version.cpp"
    "src/core/wrapper.hpp"
    "src/gui/renderer.hpp" "src/gui/renderer.cpp"
    "src/gui/window.hpp" "src/gui/window.cpp"
)

# Enable modern C++ features
target_compile_features(Connect5 PRIVATE cxx_std_14)

# Allow including relative to the root source directory
target_include_directories(Connect5 PRIVATE "src")

# Add the SDL2 dependency
find_package(SDL2)
target_link_libraries(Connect5 PRIVATE SDL2)

# Enable extra compiler warnings and treat warnings as errors
if(MSVC)
    target_compile_options(Connect5 PRIVATE "/W4" "/WX")
else()
    target_compile_options(Connect5 PRIVATE "-Wall" "-Wextra" "-pedantic" "-Werror")
endif()
