# CPPND: Capstone Tetris Game 
Capstone project for Udacity Nanodegree program [CppND](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).Project implements the game [Tetris](https://en.wikipedia.org/wiki/Tetris).


## Gameplay
Player should place the falling tetrominos in a way that the Matrix has as less as possible empty cells. When line in the Matrix has no empty cells, it is deleted. Player can rotate tetrominos, accelerate their fall. Player fails, when at least one figure exaggerates the game field on the top. For one deleted line player receives 100 scores, and every 200 scores the speed of the tetrominos will increase 
- left arrow - move the tetromino left
- right arrow - move the tetromino right
- up arrow - rotate the tetromino clock wise
- up down - move the tetromino down
- space - drop down the tetromino
- r - restart the game
- q - leave game


# Dependencies for Running Locally
- cmake >= 3.16.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- SDL >= 2.0
  - All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  - Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
- gcc/g++ >= 7.5.0
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

# Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Tetris`.

## File Structure

This repository contains:
- `cmake/` : Contains cmake configuration to find SDL2 Library files.

- `src/` : Source. Constains the `Game.cpp`, `Matrix.cpp`, `Tetromino.cpp`, `main.cpp` files.

- `CMakeLists.txt` : cmake configuration file

- `README.md` : This file

# Project description
Program is divided into three classes.
<br>
*classes:*

- Game.cpp Game.hpp (class) - the game loop is done here. and where we Initialize the SDL library , and configure the input for the game.

- Matrix.cpp Matrix.hpp (class) - in this class we Place Grid in the background and calculate the score , also we check if there is Solid Line to be deleted or not.

- Tetromino.cpp Tetromino.hpp (class) - in this class we Initialize Tetrominos and render and move and rotate them.


# The following rubric points are addressed
1. Class constructors utilize member initialization lists -  ./src/Game.cpp:8
2. The project demonstrates an understanding of C++ functions and control structures.- src/main.cpp:14:15
3. The project uses destructors appropriately. - src/Game.cpp:38
4. Classes encapsulate behavior  - ./src/Game.hpp/ - ./src/Tetromino.hpp
5. The project makes use of references in function declarations  ./src/Matrix.cpp:43.
