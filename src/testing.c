/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 18:50:59 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 09:22:26 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_test_pixel(double ix, double iy, t_data *data)
{
	mlx_texture_t	*test;
	int				color;
	int				x;
	int				y;

	x = 0;
	y = 0;
	test = mlx_load_png("./textures/test.png");
	color = pixel_from_texure(test, ix, iy);
	while (y < data->screen_height)
	{
		while (x < data->screen_width)
		{
			if (y < data->screen_height / 4 && x < data->screen_width / 4)
				mlx_put_pixel(data->img_data->main_screen,
					x, y, color);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	mlx_put_string(data->mlx, "Test color picker", 30 , 20);
}

void	test_print_grid(t_data *data)
{
	int	y;

	y = 0;
	printf("\n%s==========TEST PRINT GRID==================%s\n", GREEN, RESET);
	while (y < data->grid_height)
	{
		printf("%s\n", data->grid[y]);
		y++;
	}
	printf("\nGrid height:\t%d\n", data->grid_height);
	printf("Grid width:\t%d\n", data->grid_width);
	printf("Player xpos:\t%f\nPlayer ypos:\t%f\n", data->p_xpos, data->p_ypos);
	printf("View dir:\t%f RAD\n", data->p_viewdir);
	printf("%s=============================================\n%s", GREEN, RESET);
}

void	test_print_data(t_data *data)
{
	printf("\n%s==========TESTFILE DATA====================%s\n", GREEN, RESET);
	printf("north: %s\n", data->img_data->wall_texture_paths[0]);
	printf("east: %s\n", data->img_data->wall_texture_paths[1]);
	printf("south: %s\n", data->img_data->wall_texture_paths[2]);
	printf("west: %s\n", data->img_data->wall_texture_paths[3]);
	printf("ceiling: %s\n", data->img_data->ceiling->color);
	printf("\tceiling_RED: %d\n", data->img_data->ceiling->red);
	printf("\tceiling_GREEN: %d\n", data->img_data->ceiling->green);
	printf("\tceiling_BLUE: %d\n", data->img_data->ceiling->blue);
	printf("\tceiling RGBA: 0x%08x\n", data->img_data->ceiling->argb);
	printf("\tceiling RGBA: %d\n", data->img_data->ceiling->argb);
	printf("floor: %s\n", data->img_data->floor->color);
	printf("\tfloor_RED: %d\n", data->img_data->floor->red);
	printf("\tfloor_GREEN: %d\n", data->img_data->floor->green);
	printf("\tfloor_BLUE: %d\n", data->img_data->floor->blue);
	printf("\tfloor RGBA: 0x%08x\n", data->img_data->floor->argb);
	printf("\tfloor RGBA: %d\n", data->img_data->floor->argb);
	printf("%s============================================\n%s", GREEN, RESET);
}

void	test_print_images(t_data *data)
{
	mlx_image_t	*test_wall	= mlx_texture_to_image(data->mlx, data->img_data->wall_textures[0]);
	mlx_image_t	*test_wall2	= mlx_texture_to_image(data->mlx, data->img_data->wall_textures[1]);
	mlx_image_t	*test_wall3	= mlx_texture_to_image(data->mlx, data->img_data->wall_textures[2]);
	mlx_image_t	*test_wall4	= mlx_texture_to_image(data->mlx, data->img_data->wall_textures[3]);
	mlx_image_to_window(data->mlx, test_wall, 0, 300);
	mlx_image_to_window(data->mlx, test_wall2, 200, 300);
	mlx_image_to_window(data->mlx, test_wall3, 400, 300);
	mlx_image_to_window(data->mlx, test_wall4, 600, 300);
}

void	test_print_movement(char *str, t_data *data)
{
	printf("\n%s======== %s ============\n%s", GREEN, str, RESET);
	printf("X:%f\tY:%f\n", data->p_xpos, data->p_ypos);
	printf("looking at %f RAD\n", data->p_viewdir);
}
