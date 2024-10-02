
# cub3D

## Overview
**cub3D** is a 42 project inspired by the classic **Wolfenstein 3D**, where you'll create a "realistic" 3D graphical representation of a maze from a first-person perspective using **Ray-Casting**. This project is a great opportunity to practice mathematical concepts in a fun and engaging way while improving your skills in C programming and graphics.

## Goals
- Develop a 3D game using **MiniLibX**.
- Work with essential C libraries and algorithms.
- Apply mathematics to create efficient and elegant algorithms for ray-casting and rendering.
- Understand how 3D graphics work, including walls, textures, and colors.

## Mandatory Features

### Program Requirements
- Program Name: `cub3D`
- Language: C (with adherence to 42’s Norm)
- External Functions:
  - open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday
  - All functions from the math library (-lm)
  - All functions from **MiniLibX**

### Main Features
- **3D Maze Representation**: Create a 3D first-person view of a maze using ray-casting.
- **Window Management**: Smooth interaction, including minimizing or switching between windows.
- **Textures & Colors**:
  - Display different textures for walls (North, South, East, West).
  - Set different colors for the floor and ceiling.
- **Map Input**: Accept a scene description file in `.cub` format.
  - The map must consist of walls (`1`), empty spaces (`0`), and a player start position (`N`, `S`, `E`, `W`).
  - Map boundaries must be enclosed by walls.
- **Player Movement**:
  - Use arrow keys to rotate the view.
  - Move with **W**, **A**, **S**, **D** keys.
  - Press **ESC** to close the window and quit the game.
- **Error Handling**: If the map is misconfigured, the program should return an error message.

### Example Map (`map.cub`)
```
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture
F 220,100,0
C 225,30,0
111111
100001
101001
1000N1
111111
```

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/aabderrafie/cub3D_42
   cd cub3d
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run the game with a valid map:
   ```bash
   ./cub3D map.cub
   ```

## Bonus Features
If the mandatory part is fully completed, the following bonuses can be added:
- **Wall Collisions**: Prevent the player from walking through walls.
- **Mini-Map**: Display a small 2D map of the maze in one corner of the screen.
- **Interactive Doors**: Add doors that the player can open and close.
- **Animated Sprites**: Add moving objects or characters in the game.
- **Mouse Look**: Allow the player to rotate the view with the mouse.

## Installation
This project depends on the **MiniLibX** library. You can either use the version available on your system or compile from its sources.

## Usage
- Move the player with **W**, **A**, **S**, **D**.
- Rotate the view with the left and right arrow keys.
- Exit the game by pressing **ESC** or clicking the red cross.

## Contributing
Contributions are welcome! Fork the repository, create a new branch, and submit a pull request.

## License
This project is licensed under the MIT License.

---

Feel free to adjust any specific details, and let me know if you'd like further tweaks!
