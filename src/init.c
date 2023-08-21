/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/22 00:04:31 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	malloc_structs(t_data *data)
{
	data->check_data = malloc(sizeof(t_check_data));
	if (!data->check_data)
		return (1);
	return (0);
}

void	init_check_data(t_check_data *check_data)
{
	check_data->start_pos = 0;
	check_data->valid_char = "01NESW";
	check_data->start_char = "NESW";
	check_data->bad_check = false;
}

int	init_data(char *input_file, t_data *data)
{
	init_check_data(data->check_data);
	data->mlx 	= mlx_init(1200, 800, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_set_window_pos(data->mlx, 100, 800);
	data->grid_width = 0;
	data->grid_height = 0;
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->p_viewdir = 0;
	data->floor_height = 0;
	data->ceiling_height = 100;
	data->view_plane_dist  = 10;
	
	data->grid = generate_grid(input_file, data);
	if (!data->grid)
		return (printf("%sFile not found or empty map\n", RED), 1);
	set_grid_width(data);
	if (analyze_grid(data)) 
	  	return (1);
	if (check_walls(data))
		return (1);
	print_grid(data); // remove
	return (0);
}
