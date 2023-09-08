/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:40:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/08 10:21:26 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	toggle_mm(t_data *data)
{
	if (data->toggle_mm == 1)
		data->toggle_mm = 0;
	else
		data->toggle_mm = 1;
	build_image(data);
}

unsigned int	convert_to_rgba(int n)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	g;
	unsigned int	r;

	a = (n >> 24) & 0xFF;
	b = (n >> 16) & 0xFF;
	g = (n >> 8) & 0xFF;
	r = n & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

/***
 * @brief 'finds and converts the relative pixel in x and y plane of a texture. 
 * x and y are doubled between 0 and 1.
 * The output is in reverse foramt abgr and is converted to rgba
*/
int	pixel_from_texure(mlx_texture_t *texture, double y, double x)
{
	int	x_i;
	int	y_i;
	int	n_pixel;

	y_i = (int)(y * texture->height);
	x_i = (int)(x * texture->width);
	n_pixel = ((int *)(texture->pixels))[y_i * texture->width + x_i];
	// printf("\ntexture width = %d\ntexture height = %d\n", texture->width, texture->height);
	// printf("\npixel no we are looking at based on screen dimensions and factors:\nx: %d\ny: %d\n", x_i, y_i);
	// printf("\ninput factors:\nx: %f\ny: %f\n", x, y);
	printf("\nn_pixel color from texture: %06X", n_pixel); // remove
	n_pixel = convert_to_rgba(n_pixel);
	printf("\nn_pixel color converted: %06X", n_pixel); // remove
	return (n_pixel);
}

/***
 * creates c copy of the grid to check
 * for wall surounding with a recursive flod fill.
*/
void	flood_fill(int x, int y, char **grid, t_data *data)
{
	if (x < 0 || x > data->grid_width - 1 || y < 0 || y > data->grid_height - 1)
	{
		ft_free_array(grid);
		free_str_exit("map not enclosed by walls", data, 8);
	}
	if (grid[y][x] == '1')
		return ;
	if (grid[y][x] != 'f')
	{
		grid[y][x] = 'f';
		flood_fill(x + 1, y, grid, data);
		flood_fill(x - 1, y, grid, data);
		flood_fill(x, y + 1, grid, data);
		flood_fill(x, y - 1, grid, data);
	}
}
