/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:52:40 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/23 18:47:05 by carlowessel   ########   odam.nl         */
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
		data->p_ypos -= 1;
		data->p_viewdir = 0;
		test_print_movement("UP", data); // remove
		//build_image(data);
		//build_minimap(data);

	}
}

void	move_down(t_data *data)
{
	if (check_valid_move(data->p_ypos + 1, data->p_xpos, data->grid))
	{
		data->p_ypos += 1;
		data->p_viewdir = 180;
		test_print_movement("DOWN", data); // remove
		//build_image(data);
		//build_minimap(data);
	}
}

void	move_right(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos + 1, data->grid))
	{
		data->p_xpos += 1;
		data->p_viewdir = 90;
		test_print_movement("RIGHT", data); // remove
		//build_image(data);
		//build_minimap(data);;
	}
}


void	move_left(t_data *data)
{
	if (check_valid_move(data->p_ypos, data->p_xpos - 1, data->grid))
	{
		data->p_xpos -= 1;
		data->p_viewdir = 270;
		test_print_movement("LEFT", data); // remove
		//build_image(data);
		//build_minimap(data);
	}
}
