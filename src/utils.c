/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:40:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/28 18:45:13 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pixel_from_texure(mlx_texture_t *texture, double x, double y)
{
	int	x_i;
	int	y_i;
	int	n_pixel;

	x_i = (int)(x * texture->width);
	y_i = (int)(y * texture->height);
	n_pixel = ((int *)(texture->pixels))[y_i * texture->width + x_i];

	// switch first two to back via bitwise operations. first > 24 (save) then original < 8, then add 
	printf("xi: %d\n", x_i);	//remove
	printf("yi: %d\n", y_i);	//remove
	printf("magic number: %x\n", n_pixel); 													//remove
	
	return (n_pixel);
}
//older prints
	//printf("magic number: %x\n", ((int *)(texture->pixels))[y_i * texture->width + x_i]);		//remove
	// printf("magic number 0: %u\n", (unsigned int)(n_pixel));
	// unsigned int colornr = (unsigned int)(n_pixel);
	// printf("magic number unsigned: %u\n", colornr);		//remove
	// printf("magic number first byte: %u\n", colornr < 24); 
	// printf("magic number: %d\n", ((int *)(texture->pixels))[y_i * texture->width + x_i]);	//remove

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

int	check_params(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n%sinvallid number of arguments. required: 1\n", RED);
		return (1);
	}
	if (ft_check_extention(argv[1], "cub"))
	{
		printf("\n%sinvallid extention. required: '.cub'\n", RED);
		return (1);
	}
	return (0);
}
