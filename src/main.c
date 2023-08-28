/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/28 15:05:48 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_params(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		free_str_exit("allocating struct", data, 2);
	malloc_structs(data);
	init_data(argv[1], data);
	build_image(data);
	set_hooks(data);
	mlx_loop(data->mlx);
}
