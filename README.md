cub3D is a 42 School project where we implement a 3D game engine from scratch using the raycasting technique — the same technique used in classic games like Wolfenstein 3D.
The goal is to render a navigable 3D maze from a 2D map using only the MiniLibX graphics library and pure C.

🎯 Features
3D rendering using raycasting
Player movement: W A S D
Camera rotation: ← → arrow keys
Different wall textures for each direction (North, South, East, West)
Configurable floor and ceiling colors
Map parsing from a .cub configuration file
Clean exit with ESC key or window close button

Requirements
Linux OS
GCC compiler
X11 and Xext libraries

make        # Build the project
make clean  # Remove object files
make fclean # Remove object files + binary
make re     # Rebuild everything


📚 Resources

Lode's Raycasting Tutorial
MiniLibX Documentation
42 Docs
