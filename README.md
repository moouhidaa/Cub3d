# Cub3D

A 3D raycasting engine inspired by Wolfenstein 3D, built in C using the MiniLibX graphics library. The engine renders a 2D map into a pseudo-3D first-person perspective using the DDA raycasting algorithm.

## Features

- **Raycasting engine** using the DDA (Digital Differential Analysis) algorithm
- **Textured walls** using XPM image files (North, South, East, West faces)
- **Colored ceiling and floor** defined in the map configuration
- **First-person player movement** (WASD) with collision detection
- **Camera rotation** using left/right arrow keys
- **Map parsing** from `.cub` configuration files with full validation

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate left |
| `→` | Rotate right |
| `ESC` | Quit |

## Dependencies

- GCC
- MiniLibX Linux (included in `mlx_linux/`)
- X11 and Xext development libraries

### Install dependencies (Ubuntu/Debian)

```bash
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

## Building

```bash
make
```

## Usage

```bash
./cub3d maps/test.cub
```

## Map File Format (.cub)

```
NO ./textures/north.xpm   # North wall texture
SO ./textures/south.xpm   # South wall texture
WE ./textures/west.xpm    # West wall texture
EA ./textures/east.xpm    # East wall texture

F 220,100,0               # Floor color (R,G,B)
C 135,206,235             # Ceiling color (R,G,B)

11111111111               # Map grid:
10000000001               #   1 = wall
1000N000001               #   0 = empty space
10000000001               #   N/S/E/W = player start direction
11111111111
```

## Project Structure

```
.
├── Makefile
├── cub3d.h                   # Main header
├── src/
│   ├── main.c                # Entry point + initialization
│   ├── parsing/
│   │   ├── parse_file.c      # File reading and orchestration
│   │   ├── parse_config.c    # Texture and color parsing
│   │   ├── parse_map.c       # Map grid parsing
│   │   └── validate_map.c    # Map validation (flood fill)
│   ├── rendering/
│   │   ├── render.c          # Main render loop + raycasting
│   │   └── draw.c            # Pixel drawing utilities
│   └── player/
│       ├── movement.c        # Player movement and rotation
│       └── input.c           # Keyboard event handling
├── utils/
│   ├── ft_utils.c            # String utility functions
│   └── error.c               # Error handling and cleanup
├── textures/                 # XPM wall textures
├── maps/                     # Sample map files
└── mlx_linux/                # MiniLibX library source
```
