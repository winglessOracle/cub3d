/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 11:48:34 by carlowessel   ########   odam.nl         */
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
		free_str_exit("allocating structs", data, 2);
	malloc_structs(data);
	init_data(argv[1], data);
	mlx_loop(data->mlx_data->mlx);
}
