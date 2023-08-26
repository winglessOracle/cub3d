/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/26 14:58:30 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/26 15:08:05 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_data *data)
{
	if ((data->p_viewdir >= 315 && data->p_viewdir <= 360)
		|| (data->p_viewdir >= 0 && data->p_viewdir <= 45))
		move_up(data);
	if (data->p_viewdir >= 45 && data->p_viewdir <= 135)
		move_right(data);
	if (data->p_viewdir >= 135 && data->p_viewdir <= 225)
		move_down(data);
	if (data->p_viewdir >= 225 && data->p_viewdir <= 315)
		move_left(data);
}

void	move_s(t_data *data)
{
	if ((data->p_viewdir >= 315 && data->p_viewdir <= 360)
		|| (data->p_viewdir >= 0 && data->p_viewdir <= 45))
		move_down(data);
	if (data->p_viewdir >= 45 && data->p_viewdir <= 135)
		move_left(data);
	if (data->p_viewdir >= 135 && data->p_viewdir <= 225)
		move_up(data);
	if (data->p_viewdir >= 225 && data->p_viewdir <= 315)
		move_right(data);
}

void	move_a(t_data *data)
{
	if ((data->p_viewdir >= 315 && data->p_viewdir <= 360)
		|| (data->p_viewdir >= 0 && data->p_viewdir <= 45))
			move_left(data);
	if (data->p_viewdir >= 45 && data->p_viewdir <= 135)
		move_up(data);
	if (data->p_viewdir >= 135 && data->p_viewdir <= 225)
		move_right(data);
	if (data->p_viewdir >= 225 && data->p_viewdir <= 315)
		move_down(data);
}

void	move_d(t_data *data)
{
	if ((data->p_viewdir >= 315 && data->p_viewdir <= 360)
		|| (data->p_viewdir >= 0 && data->p_viewdir <= 45))
		move_right(data);
	if (data->p_viewdir >= 45 && data->p_viewdir <= 135)
		move_down(data);
	if (data->p_viewdir >= 135 && data->p_viewdir <= 225)
		move_left(data);
	if (data->p_viewdir >= 225 && data->p_viewdir <= 315)
		move_up(data);
}
