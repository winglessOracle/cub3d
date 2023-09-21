/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlowesseling <carlowesseling@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:29 by carlowessel   #+#    #+#                 */
/*   Updated: 2023/09/21 16:26:36 by cherrewi      ########   odam.nl         */
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

void	check_color_str(char *line, char *color, t_data *data)
{
	int		count_commas;
	int		i;
	bool	string_valid;

	i = 0;
	count_commas = 0;
	string_valid = true;
	while (color[i] != '\n' && color[i] != '\0' && !ft_isspace(color[i]))
	{
		if (color[i] == ',' && ft_isdigit(color[i + 1]))
			count_commas++;
		else
		{
			if (!ft_isdigit(color[i]))
				string_valid = false;
		}
		i++;
	}
	if (count_commas != 2 || string_valid == false)
	{
		free(line);
		free_str_exit("invalid color", data, 8);
	}
}

void	set_color(char *line, char *identifier, t_color *col, t_data *data)
{
	int		size;
	char	*color_str;
	bool	*loaded;

	if (*identifier == 'C')
		loaded = &(data->check_data->ceiling_loaded);
	if (*identifier == 'F')
		loaded = &(data->check_data->floor_loaded);
	size = 0;
	color_str = ft_strnstr(line, identifier, ft_strlen(line));
	if (color_str)
	{
		if (*loaded)
			free_str_exit("duplicate color entry found", data, 8);
		color_str++;
		while (ft_isspace(*color_str))
			color_str++;
		while (color_str[size] && !ft_isspace(color_str[size]))
			size++;
		check_color_str(line, color_str, data);
		set_rgb(color_str, col, data);
		col->rgba = get_rgba(col->red, col->green, col->blue, col->a);
		*loaded = 1;
	}
}
