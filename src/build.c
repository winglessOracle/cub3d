/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/23 14:41:20 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//for now using ARGB ceiling and floor colors
void	put_pixels(t_data *data)
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

void	build_images(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	put_pixels(data);
	mlx_image_to_window(data->mlx, data->img_data->main_screen, 0, 0);

	//	test_images(data); // remove
}
