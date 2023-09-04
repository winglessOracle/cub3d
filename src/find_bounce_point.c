/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bounce_point.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 10:41:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/04 11:39:50 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(int x, int y, t_data *data)
{
	if (x >= data->grid_width || y >= data->grid_height)
		return (false);
	if (data->grid[y][x] == '1')
		return (true);
	else
		return (false);
}
