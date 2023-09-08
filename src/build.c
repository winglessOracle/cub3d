/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/08 11:27:27 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//for now using ARGB ceiling and floor colors
void	put_pixels_main(t_data *data)
{
	int			x;
	int			y;
	t_bounce 	*bounce;
	double		viewdir;
	double		z_angle;
	double		z_height;
	int			n_pixel;

	mlx_texture_t	*test_texture; // test;
	test_texture = mlx_load_png("./textures/test.png");

	x = 0;
	while (x < data->screen_width)
	// while (x < data->screen_width && x <= 1) // debug
	{
		viewdir = calc_pix_view_dir(x, data);
		y = 0;
		while (y < data->screen_height)
		// while (y < data->screen_height && y <= 1) // debug
		{
			bounce = get_bounce(data, viewdir);
			if (bounce == NULL)
			{
				printf("raycasting error!");
				return ;
			}
			z_angle = calc_z_angle(y, data);
			z_height = calc_z_height(bounce->distance, z_angle);

			// if (y == 0)
			// {
			// 	printf("viewdir %lf, wall: x %d, y %d\n", viewdir / M_PI, bounce->x, bounce->y);
			// }

			
			if isnan(z_height) // debug
				puts("NAN value found!!"); // debug


			// printf("DEBUG x: %d, y: %d, z_angle %lf\nz_height %lf\n", x, y, z_angle, z_height); // debug
			if (z_height >= 1)
			{
				mlx_put_pixel(data->img_data->main_screen, x, y,
					data->img_data->ceiling->argb);
			}
			else if (z_height < 0)
			{
				mlx_put_pixel(data->img_data->main_screen,
					x, y, data->img_data->floor->argb);
			}
			else
			{
				n_pixel = pixel_from_texure(test_texture, (double)y / data->screen_height, (double)x / data->screen_width);
				mlx_put_pixel(data->img_data->main_screen, x, y, n_pixel);
			}
			y += 1;
		}
		x += 1;
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
	// build_minimap(data);

}
