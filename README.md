*This project has been created as part of the 42 curriculum by otidahoh,wngambi*.

# Cub3D

## Description

_Cub3D is a simple 3D graphics engine inspired by the classic game Wolfenstein 3D. The project uses the raycasting technique to render a first-person view of a 2D map, creating the illusion of a 3D environment._

_The objective of the project is to understand the fundamentals of computer graphics, raycasting, texture mapping, event handling, and player movement while using the MiniLibX graphics library._

### Features

First-person 3D rendering using raycasting.<br>
Wall texture mapping.<br>
Floor and ceiling colors.<br>
Player movement (forward, backward, strafe).<br>
Camera rotation with the keyboard.<br>
Collision detection.<br>
Map parsing and validation.<br>
Door rendering and interaction.<br>
Minimap.

## Instructions

### Requirements

CC<br>
Make<br>
MiniLibX<br>

### Compilation
> make

To clean object files:

> make clean

To remove all generated files:

> make fclean

To rebuild the project:

> make re

Running the program:

> ./cub3D maps/map.cub

Replace maps/map.cub with the path to any valid .cub configuration file.

### Controls

W   move forward<br>
S	Move backward<br>
A	Strafe left<br>
D	Strafe right<br>
← / →	Rotate camera<br>
E	Open/close door<br>
ESC	Exit the game

### Raycasting Overview

Cub3D renders one vertical column of pixels for each screen column.

For every frame:

A ray is cast from the player's position.
The first wall hit is found using the DDA (Digital Differential Analyzer) algorithm.
The perpendicular distance to the wall is computed.
The wall height is projected onto the screen.
The correct texture column is selected.
Each screen pixel is textured to produce the final image.

This process is repeated for every column of the screen, creating a real-time 3D scene.

### Map Format

A valid .cub file contains:

North texture<br>
South texture<br>
East texture<br>
West texture<br>
Floor color<br>
Ceiling color<br>
A closed map<br>
A single player starting position (N, S, E, or W)

Example:

NO textures/north.xpm<br>
SO textures/south.xpm<br>
WE textures/west.xpm<br>
EA textures/east.xpm

F 220,100,0<br>
C 225,30,0

11111111<br>
100001<br>
10N001<br>
100001<br>
11111111

## Resources

Documentation<br>
MiniLibX documentation<br>
youtube

AI was used to:

Explain raycasting concepts and mathematical formulas.

Help debug segmentation faults and logic errors.
