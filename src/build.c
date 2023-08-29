/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 14:43:22 by carlowessel   ########   odam.nl         */
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
				mlx_put_pixel(data->img_data->main_screen,
					x, y, data->img_data->floor->argb);
			else
				mlx_put_pixel(data->img_data->main_screen, x, y,
					data->img_data->ceiling->argb);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	put_pixels_mini(t_data *data)
{
	int	x;
	int	y;
	int	grid_x;
	int	grid_y;

	x = 0;
	y = 0;
	while (y < data->mm->height)
	{
		while (x < data->mm->width)
		{
			grid_x = x * data->grid_width / data->mm->width;
			grid_y = y * data->grid_height / data->mm->height;
			mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->o_col);
			if ((data->grid[grid_y][grid_x]) == '1')
				mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->w_col);
			if (grid_y == (int)round(data->p_ypos) && grid_x
				== (int)round(data->p_xpos))
				mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->p_col);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	build_minimap(t_data *data)
{
	if (data->toggle_mm)
		return ;
	if (data->mm->height < 100 || data->mm->width < 200)
		return ;
	data->img_data->mini_map
		= mlx_new_image(data->mlx, data->mm->width, data->mm->height);
	put_pixels_mini(data);
	mlx_image_to_window(data->mlx, data->img_data->mini_map,
		data->mm->xpos, data->mm->ypos);
}

void	build_image(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	put_pixels_main(data);
	mlx_image_to_window(data->mlx, data->img_data->main_screen, 0, 0);
	build_minimap(data);

	build_test_pixel(0, 0, data); //remove
//	test_print_images(data); // remove
}
