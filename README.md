# Woracle - Wordle Solver

A C++ application with Qt5 GUI for solving Wordle puzzles.

![Woracle UI](https://github.com/user-attachments/assets/499a232b-c239-4453-ba5f-6b30813f9ce9)

## Features

- Clean Qt5-based graphical user interface
- Input fields for guesses and feedback
- Real-time word suggestions based on Wordle feedback
- Built-in vocabulary of ~500 common 5-letter words
- Constraint-based filtering system

## Prerequisites

- CMake 3.10 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Qt5 development libraries (Core and Widgets)

### Installing Qt5 on Ubuntu/Debian:
```bash
sudo apt-get install qt5-qmake qtbase5-dev qtbase5-dev-tools
```

### Installing Qt5 on macOS (with Homebrew):
```bash
brew install qt@5
```

## Building

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./woracle
```

## Usage

1. **Enter Your Guess**: Type a 5-letter word (e.g., "CRANE")
2. **Enter Feedback**: Use the feedback pattern from Wordle:
   - `g` = Green (correct letter in correct position)
   - `y` = Yellow (correct letter in wrong position)
   - `b` = Black (letter not in word)
   
   Example: If you guessed "CRANE" and got ⬛🟨⬛⬛🟩, enter `bybbg`

3. **Get Suggestions**: Click the "Get Suggestions" button to see possible words
4. **Reset**: Click "Reset" to start a new game

## Project Structure

```
woracle/
├── CMakeLists.txt          # CMake build configuration
├── src/
│   ├── main.cpp            # Application entry point
│   ├── MainWindow.h/.cpp   # Main GUI window
│   └── WordleSolver.h/.cpp # Wordle solving logic
└── README.md
```

## License

See LICENSE file for details.
