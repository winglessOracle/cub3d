/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/23 17:25:44 by carlowessel   ########   odam.nl         */
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

void	put_pixels_mini(int scale, int width, int height, t_data *data)
{
	int	x;
	int	y;
	int	col_wall;
	int	col_player;

	x = 0;
	y = 0;
	col_player = get_rgba(0, 255, 0, 255);
	col_wall = get_rgba(255, 255, 255, 255);
	(void)col_player;
	(void)col_wall;
	(void)scale;
	while (y < height)
	{
		while (x < width)
		{
			mlx_put_pixel(data->img_data->mini_map, x, y, 255);
			// if (data->grid[y][x] == '1')
			// 	mlx_put_pixel(data->img_data->mini_map, x, y, col_wall);
			// if (x == data->p_xpos && y == data->p_ypos)
			// 	mlx_put_pixel(data->img_data->mini_map, x, y, col_player);
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
	int	map_scale;

	map_scale = 5;
	map_width = data->grid_width * map_scale;
	map_height = data->grid_height * map_scale;
	data->img_data->mini_map
		= mlx_new_image(data->mlx, map_width, map_height);
	put_pixels_mini(map_scale, map_width, map_height, data);
	mlx_image_to_window(data->mlx, data->img_data->mini_map,
		data->screen_width - 20 - map_width, data->screen_height - 20 - map_height);
}

void	build_image(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	put_pixels_main(data);
	mlx_image_to_window(data->mlx, data->img_data->main_screen, 0, 0);

	build_minimap(data);

//	test_print_images(data); // remove
}

