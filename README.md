# CUB3D | CODAM

My first RayCaster

### Table of Contents
* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Instalation](#installing-the-mlx-library-and-required-recourses)
* [Running](#Running)
* [Learnings](#learnings)

![test](https://github.com/winglessOracle/so_long/blob/main/example.gif)

## Introduction
CUB3D is an assignment for CODAM in which we are tasked to create a simple 3D looking environment to get familiar with a raycasting principals. At CODAM we have access to the the MLX42 library which can be found at [here: MLX42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md). 

There is no intended goal but if you like a challande navigate tthe maze map to the bottom right corner.

### Requirements
The environment must follow a set of rules. The executable ``cub3d`` will receive a map as the only argument, and this map will have a ``.cub`` filetype.

The file also must follow these rules:
- Contain a map: The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation. 

- The map must be closed/surrounded by walls.

- Contain texture data and color data for the ceiling and the floor

- Except for the map content which always has to be the last, each type of element can be set in any order in the file.

- Except for the map, each type of information from an element can be separated by one or more space(s).

- The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

- Each element (except the map) firsts information is the type  identifier (composed by one or two character(s)), followed by specific informations for each object in a strict order such as: 
`NO ./path_to_north_texture` for a wall texture and  
 `F 220,100,1` for floor color

- The program should display different wall textures that vary depending on which side the wall is facing (North, South, East, West)

- The program must be able to set the floor and ceiling colors seperatly

- Error handeling on all of these checks must exit the game in a clean manner and display  `Error\n` followed by a custom message.

## How it Works

### Reading the map
After checking the parameters and extention (.cub) we allocate a struct data where we store all relevant date. We initialize the underlying variables and allocate a few more structs for specific data like image data. We then used the our own custom  `get_next_line` function (an earlier project) to read the input data into one string which we can parse to get texture paths, colors and a (x,y) map grid. A final test is done to determine if the map is enclosed using a flood-fill function.

### Starting
If all checks are passed the MLX window is initilized, the textures are loaded en then drawn to images which are placed in the window.

### Raycasting
to follow

### Playing
Keybinding:
- `W A S D` controle player movement.
- Arrow keys LEFT and RIGHT and the mouse controle viewing direction (turing)
- `ESC` closes the environment.
- `M` toggles the mouse on or off.
- `R` toggles the mini map (radar) on or off.

### Collision 
The player hase a grid locationm (float) used to determing what they 'see' and to calculate valid moves and colissions.


## Installing the MLX library and required recourses
Please read the documentation for this in the [MLX42 repository](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md). It is self explenatory.

Cone this repository and run the make command. This works on MacOs and Linux. 
For windows please check the right installation requirements and compilation flags in the abovementioned documentation for [MLX42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md).

Just use the `make` command to compile the cub3d executable using the MLX42 lib.

## Running
Run `./cub3d ./maps/maze.cub` to run the environment. You can change the map (maze.cub) to any maps in the maps folder.

## Learnings
Here is an overview of things we learned and ran into during this project.

- Timing

- Use the MLX42 library instead of minilibx. It is more stable, has less inhearent leaks better documented and easy to use.

## Authors:
- Christaiaan Herrewijn
- Carlo Wesseling

SEPT 2023

For more information visit: [Codam.nl](https://codam.nl/) or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).
