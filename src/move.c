/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:52:40 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 14:52:43 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_valid_move(int y, int x, char **grid)
{
	if (grid[y][x] != '1')
		return (true);
	return (false);
}

void	move_up(t_data *data)
{
	if (check_valid_move(data->p_ypos - 1, data->p_xpos, data->grid))
	{
		data->p_ypos -= data->move_increment;
		test_print_movement("MOVE UP", data); // remove
		build_image(data);
	}
}

void	move_down(t_data *data)
{
	if (check_valid_move(data->p_ypos + 1, data->p_xpos, data->grid))
	{
		data->p_ypos += data->move_increment;
		test_print_movement("MOVE DOWN", data); // remove
		build_image(data);
	}
}

void	move_right(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos + 1, data->grid))
	{
		data->p_xpos += data->move_increment;
		test_print_movement("MOVE RIGHT", data); // remove
		build_image(data);
	}
}

void	move_left(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos - 1, data->grid))
	{
		data->p_xpos -= data->move_increment;
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
	if (data->p_viewdir < 0)
		data->p_viewdir += 2 * M_PI;
	else if (data->p_viewdir >= 2 * M_PI)
		data->p_viewdir -= 2 * M_PI;
	test_print_movement("TURNED", data); // remove
	build_image(data);
}
