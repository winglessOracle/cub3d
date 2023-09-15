/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:29 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/15 09:59:06 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	check_rgb_value(t_color *color, t_data *data)
{
	if (color->red < 0 || color->red > 255
		|| color->green < 0 || color->green > 255
		|| color->blue < 0 || color->blue > 255)
		free_str_exit("non valid RGB color passed", data, 7);
}

void	set_rgb(char *color_char, t_color *color, t_data *data)
{
	int		i;
	int		start;
	char	temp[4];
	int		counter;

	i = 0;
	counter = 0;
	while (counter < 3)
	{
		while (!ft_isdigit(color_char[i]))
			i++;
		start = i;
		while (color_char[i] && ft_isdigit(color_char[i]))
			i++;
		ft_strlcpy(temp, color_char + start, i++ - start + 1);
		if (counter == 0)
			color->red = ft_atoi(temp);
		else if (counter == 1)
			color->green = ft_atoi(temp);
		else if (counter == 2)
			color->blue = ft_atoi(temp);
		counter++;
	}
	check_rgb_value(color, data);
	color->rgba = get_rgba(color->red, color->green, color->blue, color->a);
}

void	set_color(char *line, char *identifier, t_color *col, t_data *data)
{
	int		size;
	char	*ident;
	char	*color;

	size = 0;
	ident = ft_strnstr(line, identifier, ft_strlen(line));
	if (ident)
	{
		ident += 2;
		while (ident[size] && !ft_isspace(ident[size]))
			size++;
		color = ft_substr(ident, 0, size);
		set_rgb(color, col, data);
		col->rgba = get_rgba(col->red, col->green, col->blue, col->a);
		data->check_data->colors_loaded += 1;
		free (color);
	}
}
