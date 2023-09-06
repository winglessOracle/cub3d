/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 12:09:34 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/06 14:42:17 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/***
 * @brief 'eye' is at half the wall height. 
 * The wall height is relative to size of one grid element.
 * valid angles are 'forward looking',
 * between 90 degrees up and 90 degrees down
*/
double	calc_z_height(double dist, double z_angle)
{
	if ((z_angle < 0) 
		|| (z_angle >= 2 * M_PI)
		|| ((z_angle > M_PI_2 - 0.001) && (z_angle < M_PI + M_PI_2 + 0.001)))
	{
		return (NAN);
	}
	return (0.5 * WALL_HEIGHT + tan(z_angle) * dist);
}
