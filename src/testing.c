/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 18:50:59 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/21 21:02:25 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_grid(t_data *data)
{
	int y;

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
	