/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 12:09:34 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/11 14:50:49 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calc horizontal pixel view dir, relative to player viewdir
double	calc_pix_view_dir(int x, t_data *data)
{
	const double	fov_hor = M_PI_2;
	double			pix_hor_view_dir;

	pix_hor_view_dir = data->p_viewdir
		+ (fov_hor / 2) - ((double)x / data->screen_width) * fov_hor;
	if (pix_hor_view_dir < 0)
		pix_hor_view_dir += 2 * M_PI;
	if (pix_hor_view_dir > 2 * M_PI)
		pix_hor_view_dir -= 2 * M_PI;
	return (pix_hor_view_dir);
}

// calc vertical view dir.
// fov is 60 degrees: (30 deg up + 30 deg down)
double	calc_z_angle(int y, t_data *data)
{
	const double	fov_vert = M_PI / 3;
	double			pix_vert_view_dir;

	pix_vert_view_dir = (fov_vert / 2)
		- ((double)y / (data->screen_height - 1)) * fov_vert;
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
