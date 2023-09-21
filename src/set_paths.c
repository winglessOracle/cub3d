/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 13:20:36 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/21 15:29:09 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_load(t_texture *paths, int i, t_data *data, char *line)
{
	if (ft_check_extention(data->img_data->wall_texture_paths[paths[i].dir],
			"png"))
	{
		free(line);
		free_str_exit("wrong format. expected '.png'", data, 7);
	}
	if (data->img_data->wall_textures[paths[i].dir] == NULL)
	{
		data->img_data->wall_textures[paths[i].dir]
			= mlx_load_png(data->img_data->wall_texture_paths[paths[i].dir]);
		if (!data->img_data->wall_textures[paths[i].dir])
		{
			free(line);
			free_str_exit("loading texture", data, 6);
		}
		data->check_data->textures_loaded += 1;
	}
}

void	validate_check_and_load(char *ident, int i, char *line, t_data *data)
{
	char				*end;
	static t_texture	paths[] = {{"NO", NORTH}, {"EA", EAST},
	{"SO", SOUTH}, {"WE", WEST}};

	while (*ident && *ident != '/')
		ident++;
	if (*ident == '/')
	{
		end = ++ident;
		while (*end && !ft_isspace(*end))
			end++;
		if (data->img_data->wall_texture_paths[paths[i].dir] == NULL)
		{
			data->img_data->wall_texture_paths[paths[i].dir]
				= ft_substr(ident, 0, end - ident);
			check_and_load(paths, i, data, line);
		}
		else
		{
			free(line);
			free_str_exit("duplicate wall textures found", data, 7);
		}
	}
}

void	load_textures(char *line, t_data *data)
{
	char				*ident;
	int					i;
	static t_texture	paths[] = {{"NO", NORTH}, {"EA", EAST},
	{"SO", SOUTH}, {"WE", WEST}};

	i = 0;
	while (i < 4)
	{
		ident = ft_strnstr(line, paths[i].prefix, ft_strlen(line));
		if (ident)
			validate_check_and_load(ident, i, line, data);
		i++;
	}
}

/***
 * @brief checks every line of he input file
 * to see if it contains a path to one of the required wall textures and 
 * then saves the path and loads the texture.
*/
void	parse_file_paths(char *file, t_data *data)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_str_exit("parseing file:\nopening file", data, 5);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		load_textures(line, data);
		set_color(line, "C ", data->img_data->ceiling, data);
		set_color(line, "F ", data->img_data->floor, data);
		free(line);
	}
	close(fd);
	check_input_data(data);
}
