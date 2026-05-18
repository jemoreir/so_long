# so_long

`so_long` is a small 2D game developed in C as part of the 42 Lisboa curriculum.

The goal of the project is to build a simple tile-based game using the MiniLibX graphical library, while practicing map parsing, rendering, event handling and memory management.

## About the project

The player must collect all collectibles on the map before reaching the exit.

The game reads a `.ber` map file, validates its structure and renders the game window using sprites.

This project helped me practice:

- Reading and validating map files
- Working with a 2D matrix
- Implementing a flood fill algorithm
- Handling keyboard events
- Rendering sprites with MiniLibX
- Managing memory in a graphical C project

## Features

- Tile-based 2D rendering
- Map validation
- Wall, player, collectible and exit detection
- Flood fill path validation
- Keyboard movement handling
- Move counter
- Basic error handling
- Memory cleanup before exit

## Map rules

A valid map must:

- Be rectangular
- Be surrounded by walls
- Contain exactly one player
- Contain exactly one exit
- Contain at least one collectible
- Have a valid path to all collectibles and the exit

Example:

```txt
111111
1000C1
10P001
1000E1
111111