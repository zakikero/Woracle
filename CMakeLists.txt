cmake_minimum_required(VERSION 3.10)
project(woracle VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
)

add_executable(woracle ${SOURCES})

# Warnings utiles
if (MSVC)
    target_compile_options(woracle PRIVATE /W4 /permissive-)
else()
    target_compile_options(woracle PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(woracle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
