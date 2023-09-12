/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 13:20:36 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/13 00:11:46 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// typedef struct s_texture{
// 	char	*prefix;
// 	int		dir;
// }	t_texture;

// void	load_textures(char *line, t_data *data)
// {
// 	int					size;
// 	char				*ident;
// 	int					i;
// 	static t_texture	paths[] =
// 		{{"NO", NORTH}, 
// 		{"EA", EAST},
// 		{"SO", SOUTH},
// 		{"WE", WEST}
// 	};

// 	i = 0;
// 	size = 0;
// 	while (i < 4)
// 	{
// 		ident = ft_strnstr(line, paths[i].prefix, ft_strlen(line));
// 		if (ident)
// 		{
// 			while (ident && *ident != '/')
// 				ident++;
// 			if (*ident == '/')
// 				ident++;
// 			while (ident[size] && !ft_isspace(ident[size]))
// 				size++;
// 			data->img_data->wall_texture_paths[paths[i].dir]
// 				= ft_substr(ident, 0, size);
// 			if (ft_check_extention(data->img_data->wall_texture_paths[paths[i].dir], "png"))
// 				free_str_exit("wrong format. expected '.png'", data, 7);
// 			data->img_data->wall_textures[paths[i].dir]= 
// 				mlx_load_png(data->img_data->wall_texture_paths[paths[i].dir]);
// 			if (!data->img_data->wall_textures[paths[i].dir])
// 				free_str_exit("loading texture", data, 6);
// 			data->check_data->textures_loaded += 1;
// 		}
// 		i++;
// 	}
// }

void	load_north(char *line, t_data *data)
{
	int		size;
	char	*ident;

	size = 0;
	ident = ft_strnstr(line, "NO", ft_strlen(line));
	if (ident)
	{
		while (ident && *ident != '/')
			ident++;
		if (*ident == '/')
			ident++;
		while (ident[size] && !ft_isspace(ident[size]))
			size++;
		data->img_data->wall_texture_paths[NORTH] = ft_substr(ident, 0, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[NORTH],"png"))
			free_str_exit("wrong file format. expected '.png'",	data, 7);
		data->img_data->wall_textures[NORTH]
			= mlx_load_png(data->img_data->wall_texture_paths[NORTH]);
		if (!data->img_data->wall_textures[NORTH])
			free_str_exit("loading texture", data, 6);
		data->check_data->textures_loaded += 1;
	}
}

void	load_east(char *line, t_data *data)
{
	int		size;
	char	*ident;

	size = 0;
	ident = ft_strnstr(line, "EA", ft_strlen(line));
	if (ident)
	{
		while (ident && *ident != '/')
			ident++;
		if (*ident == '/')
			ident++;
		while (ident[size] && !ft_isspace(ident[size]))
			size++;
		data->img_data->wall_texture_paths[EAST] = ft_substr(ident, 0, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[EAST], "png"))
			free_str_exit("wrong file format. expected '.png'",	data, 7);
		data->img_data->wall_textures[EAST]
			= mlx_load_png(data->img_data->wall_texture_paths[EAST]);
		if (!data->img_data->wall_textures[EAST])
			free_str_exit("loading texture", data, 6);
		data->check_data->textures_loaded += 1;
	}
}

void	load_south(char *line, t_data *data)
{
	int		size;
	char	*ident;

	size = 0;
	ident = ft_strnstr(line, "SO", ft_strlen(line));
	if (ident)
	{
		while (ident && *ident != '/')
			ident++;
		if (*ident == '/')
			ident++;
		while (ident[size] && !ft_isspace(ident[size]))
			size++;
		data->img_data->wall_texture_paths[SOUTH] = ft_substr(ident, 0, size);
		if (ft_check_extention
			(data->img_data->wall_texture_paths[SOUTH], "png"))
			free_str_exit("wrong file format. expected '.png'",	data, 7);
		data->img_data->wall_textures[SOUTH]
			= mlx_load_png(data->img_data->wall_texture_paths[SOUTH]);
		if (!data->img_data->wall_textures[SOUTH])
			free_str_exit("loading texture", data, 6);
		data->check_data->textures_loaded += 1;
	}
}

void	load_west(char *line, t_data *data)
{
	int		size;
	char	*ident;

	size = 0;
	ident = ft_strnstr(line, "WE", ft_strlen(line));
	if (ident)
	{
		while (ident && *ident != '/')
			ident++;
		if (*ident == '/')
			ident++;
		while (ident[size] && !ft_isspace(ident[size]))
			size++;
		data->img_data->wall_texture_paths[WEST] = ft_substr(ident, 0, size);
		if (ft_check_extention(data->img_data->wall_texture_paths[WEST], "png"))
			free_str_exit("wrong file format. expected '.png'",	data, 7);
		data->img_data->wall_textures[WEST]
			= mlx_load_png(data->img_data->wall_texture_paths[WEST]);
		if (!data->img_data->wall_textures[WEST])
			free_str_exit("loading texture", data, 6);
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
		free_str_exit("parseing file:\nopening file", data, 5);
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
		set_color(line, "C ", data->img_data->ceiling, data);
		set_color(line, "F ", data->img_data->floor, data);
		free (line);
	}
	close(fd);
	check_input_data(data);
}
