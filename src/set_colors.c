/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:29 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/08/22 16:16:07 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rgb(t_color *color)
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
		set_rgb(data->mlx_data->ceiling);
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
		set_rgb(data->mlx_data->floor);
	}
}
