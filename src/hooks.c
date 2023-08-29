/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:43:27 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 09:12:03 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("%s\nYou left the game\n\n%s", GREEN, RESET);
		free_exit(data, 0);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_w(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_s(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_a(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_d(data);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		turn('L', data);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		turn('R', data);
	// if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	// 	restart_map("levels/level_1.ber", g);
	//toggle minimap?
}

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)data;
	(void)button;
	(void)action;
	(void)mods;
	data = param;
	//ad function
}

void	close_hook(void *param)
{
	t_data	*data;

	data = param;
	printf("%s\nYou left the game\n\n%s", GREEN, RESET);
	mlx_terminate(data->mlx);
	free_exit(data, 0);
}

void	set_hooks(t_data *data)
{
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_mouse_hook(data->mlx, mouse_hook, data);
	mlx_close_hook(data->mlx, close_hook, data);
}
