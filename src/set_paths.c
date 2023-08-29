/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 13:20:36 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/29 14:09:09 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_north(char *line, t_data *data)
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
		data->img_data->wall_texture_paths[0] = ft_substr(line, start, size);
		data->img_data->wall_textures[0]
			= mlx_load_png(data->img_data->wall_texture_paths[0]);
		if (!data->img_data->wall_textures[0])
			free_str_exit("loading texture", data, 7);
	}
}

void	load_east(char *line, t_data *data)
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
		data->img_data->wall_texture_paths[1] = ft_substr(line, start, size);
		data->img_data->wall_textures[1]
			= mlx_load_png(data->img_data->wall_texture_paths[1]);
		if (!data->img_data->wall_textures[1])
			free_str_exit("loading texture", data, 7);
	}
}

void	load_south(char *line, t_data *data)
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
		data->img_data->wall_texture_paths[2] = ft_substr(line, start, size);
		data->img_data->wall_textures[2]
			= mlx_load_png(data->img_data->wall_texture_paths[2]);
		if (!data->img_data->wall_textures[2])
			free_str_exit("loading texture", data, 7);
	}
}

void	load_west(char *line, t_data *data)
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
		data->img_data->wall_texture_paths[3] = ft_substr(line, start, size);
		data->img_data->wall_textures[3]
			= mlx_load_png(data->img_data->wall_texture_paths[3]);
		if (!data->img_data->wall_textures[3])
			free_str_exit("loading texture", data, 7);
	}
}


void	parse_file_paths(char *file, t_data *data)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_str_exit("parseing file:\nopening file", data, 9);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		load_north(line, data);
		load_east(line, data);
		load_south(line, data);
		load_west(line, data);
		set_ceiling_color(line, data);
		set_floor_color(line, data);
		free (line);
	}
	close(fd);
	test_print_data(data); // remove
}
