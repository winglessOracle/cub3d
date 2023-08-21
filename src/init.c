/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 18:56:08 by carlowessel   ########   odam.nl         */
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

int	init_data(char *input_file, t_data *data)
{
	data->mlx 	= mlx_init(1200, 800, "cub3d", false);
	if (!data->mlx)
		return (1);
	mlx_set_window_pos(data->mlx, 100, 800);
	data->grid_width = 0;
	data->grid_height = 0;
	data->grid = generate_grid(input_file, data);
	if (!data->grid)
	{
		printf("%sFile not found of empty map\n", RED);
		return (1);
	}
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->p_viewdir = 0;
	data->floor_height = 0;
	data->ceiling_height = 0;
	data->view_plane_dist  = 0;
	print_grid(data); // remove
	return (0);
}
