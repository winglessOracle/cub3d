/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 15:41:04 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/01 15:42:42 by cwesseli      ########   odam.nl         */
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

void	check_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->img_data->wall_textures[i])
			free_str_exit("loading texture", data, 7);
		i++;
	}
}
