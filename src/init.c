/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 21:06:32 by carlowessel   ########   odam.nl         */
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
				return (printf("%sFound non valid characters in map (%c)\n", RED, data->grid[y][x]), 1);
			check_start_pos(y, x, data);
			x++;
		}
		x = 0;
		y++;
	}
	if (data->start_pos != 1)
		return (printf("%sWrong amount of starting positions (%d). Required 1\n", RED, data->start_pos), 1);
	return (0);
}

int	init_data(char *input_file, t_data *data)
{
	data->mlx 	= mlx_init(1200, 800, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_set_window_pos(data->mlx, 100, 800);
	data->grid_width = 0;
	data->grid_height = 0;
	data->grid = generate_grid(input_file, data);
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->p_viewdir = 0;
	data->floor_height = 0;
	data->ceiling_height = 100;
	data->view_plane_dist  = 10;
	data->start_pos = 0;
	data->valid_char = "01NESW";
	data->start_char = "NESW";
	if (!data->grid)
		return (printf("%sFile not found or empty map\n", RED), 1);
	set_grid_width(data);
	if (analyze_grid(data))
	  	return (1);
	print_grid(data); // remove
	return (0);
}
