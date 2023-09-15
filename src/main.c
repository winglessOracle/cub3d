/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/15 11:01:23 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(char *input_file, t_data *data)
{
	init_main_data(data);
	init_check_data(data);
	init_img_data(data);
	data->grid = generate_grid(input_file);
	if (!data->grid)
		free_str_exit("generating grid from input file", data, 9);
	parse_file_paths(input_file, data);
	analyze_grid(data);
	square_grid(data);
	init_minimap(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_params(argc, argv))
		return (1);
	malloc_structs(&data);
	init_data(argv[1], &data);
	build_image(&data);
	set_hooks(&data);
	mlx_loop((&data)->mlx);
	mlx_terminate((&data)->mlx);
	free_all(&data);
	return (EXIT_SUCCESS);
}
