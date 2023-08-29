/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:52:40 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 23:04:51 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_move(double y, double x, t_data *data)
{
	if (data->grid[(int)round(y)][(int)round(x)] == '1')
		return (false);
	return (true);
}

void	move_forward(t_data *data)
{
	double	vx;
	double	vy;

	vy = data->move_increment * cos(data->p_viewdir);
	vx = data->move_increment * sin(data->p_viewdir);
	if (check_valid_move(data->p_ypos + vy, data->p_xpos + vx, data))
	{
		data->p_ypos += vy;
		data->p_xpos += vx;
		test_print_movement("MOVE FORWARD", data); // remove
		build_image(data);
	}
}

void	move_backward(t_data *data)
{
	double	vx;
	double	vy;

	vy = data->move_increment * cos(data->p_viewdir + M_PI);
	vx = data->move_increment * sin(data->p_viewdir + M_PI);
	if (check_valid_move(data->p_ypos + vy, data->p_xpos + vx, data))
	{
		data->p_ypos += vy;
		data->p_xpos += vx;
		test_print_movement("MOVE BACKWARD", data); // remove
		build_image(data);
	}
}

void	move_right(t_data *data)
{
	double	vx;
	double	vy;

	vy = data->move_increment * cos(data->p_viewdir - M_PI_2);
	vx = data->move_increment * sin(data->p_viewdir - M_PI_2);
	if (check_valid_move(data->p_ypos + vy, data->p_xpos + vx, data))
	{
		data->p_ypos += vy;
		data->p_xpos += vx;
		test_print_movement("MOVE RIGHT", data); // remove
		build_image(data);
	}
}

void	move_left(t_data *data)
{
	double	vx;
	double	vy;

	vy = data->move_increment * cos(data->p_viewdir + M_PI_2);
	vx = data->move_increment * sin(data->p_viewdir + M_PI_2);
	if (check_valid_move(data->p_ypos + vy, data->p_xpos + vx, data))
	{
		data->p_ypos += vy;
		data->p_xpos += vx;
		test_print_movement("MOVE LEFT", data); // remove
		build_image(data);
	}
}

void	turn(char c, t_data *data)
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
