/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:43:27 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/07 09:58:22 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_hook(void *param)
{
	t_data		*data;
	static int	frame_counter = 0;

	data = param;
	frame_counter ++;
	if (frame_counter >= data->movement_rate)
	{
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
		frame_counter = 0;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("%s\nYou left the game\n\n%s", GREEN, RESET);
		mlx_terminate(data->mlx);
		free_exit(data, 0);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		toggle_mm(data);
}

void	ft_mouse_hook(void *param)
{
	t_data		*data;
	int			delta_x;
	double		delta_view;
	static int	frame_counter = 0;

	data = param;
	delta_x = 0;
	delta_view = 0;
	frame_counter ++;
	if (frame_counter >= data->movement_rate)
		mlx_get_mouse_pos(data->mlx, &data->mouse_xpos, &data->mouse_ypos);
	delta_x = data->mouse_xpos - data->previous_mouse_x;
	data->previous_mouse_x = data->mouse_xpos;
	delta_view = delta_x * data->mouse_sensitivity;
	if (delta_view < -0.1)
		turn_player('R', data);
	else if (delta_view > 0.1)
		turn_player('L', data);
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
