/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/05 17:36:34 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/06 12:56:00 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>
# include <assert.h>

void	test_bounce(t_data *data);
void	test_calc_z_height(void);

static void init(int argc, char **argv, t_data *data)
{
	if (check_params(argc, argv))
		return ;

	malloc_structs(data);
	init_data(argv[1], data);
	data->p_xpos = 1.5;
	data->p_ypos = 1.5;
}

int main(int argc, char **argv)
{
	t_data	data;

	init(argc, argv, &data);
	test_print_grid(&data);

	test_bounce(&data);
	test_calc_z_height();
}
