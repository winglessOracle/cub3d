/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 17:36:34 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/05 17:39:30 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>
# include <assert.h>


void	test_bounce(t_data *data)
{
	t_bounce	*bounce;

	puts("testing get_horizontal_bounce() ...");

	// HORIZONTAL BOUNCE
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 0);
	// printf("distance: %lf\n", bounce->distance);
	// printf("x: %d\n", bounce->x);
	// printf("y: %d\n", bounce->y);
	// printf("bounce_position: %lf\n", bounce->bounce_position);
	assert(bounce != NULL);
	assert(bounce->x == 1);
	assert(bounce->y == 3);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 1/12);
	assert(bounce != NULL);
	assert(bounce->x == 2);
	assert(bounce->y == 3);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 2/12);
	assert(bounce == NULL);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 3/12);
	assert(bounce == NULL);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 4/12);
	assert(bounce != NULL);
	assert(bounce->x == 2);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 5/12);
	assert(bounce != NULL);
	assert(bounce->x == 1);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 6/12);
	assert(bounce != NULL);
	assert(bounce->x == 1);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 7/12);
	assert(bounce != NULL);
	assert(bounce->x == 1);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 8/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 9/12);
	assert(bounce == NULL);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 10/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 2);
	free(bounce);
	// ----------------------------------
	bounce = get_horizontal_bounce(data, 2 * M_PI * 11/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 3);
	free(bounce);

	puts("OK");
	// ----------------------------------

	// VERTICAL BOUNCE
	puts("testing get_vertical_bounce() ...");
	// ----------------------------------
	bounce = get_vertical_bounce(data, 0);
	assert(bounce == NULL);
	// // ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 1/12);
	assert(bounce == NULL);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 2/12);
	assert(bounce->x == 3);
	assert(bounce->y == 2);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 3/12);
	assert(bounce != NULL);
	assert(bounce->x == 3);
	assert(bounce->y == 1);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 4/12);
	assert(bounce != NULL);
	assert(bounce->x == 3);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 5/12);
	assert(bounce != NULL);
	assert(bounce->x == 2);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 6/12);
	assert(bounce == NULL);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 7/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 0);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 8/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 1);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 9/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 1);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 10/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 1);
	free(bounce);
	// ----------------------------------
	bounce = get_vertical_bounce(data, 2 * M_PI * 11/12);
	assert(bounce != NULL);
	assert(bounce->x == 0);
	assert(bounce->y == 2);
	free(bounce);

	puts("OK");
	// ----------------------------------
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (check_params(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		free_str_exit("allocating struct", data, 2);
	malloc_structs(data);
	init_data(argv[1], data);
	data->p_xpos = 1.5;
	data->p_ypos = 1.5;

	test_print_grid(data);
	test_bounce(data);
}
