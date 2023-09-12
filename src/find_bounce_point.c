/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bounce_point.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 10:41:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/12 12:15:41 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/***
 * @brief, calulates the bounce point at a given y value, based on current
 * position and view direction
 * @note, assumes bounce->y is already set
 * @param viewdir the horizontal viewdir of the pixel being calculated
*/
static bool	define_horizontal_bounce(t_bounce *bounce, double viewdir,
	t_data *data)
{
	double	d_y;
	double	d_x;

	d_y = (bounce->y + check_looking_up(viewdir)) - data->p_ypos;
	d_x = d_y * tan(viewdir);
	if (check_looking_up(viewdir))
		bounce->bounce_position = fmod(data->p_xpos + d_x, 1);
	else
		bounce->bounce_position = 1 - fmod(data->p_xpos + d_x, 1);
	bounce->x = (int)(data->p_xpos + d_x);
	if (data->p_xpos + d_x < 0
		|| is_out_of_map(bounce->x, bounce->y, data))
	{
		return (NULL);
	}
	if (is_wall(bounce->x, bounce->y, data))
	{
		bounce->distance = sqrt(d_x * d_x + d_y * d_y);
		if (check_looking_up(viewdir))
			bounce->texture = data->img_data->wall_textures[SOUTH];
		else
			bounce->texture = data->img_data->wall_textures[NORTH];
		return (true);
	}
	return (false);
}

/***
 * @brief, calulates the bounce point at a given x value, based on current
 * position and view direction
 * @note, assumes bounce->x is already set
*/
static bool	define_vertical_bounce(t_bounce *bounce, double viewdir,
	t_data *data)
{
	double	d_y;
	double	d_x;

	d_x = (bounce->x + check_looking_left(viewdir)) - data->p_xpos;
	d_y = d_x / tan(viewdir);
	if (check_looking_left(viewdir) == false)
		bounce->bounce_position = fmod(data->p_ypos + d_y, 1);
	else
		bounce->bounce_position = 1 - fmod(data->p_ypos + d_y, 1);
	bounce->y = (int)(data->p_ypos + d_y);
	if (data->p_ypos + d_y < 0
		|| is_out_of_map(bounce->x, bounce->y, data))
	{
		return (NULL);
	}
	if (is_wall(bounce->x, bounce->y, data))
	{
		bounce->distance = sqrt(d_x * d_x + d_y * d_y);
		if (check_looking_left(viewdir))
			bounce->texture = data->img_data->wall_textures[EAST];
		else
			bounce->texture = data->img_data->wall_textures[WEST];
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

t_bounce	*get_vertical_bounce(t_data *data, double viewdir)
{
	t_bounce	*bounce;
	bool		bounce_found;

	bounce_found = false;
	if (sin(viewdir) > -0.001 && sin(viewdir) < 0.001)
		return (NULL);
	bounce = malloc(sizeof(t_bounce));
	if (bounce == NULL)
		return (NULL);
	bounce->x = (int)(data->p_xpos) + 1 - 2 * check_looking_left(viewdir);
	while (bounce->x >= 0 && bounce->x < data->grid_width)
	{
		if (define_vertical_bounce(bounce, viewdir, data))
		{
			bounce_found = true;
			break ;
		}
		bounce->x += (1 - 2 * check_looking_left(viewdir));
	}
	if (bounce_found == false)
	{
		free(bounce);
		return (NULL);
	}
	return (bounce);
}

t_bounce	*get_bounce(t_data *data, double viewdir)
{
	t_bounce	*bounce_hor;
	t_bounce	*bounce_vert;

	bounce_vert = get_vertical_bounce(data, viewdir);
	bounce_hor = get_horizontal_bounce(data, viewdir);
	if (bounce_vert == NULL && bounce_hor == NULL)
	{
		printf("error: no bounce found!");
		return (NULL);
	}
	if (bounce_vert == NULL)
		return (bounce_hor);
	if (bounce_hor == NULL)
		return (bounce_vert);
	if (bounce_vert->distance < bounce_hor->distance)
	{
		free(bounce_hor);
		return (bounce_vert);
	}
	else
	{
		free(bounce_vert);
		return (bounce_hor);
	}
}
