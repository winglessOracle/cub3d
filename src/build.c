/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 09:11:58 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/23 12:58:56 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_images(t_data *data)
{
	data->img_data->main_screen
		= mlx_new_image(data->mlx, data->screen_width, data->screen_height);

	test_images(data);
}
