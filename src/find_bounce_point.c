/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bounce_point.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 10:41:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/05 14:27:37 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/***
 * @brief, calulates the bounce point at a given y value, based on current
 * position and view direction
 * @note, assumes bounce->y is already set
*/
static bool	define_horizontal_bounce(t_bounce *bounce, double viewdir,
	t_data *data)
{
	double	d_y;
	double	d_x;

	d_y = (bounce->y + check_looking_up(viewdir)) - data->p_ypos;
	d_x = d_y * tan(viewdir);
	bounce->bounce_position = fmod(data->p_xpos + d_x, 1);
	bounce->x = (int)(data->p_xpos + d_x);
	if (data->p_xpos + d_x < 0
		|| is_out_of_map(bounce->x, bounce->y, data))
	{
		return (NULL);
	}
	if (is_wall(bounce->x, bounce->y, data))
	{
		bounce->distance = sqrt(d_x * d_x + d_y * d_y);
		return (true);
	}
	return (false);
}

/***
 * @param viewdir view direction in rad: 0 rad is south, pi/2 rad is east
*/
t_bounce	*get_horizontal_bounce(t_data *data, double viewdir)
{
	t_bounce	*bounce;
	bool		bounce_found;

	bounce_found = false;
	if (cos(viewdir) > -0.001 && cos(viewdir) < 0.001)
		return (NULL);
	bounce = malloc(sizeof(t_bounce));
	if (bounce == NULL)
		return (NULL);
	bounce->y = (int)(data->p_ypos) + 1 - 2 * check_looking_up(viewdir);
	while (bounce->y >= 0 && bounce->y < data->grid_height)
	{
		if (define_horizontal_bounce(bounce, viewdir, data))
		{
			bounce_found = true;
			break ;
		}
		bounce->y += (1 - 2 * check_looking_up(viewdir));
	}
	if (bounce_found == false)
	{
		free(bounce);
		return (NULL);
	}
	return (bounce);
}
