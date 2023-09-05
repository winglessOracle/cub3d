/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/19 08:29:28 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/05 14:34:01 by cherrewi      ########   odam.nl         */
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

	// --------------------
	// testing
	
	data->p_xpos = 1;
	data->p_ypos = 1;
	test_print_grid(data); // remove

	double viewdir;
	t_bounce *bounce;
	
	viewdir = M_PI_4; // look south-east
	// viewdir = M_PI_4 + M_PI_2;  // look norht-east;
	// viewdir = M_PI;  // look north
	// viewdir = M_PI + M_PI_2 + M_PI_4;  // look south-west

	printf("View dir:\t%f RAD (%.4f π RAD)\n",viewdir, viewdir / M_PI);
	bounce = get_horizontal_bounce(data, viewdir);
	if (bounce == NULL)
		puts("no bounce found!");
	else
	{
		printf("distance: %lf\n", bounce->distance);
		printf("x: %d\n", bounce->x);
		printf("y: %d\n", bounce->y);
		printf("pos: %lf\n", bounce->bounce_position);
	}
	// ------------------

	build_image(data);
	set_hooks(data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
