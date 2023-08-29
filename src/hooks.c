/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:43:27 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 23:34:11 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(data->p_viewdir, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(data->p_viewdir + M_PI, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(data->p_viewdir + M_PI_2, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(data->p_viewdir - M_PI_2, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		turn_player('L', data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		turn_player('R', data);
	build_minimap(data);
	//if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
	// 	restart_map;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("%s\nYou left the game\n\n%s", GREEN, RESET);
		free_exit(data, 0); // mlx_close_window
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		toggle_mm(data);
	// if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	// 	restart_map("levels/level_1.ber", g);
}

void	ft_mouse_hook(void *param)
{
	t_data	*data;

	(void)data;
	data = param;
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
	mlx_loop_hook(data->mlx, ft_key_hook, data);
	mlx_loop_hook(data->mlx, ft_mouse_hook, data);
	mlx_key_hook(data->mlx, key_hook, data);
	mlx_close_hook(data->mlx, close_hook, data);
}
