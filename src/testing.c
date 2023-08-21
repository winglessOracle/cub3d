/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 18:50:59 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/21 18:57:24 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_grid(t_data *data)
{
	for (int i = 0; i < 14; i++)
		printf("%s\n", data->grid[i]);
	printf("\nhight=%d\n", data->grid_height);
	printf("width=%d\n", data->grid_width);	
	printf("player xpos=%d\typos=%d\n", data->p_xpos, data->p_ypos);	
	printf("view dir=%d\n", data->p_viewdir);

}
	