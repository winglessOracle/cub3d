/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 15:41:04 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/04 10:52:56 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_params(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n%sinvallid number of arguments. required: 1\n", RED);
		return (1);
	}
	if (ft_check_extention(argv[1], "cub"))
	{
		printf("\n%sinvallid extention. required: '.cub'\n", RED);
		return (1);
	}
	return (0);
}

void	check_input_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->check_data->textures_loaded != 4)
		free_str_exit("input file contains more or less than 4 textures",
			data, 7);
	if (data->check_data->colors_loaded != 2)
		free_str_exit("input file contains more or less than 2 colors",
			data, 7);
	while (i < 4)
	{
		if (!data->img_data->wall_textures[i])
			free_str_exit("loading texture", data, 7);
		i++;
	}
}
