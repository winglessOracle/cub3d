/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 23:17:22 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/21 23:23:17 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**generate_grid(char *input_file, t_data *data)
{
	int		fd;
	char	*line;
	char	*joined_lines;
	char	**ret;

	line = "";
	joined_lines = ft_strdup("");
	fd = open(input_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin_free(joined_lines, line);
		data->grid_height++;
		free (line);
	}
	close(fd);
	if (joined_lines[0] == '\0' || joined_lines[0] == '\n')
		return (NULL);
	ret = ft_split(joined_lines, '\n');
	free (joined_lines);
	return (ret);
}

void	set_grid_width(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

void	check_start_pos(int y, int x, t_data *data)
{
	if ((ft_strchr(data->start_char, data->grid[y][x]))) 
	{
		data->start_pos++;
		data->p_xpos = x;
		data->p_ypos = y;
		if (data->grid[y][x] == 'N')
			data->p_viewdir = 0;
		else if (data->grid[y][x] == 'E')
			data->p_viewdir = 90;
		else if (data->grid[y][x] == 'S')
			data->p_viewdir = 180;
		else if (data->grid[y][x] == 'W')
			data->p_viewdir = 270;
	}
}

int	analyze_grid(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->grid_height)
	{
		while (data->grid[y][x])
		{
			while (ft_isspace(data->grid[y][x]))
				x++;
			if (!(ft_strchr(data->valid_char, data->grid[y][x]))) 
				return (printf("\n%sFound non valid characters in map (%c)\n", RED, data->grid[y][x]), 1);
			check_start_pos(y, x, data);
			x++;
		}
		x = 0;
		y++;
	}
	if (data->start_pos != 1)
		return (printf("\n%sWrong amount of starting positions (%d). Required 1\n", RED, data->start_pos), 1);
	return (0);
}

int		check_walls(t_data *data)
{
	char	**flood_grid;
	int		y;
	int		x;

	y = 0;
	flood_grid = malloc(sizeof(char *) * data->grid_height + 1);
	if (!flood_grid)
		return (printf("\n%sERROR: allocating memory for flood fill.\n", RED), 1);
	while (y < data->grid_height)
	{
			flood_grid[y] = ft_strdup(data->grid[y]);
			y++;
	}
	flood_grid[data->grid_height] = NULL;
	x = data->p_xpos;
	y = data->p_ypos;
	flood_fill(x, y, flood_grid, data);
	if(data->bad_check)
		return (ft_free_array(flood_grid), 1);
	return (ft_free_array(flood_grid), 0);
}
