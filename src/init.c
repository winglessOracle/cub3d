/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/22 15:57:14 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_structs(t_data *data)
{
	data->check_data = malloc(sizeof(t_check_data));
	if (!data->check_data)
		free_str_exit("allocating structs", data, 3);
	data->mlx_data = malloc(sizeof(t_mlx_data));
	if (!data->mlx_data)
		free_str_exit("allocating structs", data, 3);
	data->mlx_data->ceiling = malloc(sizeof(t_color));
	if (!data->mlx_data->ceiling)
		free_str_exit("allocating structs", data, 3);
	data->mlx_data->floor = malloc(sizeof(t_color));
	if (!data->mlx_data->floor)
		free_str_exit("allocating structs", data, 3);
}

void	init_mlx_data(t_data *data)
{
	data->mlx_data->mlx = mlx_init(1200, 800, "cub3d", false);
	if (!data->mlx_data->mlx)
		free_str_exit("initializing MLX", data, 3);
	mlx_set_window_pos(data->mlx_data->mlx, 100, 800);
	data->mlx_data->north_texure = NULL;
	data->mlx_data->east_texture = NULL;
	data->mlx_data->south_texture = NULL;
	data->mlx_data->west_texture = NULL;
	data->mlx_data->ceiling->color = "default";
	data->mlx_data->ceiling->red = 1;
	data->mlx_data->ceiling->green = 1;
	data->mlx_data->ceiling->blue = 1;
	data->mlx_data->floor->color = "default";
	data->mlx_data->floor->red = 2;
	data->mlx_data->floor->green = 2;
	data->mlx_data->floor->blue = 2;
}

void	init_check_data(t_data *data)
{
	data->check_data->start_pos = 0;
	data->check_data->valid_char = "01NESW";
	data->check_data->start_char = "NESW";
}

void	init_main_data(t_data *data)
{
	data->grid_width = 0;
	data->grid_height = 0;
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->p_viewdir = 0;
	data->floor_height = 0;
	data->ceiling_height = 100;
	data->view_plane_dist = 10;
}

void	init_data(char *input_file, t_data *data)
{
	init_check_data(data);
	init_mlx_data(data);
	init_main_data(data);
	parse_file_paths(input_file, data);
	data->grid = generate_grid(input_file);
	if (!data->grid)
		free_str_exit("generating grid", data, 3);
	analyze_grid(data);
	print_grid(data); // remove
}
