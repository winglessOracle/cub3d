/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:40:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/14 14:37:23 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	toggle(int n)
{
	return (n == 0);
}

/***
 * @brief 'finds and converts the relative pixel in x and y plane of a texture. 
 * x and y are doubled between 0 and 1.
*/
int	pixel_from_texure(mlx_texture_t *texture, double y, double x)
{
	int	x_i;
	int	y_i;
	int	n_pixel;

	y_i = (int)(y * texture->height);
	x_i = (int)(x * texture->width);
	n_pixel = ((int *)(texture->pixels))[y_i * texture->width + x_i];
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
