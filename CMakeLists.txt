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
    "src/gfx/surface.hpp" "src/gfx/surface.cpp"
    "src/gfx/texture.hpp" "src/gfx/texture.cpp"
    "src/gui/font.hpp" "src/gui/font.cpp"
    "src/gui/event.hpp" "src/gui/event.cpp"
    "src/gui/widget.hpp" "src/gui/widget.cpp"
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
if(WIN32)
    set(LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")

    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(SDL2_DIR "${LIBS_DIR}/i686-w64-mingw32")
    else()
        set(SDL2_DIR "${LIBS_DIR}/x86_64-w64-mingw32")
    endif()
    set(SDL2_BIN_DIR "${SDL2_DIR}/bin")

    configure_file("${SDL2_BIN_DIR}/SDL2.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
    configure_file("${SDL2_BIN_DIR}/SDL2_image.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
    configure_file("${SDL2_BIN_DIR}/SDL2_ttf.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
    configure_file("${SDL2_BIN_DIR}/libfreetype-6.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
    configure_file("${SDL2_BIN_DIR}/libpng16-16.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
    configure_file("${SDL2_BIN_DIR}/zlib1.dll" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
target_include_directories(
    Gomoku PRIVATE
    "${SDL2_INCLUDE_DIRS}"
    "${SDL2_IMAGE_INCLUDE_DIRS}"
    "${SDL2_TTF_INCLUDE_DIRS}"
)
target_link_libraries(
    Gomoku PRIVATE
    "${SDL2_LIBRARIES}"
    "${SDL2_IMAGE_LIBRARIES}"
    "${SDL2_TTF_LIBRARIES}"
)

# Enable extra compiler warnings and treat warnings as errors
if(MSVC)
    target_compile_options(Gomoku PRIVATE "/W4" "/WX")
else()
    target_compile_options(Gomoku PRIVATE "-Wall" "-Wextra" "-pedantic" "-Werror")
endif()
