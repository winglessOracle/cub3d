/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:40:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/22 16:57:54 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_data *data)
{
	if (data->check_data)
		free(data->check_data);
	if (data->mlx_data)
		free(data->mlx_data);
	if (data->mlx_data->floor)
		free(data->mlx_data->floor);
	if (data->mlx_data->ceiling)
		free(data->mlx_data->ceiling);
	if (data->grid)
		ft_free_array(data->grid);
	if (data)
		free(data);
}

int	free_exit(t_data *data)
{
	free_all(data);
	exit(EXIT_FAILURE);
}

void	free_str_exit(char *str, t_data *data, int error)
{
	printf("\n%sERROR: %s%s\n", RED, str, RESET);
	free_all(data);
	exit(error);
}

void	flood_fill(int x, int y, char **grid, t_data *data)
{
	if (x < 0 || x > data->grid_width - 1 || y < 0 || y > data->grid_height - 1)
	{
		ft_free_array(grid);
		free_str_exit("map not enclosed by walls", data, 8);
	}
	if (grid[y][x] == '1')
		return ;
	if (grid[y][x] != 'f')
	{
		grid[y][x] = 'f';
		flood_fill(x + 1, y, grid, data);
		flood_fill(x - 1, y, grid, data);
		flood_fill(x, y + 1, grid, data);
		flood_fill(x, y - 1, grid, data);
	}
}

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
