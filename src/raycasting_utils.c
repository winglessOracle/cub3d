/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 14:23:17 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/05 14:25:07 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// viewdirection 0, means looking down (south); viewdir is counter clockwise
bool	check_looking_up(double viewdir)
{
	return (viewdir > M_PI_2 && viewdir < M_PI_2 + M_PI);
}

bool	check_looking_left(double viewdir)
{
	return (viewdir > M_PI);
}

bool	is_wall(int x, int y, t_data *data)
{
	if (x < 0 || y < 0)
		return (false);
	if (x >= data->grid_width || y >= data->grid_height)
		return (false);
	if (data->grid[y][x] == '1')
		return (true);
	else
		return (false);
}

bool	is_out_of_map(int x, int y, t_data *data)
{
	return (x < 0 || y < 0 || x >= data->grid_width || y >= data->grid_height);
}
