/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/23 12:31:27 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/18 17:54:18 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delete_textures(mlx_texture_t **textures, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
	free(textures);
}

void	free_all(t_data *data)
{
	if (data->check_data)
		free(data->check_data);
	if (data->img_data->floor)
		free(data->img_data->floor);
	if (data->img_data->ceiling)
		free(data->img_data->ceiling);
	if (data->img_data->wall_texture_paths)
		ft_free_array(data->img_data->wall_texture_paths);
	if (data->img_data->wall_textures)
		delete_textures(data->img_data->wall_textures, data->check_data->textures_loaded);
	if (data->mm)
		free(data->mm);
	if (data->img_data)
		free(data->img_data);
	if (data->grid)
		ft_free_array(data->grid);
}

int	free_exit(t_data *data, int n)
{
	free_all(data);
	if (n == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_str_exit(char *str, t_data *data, int error)
{
	printf("\n%sERROR: %s%s\n", RED, str, RESET);
	free_all(data);
	exit(error);
}
