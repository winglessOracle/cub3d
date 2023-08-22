/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 13:20:36 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 15:57:41 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_north_path(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "NO ./", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'N')
			start++;
		start += 3;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->north_texure = ft_substr(line, start, size);
	}
}

void	set_east_path(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "EA ./", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'E')
			start++;
		start += 3;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->east_texture = ft_substr(line, start, size);
	}
}

void	set_south_path(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "SO ./", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'S')
			start++;
		start += 3;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->south_texture = ft_substr(line, start, size);
	}
}

void	set_west_path(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "WE ./", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'W')
			start++;
		start += 3;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->west_texture = ft_substr(line, start, size);
	}
}

void	parse_file_paths(char *file, t_data *data)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_str_exit("parseing file", data, 9);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		set_north_path(line, data);
		set_east_path(line, data);
		set_south_path(line, data);
		set_west_path(line, data);
		set_ceiling_color(line, data);
		set_floor_color(line, data);
		free (line);
	}
	close(fd);
	print_file_data(data); // remove
}
