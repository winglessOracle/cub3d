/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:29 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 16:36:05 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb_value(t_color *color, t_data *data)
{
	printf("here\n");
	if (color->red < 0 || color->red > 255 \
			|| color->green < 0 || color->green > 255 \
			|| color->blue < 0 || color->blue > 255)
		free_str_exit("non valid RGB color passed", data, 9);
}

void	set_rgb(t_color *color, t_data *data)
{
	int		i;
	int		start;
	char	temp[4];

	i = 0;
	start = 0;
	while (color->color[i] && color->color[i] != ',')
		i++;
	i++;
	ft_strlcpy(temp, color->color + start, i);
	color->red = ft_atoi(temp);
	start = i;
	while (color->color[i] && color->color[i] != ',')
		i++;
	i++;
	ft_strlcpy(temp, color->color + start, i);
	color->green = ft_atoi(temp);
	start = i;
	while (color->color[i] && color->color[i] != ',')
		i++;
	i++;
	ft_strlcpy(temp, color->color + start, i);
	color->blue = ft_atoi(temp);
	check_rgb_value(color, data);
}

void	set_ceiling_color(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "C ", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'C')
			start++;
		start += 2;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->ceiling->color = ft_substr(line, start, size);
		set_rgb(data->mlx_data->ceiling, data);
	}
}

void	set_floor_color(char *line, t_data *data)
{
	int	start;
	int	size;

	start = 0;
	size = 0;
	if (ft_strnstr(line, "F ", ft_strlen(line)))
	{
		while (line[start] && line[start] != 'F')
			start++;
		start += 2;
		while (line[start + size] && !ft_isspace(line[start + size]))
			size++;
		data->mlx_data->floor->color = ft_substr(line, start, size);
		set_rgb(data->mlx_data->floor, data);
	}
}
