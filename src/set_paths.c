/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 13:20:36 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/12 20:19:19 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

// typedef struct {
// 	char	*prefix;
// 	int		direction;
// } t_texture;

// static	t_texture paths[] = {
// 	{"NO", NORTH},
// 	{"EA", EAST},
// 	{"SO", SOUTH},
// 	{"NO", WEST}
// };

// void	load_textures(char *line, t_data *data)
// {
// 	int	start;
// 	int	size;

// 	start = 0;
// 	size = 0;
// 	if (ft_strnstr(line, paths->prefix, ft_strlen(line)))
// 	{
// 		while (line[start] && line[start] != paths->prefix[0])
// 			start++;
// 		start += 3;
// 		while (line[start + size] && !ft_isspace(line[start + size]))
// 			size++;
// 		data->img_data->wall_texture_paths[paths->direction]
// 			= ft_substr(line, start, size);
// 		if (ft_check_extention(data->img_data->wall_texture_paths[paths->direction],
// 				"png"))
// 			free_str_exit("wrong file format for textures. expected '.png'",
// 				data, 7);
// 		data->img_data->wall_textures[paths->direction]
// 			= mlx_load_png(data->img_data->wall_texture_paths[paths->direction]);
// 		if (!data->img_data->wall_textures[paths->direction])
// 			free_str_exit("loading texture", data, 7);
// 		data->check_data->textures_loaded += 1;
// 	}
// }

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
		data->img_data->wall_texture_paths[NORTH]
			= ft_substr(line, start, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[NORTH],
				"png"))
			free_str_exit("wrong file format for textures. expected '.PNG'",
				data, 7);
		data->img_data->wall_textures[NORTH]
			= mlx_load_png(data->img_data->wall_texture_paths[NORTH]);
		if (!data->img_data->wall_textures[NORTH])
			free_str_exit("loading texture", data, 7);
		data->check_data->textures_loaded += 1;
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
		data->img_data->wall_texture_paths[EAST]
			= ft_substr(line, start, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[EAST],
				"png"))
			free_str_exit("wrong file format for textures. expected '.PNG'",
				data, 7);
		data->img_data->wall_textures[EAST]
			= mlx_load_png(data->img_data->wall_texture_paths[EAST]);
		if (!data->img_data->wall_textures[EAST])
			free_str_exit("loading texture", data, 7);
		data->check_data->textures_loaded += 1;
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
		data->img_data->wall_texture_paths[SOUTH]
			= ft_substr(line, start, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[SOUTH],
				"png"))
			free_str_exit("wrong file format for textures. expected '.PNG'",
				data, 7);
		data->img_data->wall_textures[SOUTH]
			= mlx_load_png(data->img_data->wall_texture_paths[SOUTH]);
		if (!data->img_data->wall_textures[SOUTH])
			free_str_exit("loading texture", data, 7);
		data->check_data->textures_loaded += 1;
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
		data->img_data->wall_texture_paths[WEST]
			= ft_substr(line, start, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[WEST],
				"png"))
			free_str_exit("wrong file format for textures. expected '.PNG'",
				data, 7);
		data->img_data->wall_textures[WEST]
			= mlx_load_png(data->img_data->wall_texture_paths[WEST]);
		if (!data->img_data->wall_textures[WEST])
			free_str_exit("loading texture", data, 7);
		data->check_data->textures_loaded += 1;
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
		free_str_exit("parseing file:\nopening file", data, 9);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// load_textures(line, data);
		load_north(line, data);
		load_east(line, data);
		load_south(line, data);
		load_west(line, data);
		set_ceiling_color(line, data);
		set_floor_color(line, data);
		free (line);
	}
	close(fd);
	check_input_data(data);
}
