/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:52:40 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 23:36:14 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_move(double y, double x, t_data *data)
{
	if (data->grid[(int)round(y)][(int)round(x)] == '1')
		return (false);
	return (true);
}

void	move_player(double rad, t_data *data)
{
	double	vx;
	double	vy;

	vy = data->move_increment * cos(fmod(rad, 2 * M_PI));
	vx = data->move_increment * sin(fmod(rad, 2 * M_PI));
	if (check_valid_move(data->p_ypos + vy, data->p_xpos + vx, data))
	{
		data->p_ypos += vy;
		data->p_xpos += vx;
		test_print_movement("MOVED", data); // remove
		build_image(data);
	}
}

void	turn_player(char c, t_data *data)
{
	if (c == 'L')
		data->p_viewdir -= data->turn_increment;
	if (c == 'R')
		data->p_viewdir += data->turn_increment;
	data->p_viewdir = fmod(data->p_viewdir, 2 * M_PI);	
	if (data->p_viewdir < 0)
		data->p_viewdir += 2 * M_PI;
	test_print_movement("TURNED", data); // remove
	build_image(data);
}
