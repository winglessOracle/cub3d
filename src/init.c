/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/24 13:05:02 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_structs(t_data *data)
{
	data->check_data = malloc(sizeof(t_check_data));
	if (!data->check_data)
		free_str_exit("allocating structs", data, 3);
	data->img_data = malloc(sizeof(t_img_data));
	if (!data->img_data)
		free_str_exit("allocating structs", data, 3);
	data->img_data->ceiling = malloc(sizeof(t_color));
	if (!data->img_data->ceiling)
		free_str_exit("allocating structs", data, 3);
	data->img_data->floor = malloc(sizeof(t_color));
	if (!data->img_data->floor)
		free_str_exit("allocating structs", data, 3);
	data->img_data->wall_texture_paths = malloc(sizeof(char) * 4);
	if (!data->img_data->wall_texture_paths)
		free_str_exit("allocating structs", data, 3);
	data->img_data->wall_textures = malloc(sizeof(mlx_texture_t) * 4);
	if (!data->img_data->wall_textures)
		free_str_exit("allocating structs", data, 3);
}

void	init_img_data(t_data *data)
{
	data->mlx
		= mlx_init(data->screen_width, data->screen_height, "cub3d", false);
	if (!data->mlx)
		free_str_exit("initializing MLX", data, 3);
	mlx_set_window_pos(data->mlx, 640, 1500); //get center screen
	data->img_data->wall_texture_paths[4] = NULL;
	data->img_data->wall_textures[4] = NULL;
	data->img_data->ceiling->color = "default";
	data->img_data->ceiling->red = 0;
	data->img_data->ceiling->green = 0;
	data->img_data->ceiling->blue = 0;
	data->img_data->ceiling->a = 255;
	data->img_data->ceiling->argb = 0;
	data->img_data->floor->color = "default";
	data->img_data->floor->red = 0;
	data->img_data->floor->green = 0;
	data->img_data->floor->blue = 0;
	data->img_data->floor->a = 255;
	data->img_data->floor->argb = 0;
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
	data->screen_width = 1280;
	data->screen_height = 720;
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->p_viewdir = 0;
	data->floor_height = 0;
	data->ceiling_height = 100;
	data->view_plane_dist = 10;
}

void	init_data(char *input_file, t_data *data)
{
	init_main_data(data);
	init_check_data(data);
	init_img_data(data);
	parse_file_paths(input_file, data);
	data->grid = generate_grid(input_file);
	if (!data->grid)
		free_str_exit("generating grid", data, 3);
	analyze_grid(data);
	test_print_grid(data); // remove
}
