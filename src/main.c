/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/21 11:12:31 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_global	*global;
	
	global = malloc(sizeof(t_global));
	if (!global)
		ft_printf("ERROR");
	global->mlx = mlx_init(200, 100, "cub3d", false);
	mlx_set_window_size(global->mlx, 200, 100);
	mlx_set_window_pos(global->mlx, 300, 200);
	mlx_loop(global->mlx);
	
}