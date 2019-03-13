cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Connect5 VERSION 0.1.0 LANGUAGES CXX)

add_executable(Connect5 "src/main.cpp")

# Enable modern C++ features
target_compile_features(Connect5 PRIVATE cxx_std_14)
