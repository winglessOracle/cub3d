/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:33:39 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/24 17:27:25 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	find_start_grid(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (true);
	return (false);
}

void	square_grid(t_data *data)
{
	int		delta;
	int		y;

	y = 0;
	delta = 0;
	while (y < data->grid_height)
	{
		delta = data->grid_width - ft_strlen(data->grid[y]);
		while (delta != 0)
		{
			data->grid[y] = ft_strjoin_free(data->grid[y], "x");
			delta--;
		}
		y++;
	}
}

char	*grid_helper(int fd)
{
	char	*line;
	char	*joined_lines;
	bool	start_grid;

	line = "";
	joined_lines = ft_strdup("");
	start_grid = false;
	while (line)
	{
		line = get_next_line(fd);
		if (!start_grid)
			start_grid = find_start_grid(line);
		if (start_grid)
		{
			if (line == NULL || line[0] == '\n')
				break ;
			joined_lines = ft_strjoin_free(joined_lines, line);
		}
	}
	close (fd);
	if (joined_lines[0] == '\0' || joined_lines[0] == '\n')
		return (free(joined_lines), NULL);
	return (joined_lines);
}

char	**generate_grid(char *input_file)
{
	int		fd;
	char	*joined_lines;
	char	**ret;

	fd = open(input_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	joined_lines = grid_helper(fd);
	ret = ft_split(joined_lines, '\n');
	free(joined_lines);
	return (ret);
}
