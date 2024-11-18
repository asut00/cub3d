# Cub3D 🕹️
  
**Cub3D** is a 3D game engine built in C, inspired by the classic **Wolfenstein 3D**. It leverages raycasting to render a first-person perspective in a 2D environment, turning simple maps into immersive 3D experiences.

## Table of Contents

- [About the Project](#about-the-project)
- [Key Features](#key-features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Project Requirements](#project-requirements)
- [Author](#author)

---

## About the Project

The **Cub3D** project is part of the [42 School](https://42.fr/) curriculum, designed to introduce 3D graphics programming. By implementing a basic raycasting engine, this project bridges the gap between 2D and 3D rendering, providing insights into the math and logic behind first-person perspective engines.

### Objectives:
- Develop a 3D renderer using raycasting techniques.
- Parse and interpret a 2D map file to create a virtual world.
- Manage textures, sprites, and collision detection for realistic gameplay.
- Build a game-like experience, complete with player movement and interactions.

---

## Key Features

- **Raycasting Engine**: A simplified rendering engine to simulate 3D visuals.
- **2D to 3D Mapping**: Converts a 2D map into a playable 3D environment.
- **Textures**: Adds realism with textured walls, floors, and ceilings.
- **Sprites**: Supports rendering objects like doors, enemies, or decorations.
- **Player Movement**: Navigate the environment with smooth, responsive controls.
- **Collision Detection**: Prevent players from walking through walls.

---

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/asut00/cub3d.git
   cd cub3d
   ```

2. **Compile the program**:
   ```bash
   make
   ```
   This generates the `cub3d` executable in the project directory.

---

## Usage

Launch the program with a map file as an argument:

```bash
./cub3d path/to/map.cub
```

### Example:

```bash
./cub3d maps/sample.cub
```

### Map File Format

The `.cub` file defines the environment layout and includes:
- **Map grid**: Represented by `1` (walls), `0` (empty space), and player start position (`N`, `S`, `E`, `W`).
- **Textures**: File paths for wall textures and sprites.
- **Colors**: RGB values for the floor and ceiling.

Example `.cub` file:

```plaintext
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,225,225

111111
100001
1001N1
111111
```

---

## Game Controls (qwerty keyboard)

| Key            | Action                      |
|-----------------|-----------------------------|
| `W` / `S`      | Move forward / backward     |
| `A` / `D`      | Strafe left / right         |
| `←` / `→`      | Rotate view left / right    |
| `ESC`          | Exit the game               |

---

## Project Requirements

- **Parsing**:
  - Validate the `.cub` map format.
  - Manage errors gracefully (e.g., missing textures, invalid maps).
- **Rendering**:
  - Implement raycasting to draw walls based on player perspective.
  - Handle texture mapping and screen resolution adjustments.
- **Gameplay**:
  - Player movement and collision detection.
  - Sprite rendering for objects and enemies.

---

## Author

- GitHub: [@asut00](https://github.com/asut00)  
- 42 Intra: `asuteau`
