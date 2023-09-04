/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bounce_point.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 10:41:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/04 17:12:41 by cherrewi      ########   odam.nl         */
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

t_bounce *get_horizontal_bounce(t_data *data, double viewdir)
{
	t_bounce	*bounce;
	double		d_y;
	double		d_x;

	bounce = malloc(sizeof(t_bounce));
	if (bounce == NULL)
		return (NULL);
	if (cos(viewdir) > -0.001 && cos(viewdir) < 0.001)
		return (NULL);  // no horizontal bounce, because view is vertically
	bounce->y = (int)(data->p_ypos) + 1 - 2 * check_looking_up(viewdir);
	while (bounce->y >= 0 && bounce->y < data->grid_height)
	{
		d_y = (bounce->y + check_looking_up(viewdir)) - data->p_ypos;
		d_x = d_y * tan(viewdir);
		bounce->bounce_position = fmod(data->p_xpos + d_x, 1);
		bounce->x = (int)(data->p_xpos + d_x);
		if (is_wall(bounce->x, bounce->y, data))
		{
			bounce->distance = sqrt(d_x * d_x + d_y * d_y);
			break;
		}
		if (check_looking_up(viewdir))
			bounce->y -= 1;
		else
			bounce->y += 1;
	}
	return (bounce);
}
