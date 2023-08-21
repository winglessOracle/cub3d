/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 00:03:12 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	*data;
	
	if(check_params(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (2);
	if (malloc_structs(data))
		return (3);
	if (init_data(argv[1], data))
		return (free_all_return(2, data));
	mlx_loop(data->mlx);
}