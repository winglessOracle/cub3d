/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:52:40 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/26 14:44:13 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_move(int y, int x, char **grid)
{
	if (grid[y][x] != '1')
		return (true);
	return (false);
}

void	move_forward(t_data *data)
{
	if (check_valid_move(data->p_ypos - 1, data->p_xpos, data->grid))
	{
		data->p_ypos -= 1;
		test_print_movement("MOVE FORWARD", data); // remove
		build_image(data);
	}
}

void	move_backward(t_data *data)
{
	if (check_valid_move(data->p_ypos + 1, data->p_xpos, data->grid))
	{
		data->p_ypos += 1;
		test_print_movement("MOVE BACKWARD", data); // remove
		build_image(data);
	}
}

void	move_right(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos + 1, data->grid))
	{
		data->p_xpos += 1;
		test_print_movement("MOVE RIGHT", data); // remove
		build_image(data);
	}
}

void	move_left(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos - 1, data->grid))
	{
		data->p_xpos -= 1;
		data->p_viewdir = 270;
		test_print_movement("MOVE LEFT", data); // remove
		build_image(data);
	}
}

void	turn(char c, t_data *data)
{
	if (c == 'L')
	{
		data->p_viewdir -= 90;
		test_print_movement("TURN LEFT", data); // remove
	}
	else if (c == 'R')
	{
		data->p_viewdir += 90;
		test_print_movement("TURN RIGHT", data); // remove
	}
	data->p_viewdir = fmod(data->p_viewdir, 360.0);
	if (data->p_viewdir < 0)
		data->p_viewdir += 360;
	build_image(data);
}
