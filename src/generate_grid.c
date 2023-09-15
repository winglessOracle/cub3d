/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:33:39 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/15 11:24:56 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			data->grid[y] = ft_strjoin_free(data->grid[y], " ");
			delta--;
		}
		y++;
	}
}

int	find_grid(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

char	*grid_helper(int fd)
{
	char	*line;
	char	*joined_lines;
	int		start_grid;

	start_grid = 0;
	line = get_next_line(fd);
	joined_lines = NULL;
	while (line)
	{
		if (find_grid(line) == 0 && start_grid == 1)
			break ;
		start_grid = find_grid(line);
		if (start_grid == 1)
		{
			if (joined_lines == NULL)
				joined_lines = ft_strdup(line);
			else
				joined_lines = ft_strjoin_free(joined_lines, line);
		}
		line = get_next_line(fd);
	}
	close (fd);
	if (start_grid == 0 || joined_lines[0] == '\0' || joined_lines[0] == '\n')
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
	{
		printf("ERROR: opening input file");
		return (NULL);
	}
	joined_lines = grid_helper(fd);
	if (joined_lines == NULL)
		return (NULL);
	ret = ft_split(joined_lines, '\n');
	free(joined_lines);
	return (ret);
}
