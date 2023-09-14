/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 14:43:27 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/14 13:11:29 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook_repeat(void *param)
{
	t_data		*data;

	data = param;
	if (mlx_get_time() >= data->last_pixelate + data->update_rate)
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
	}
}

void	key_hook_single(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("%s\nYou left the game\n\n%s", GREEN, RESET);
		mlx_terminate(data->mlx);
		free_exit(data, 0);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		data->mm->toggle_mm = toggle(data->mm->toggle_mm);
		build_image(data);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		data->toggle_mouse = toggle(data->toggle_mouse);
}

void	ft_mouse_hook(void *param)
{
	t_data		*data;
	int			delta_x;
	double		delta_view;

	data = param;
	if (data->toggle_mouse)
	{
		delta_x = 0;
		delta_view = 0;
		if (mlx_get_time() >= data->last_pixelate + data->update_rate)
			mlx_get_mouse_pos(data->mlx, &data->mouse_xpos, &data->mouse_ypos);
		delta_x = data->mouse_xpos - data->previous_mouse_x;
		data->previous_mouse_x = data->mouse_xpos;
		delta_view = delta_x * data->mouse_sensitivity;
		if (delta_view < -0.1)
			turn_player('L', data);
		else if (delta_view > 0.1)
			turn_player('R', data);
	}
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
	mlx_loop_hook(data->mlx, key_hook_repeat, data);
	mlx_key_hook(data->mlx, key_hook_single, data);
	mlx_loop_hook(data->mlx, ft_mouse_hook, data);
	mlx_close_hook(data->mlx, close_hook, data);
}
