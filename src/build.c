/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/14 18:00:38 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_put_pixel(mlx_image_t *image, uint32_t x, uint32_t y,
	uint32_t color)
{
	uint32_t	*pixelstart;

	pixelstart = &((uint32_t *)image->pixels)[(y * image->width + x)];
	*pixelstart = color;
}

void	put_pixels_main(t_data *data)
{
	int				x;
	int				y;
	t_pixel_data	pixel_data;

	x = 0;
	while (x < data->screen_width)
	{
		pixel_data.viewdir = calc_pix_view_dir(x, data);
		pixel_data.bounce = get_bounce(data, pixel_data.viewdir);
		if (pixel_data.bounce == NULL)
			return ;
		(pixel_data.bounce)->distance_adj 
			= sqrt((pixel_data.bounce)->distance_squared)
			* cos(pixel_data.viewdir - data->p_viewdir);
		y = 0;
		while (y < data->screen_height)
		{
			put_raycast_pixel(data, &pixel_data, x, y);
			y++;
		}
		free(pixel_data.bounce);
		pixel_data.bounce = NULL;
		x++;
	}
}

void	put_pixels_mini(t_data *data)
{
	int	x;
	int	y;
	int	grid_x;
	int	grid_y;

	y = 0;
	while (y < data->mm->height)
	{
		x = 0;
		while (x < data->mm->width)
		{
			grid_x = x * data->grid_width / data->mm->width;
			grid_y = y * data->grid_height / data->mm->height;
			mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->o_col);
			if ((data->grid[grid_y][grid_x]) == '1')
				mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->w_col);
			if (grid_y == (int)data->p_ypos && grid_x
				== (int)data->p_xpos)
				mlx_put_pixel(data->img_data->mini_map, x, y, data->mm->p_col);
			x++;
		}
		y++;
	}
}

void	pixelate_image(t_data *data)
{
	put_pixels_main(data);
	if (data->mm->toggle_mm && data->mm->height >= 50 && data->mm->width >= 100)
		put_pixels_mini(data);
	data->last_pixelate = mlx_get_time();
}

void	build_image(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	mlx_image_to_window(data->mlx, data->img_data->main_screen, 0, 0);
	if (data->mm->toggle_mm && data->mm->height >= 50
		&& data->mm->width >= 100)
	{
		mlx_image_to_window(data->mlx, data->img_data->mini_map,
			data->mm->xpos, data->mm->ypos);
	}
	pixelate_image(data);
}
