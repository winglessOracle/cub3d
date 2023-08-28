/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/26 14:58:30 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/28 15:36:50 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_data *data)
{
	if (data->p_viewdir == 0)
		move_up(data);
	if (data->p_viewdir == M_PI_2)
		move_right(data);
	if (data->p_viewdir == M_PI)
		move_down(data);
	if (data->p_viewdir == M_PI + M_PI_2)
		move_left(data);
}

void	move_s(t_data *data)
{
	if (data->p_viewdir == 0)
		move_down(data);
	if (data->p_viewdir == M_PI_2)
		move_left(data);
	if (data->p_viewdir == M_PI)
		move_up(data);
	if (data->p_viewdir == M_PI + M_PI_2)
		move_right(data);
}

void	move_a(t_data *data)
{
	if (data->p_viewdir == 0)
		move_left(data);
	if (data->p_viewdir == M_PI_2)
		move_up(data);
	if (data->p_viewdir == M_PI)
		move_right(data);
	if (data->p_viewdir == M_PI + M_PI_2)
		move_down(data);
}

void	move_d(t_data *data)
{
	if (data->p_viewdir == 0)
		move_right(data);
	if (data->p_viewdir == M_PI_2)
		move_down(data);
	if (data->p_viewdir == M_PI)
		move_left(data);
	if (data->p_viewdir == M_PI + M_PI_2)
		move_up(data);
}
