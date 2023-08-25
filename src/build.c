/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/25 09:35:04 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//for now using ARGB ceiling and floor colors
void	put_pixels_main(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->screen_height)
	{
		while (x < data->screen_width)
		{
			if (y > data->screen_height / 2)
				mlx_put_pixel(data->img_data->main_screen, x, y, data->img_data->floor->argb);
			else
				mlx_put_pixel(data->img_data->main_screen, x, y, data->img_data->ceiling->argb);
			if (x < 20 || x > data->screen_width - 20 || y < 20 || y > data->screen_height - 20)
					mlx_put_pixel(data->img_data->main_screen, x, y, 255);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	put_pixels_mini(int map_width, int map_height, t_data *data)
{
	//issue is non exiting cooordinate not square	int	x;
	int	x;
	int	y;
	int	col_wall;
	int	col_player;
	int	col_open;

	x = 0;
	y = 0;
	col_player = get_rgba(0, 255, 0, 255);
	col_wall = get_rgba(0, 0, 0, 255);
	col_open = get_rgba(0, 0, 255, 255);
	while (y < map_height)
	{
		while (x < map_width)
		{
			int tx = x * data->grid_width / map_width;
			int ty = y * data->grid_height / map_height;
			mlx_put_pixel(data->img_data->mini_map, x, y, col_open);
			if (data->grid[ty][tx]== '1')
		   		mlx_put_pixel(data->img_data->mini_map, x, y, col_wall);
			if (ty== data->p_ypos && tx == data->p_xpos)
		   		mlx_put_pixel(data->img_data->mini_map, x, y, col_player);
			// if (data->grid[ty][tx]== ' ')
		   	// 	mlx_put_pixel(data->img_data->mini_map, x, y, 0);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	build_minimap(t_data *data)
{
	int	map_width;
	int	map_height;
	int	scale; // move to init; and add bool for min size of 200x100. later relate this to screen resoluition

	scale = 4;
	map_width = data->screen_width / scale;
	map_height = data->screen_height / scale;
	printf("\nMap_width=%d\nMap_height=%d\n", map_width, map_height);
	data->img_data->mini_map
		= mlx_new_image(data->mlx, map_width, map_height);
	put_pixels_mini(map_width, map_height, data);
	mlx_image_to_window(data->mlx, data->img_data->mini_map,
		data->screen_width - 30 - map_width, data->screen_height - 30 - map_height);
}

void	build_image(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	put_pixels_main(data);
	mlx_image_to_window(data->mlx, data->img_data->main_screen, 0, 0);
	build_minimap(data);

//test_print_images(data); // remove
}


//draw image (including binus)
