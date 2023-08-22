/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 18:50:59 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 15:58:55 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_grid(t_data *data)
{
	int	y;

	y = 0;
	printf("\n==========TEST PRINT GRID===============================\n");
	while (y < data->grid_height)
	{
		printf("%s\n", data->grid[y]);
		y++;
	}
	printf("\nGrid hight:\t%d\n", data->grid_height);
	printf("Grid width:\t%d\n", data->grid_width);
	printf("Player xpos:\t%d\nPlayer ypos:\t%d\n", data->p_xpos, data->p_ypos);
	printf("View dir:\t%d\n", data->p_viewdir);
	printf("========================================================\n");
}

void	print_file_data(t_data *data)
{
	printf("north: %s\n", data->mlx_data->north_texure);
	printf("east: %s\n", data->mlx_data->east_texture);
	printf("south: %s\n", data->mlx_data->south_texture);
	printf("west: %s\n", data->mlx_data->west_texture);
	printf("ceiling: %s\n", data->mlx_data->ceiling->color);
	printf("\tceiling_RED: %d\n", data->mlx_data->ceiling->red);
	printf("\tceiling_GREEN: %d\n", data->mlx_data->ceiling->green);
	printf("\tceiling_BLUE: %d\n", data->mlx_data->ceiling->blue);
	printf("floor: %s\n", data->mlx_data->floor->color);
	printf("\tfloor_RED: %d\n", data->mlx_data->floor->red);
	printf("\tfloor_GREEN: %d\n", data->mlx_data->floor->green);
	printf("\tfloor_BLUE: %d\n", data->mlx_data->floor->blue);
}
