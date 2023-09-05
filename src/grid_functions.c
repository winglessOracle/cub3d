/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 23:17:22 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/05 08:25:50 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_grid_dimensions(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->grid[data->grid_height])
		data->grid_height++;
	while (y < data->grid_height)
	{
		while (data->grid[y][x])
		{
			if (x + 1 > data->grid_width)
				data->grid_width = x + 1;
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_grid(t_data *data)
{
	char	**flood_grid;
	int		y;
	int		x;

	if (data->check_data->start_pos != 1)
	{
		printf("\n%sWrong amount of starting positions (%d).\n", \
			RED, data->check_data->start_pos);
		free_exit(data, 1);
	}
	y = 0;
	flood_grid = malloc(sizeof(char *) * data->grid_height + 1);
	if (!flood_grid)
		free_str_exit("generating flood grid", data, 6);
	while (y < data->grid_height)
	{
		flood_grid[y] = ft_strdup(data->grid[y]);
		y++;
	}
	flood_grid[data->grid_height] = NULL;
	x = data->p_xpos;
	y = data->p_ypos;
	flood_fill(x, y, flood_grid, data);
	ft_free_array(flood_grid);
}

void	set_start_pos(int y, int x, t_data *data)
{
	if ((ft_strchr(data->check_data->start_char, data->grid[y][x]))) 
	{
		data->check_data->start_pos++;
		data->p_xpos = x + 0.5;
		data->p_ypos = y + 0.5;
		if (data->grid[y][x] == 'N')
			data->p_viewdir = M_PI;
		else if (data->grid[y][x] == 'E')
			data->p_viewdir = M_PI_2;
		else if (data->grid[y][x] == 'S')
			data->p_viewdir = 0;
		else if (data->grid[y][x] == 'W')
			data->p_viewdir = M_PI + M_PI_2;
	}
}

void	analyze_grid(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_grid_dimensions(data);
	while (y < data->grid_height)
	{
		while (data->grid[y][x])
		{
			while (ft_isspace(data->grid[y][x]))
				x++;
			if (!(ft_strchr(data->check_data->valid_char, data->grid[y][x])))
			{
				printf("\n%sFound non valid characters in map (%c)\n", \
					RED, data->grid[y][x]);
				free_exit(data, 1);
			}
			set_start_pos(y, x, data);
			x++;
		}
		x = 0;
		y++;
	}
	check_grid(data);
}
