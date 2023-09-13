/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 12:09:34 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/13 21:22:32 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calc horizontal pixel view dir, relative to player viewdir
// fov horizontal is 90 degrees: (45 deg left + 45 deg right)
// tan (45 degrees) == 1
double	calc_pix_view_dir(int x, t_data *data)
{
	double			pix_hor_view_dir;
	int				d_x;

	d_x = (data->screen_width / 2) - x;
	pix_hor_view_dir = data->p_viewdir
		+ atan((double)d_x / (data->screen_width / 2));
	if (pix_hor_view_dir < 0)
		pix_hor_view_dir += 2 * M_PI;
	return (pix_hor_view_dir);
}

// calc vertical view dir.
// fov vertical is 60 degrees: (30 deg up + 30 deg down), 
// tan(30 degrees) == 1/sqrt(3)
double	calc_z_angle(int y, t_data *data)
{
	double			pix_vert_view_dir;
	int				d_y;

	d_y = (data->screen_height / 2) - y;
	pix_vert_view_dir = atan(M_SQRT1_3 * d_y / (data->screen_height / 2));
	if (pix_vert_view_dir < 0)
		pix_vert_view_dir += 2 * M_PI;
	return (pix_vert_view_dir);
}

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
