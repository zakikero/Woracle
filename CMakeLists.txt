cmake_minimum_required(VERSION 3.10)
project(woracle VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 packages
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Enable automatic MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Source files
set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/WordleSolver.cpp
)

# Header files
set(HEADERS
    src/MainWindow.h
    src/WordleSolver.h
)

# Create executable
add_executable(woracle ${SOURCES} ${HEADERS})

# Link Qt5 libraries
target_link_libraries(woracle Qt5::Core Qt5::Widgets)

# Include directories
target_include_directories(woracle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
