/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/15 11:01:01 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "config.h"

void	malloc_structs(t_data *data)
{
	data->check_data = malloc(sizeof(t_check_data));
	if (!data->check_data)
		free_str_exit("allocating structs", data, 3);
	data->img_data = malloc(sizeof(t_img_data));
	if (!data->img_data)
		free_str_exit("allocating structs", data, 3);
	data->img_data->ceiling = malloc(sizeof(t_color));
	if (!data->img_data->ceiling)
		free_str_exit("allocating structs", data, 3);
	data->img_data->floor = malloc(sizeof(t_color));
	if (!data->img_data->floor)
		free_str_exit("allocating structs", data, 3);
	data->img_data->wall_texture_paths = ft_calloc(5, sizeof(char *));
	if (!data->img_data->wall_texture_paths)
		free_str_exit("allocating structs", data, 3);
	data->img_data->wall_textures = ft_calloc(5, sizeof(mlx_texture_t *));
	if (!data->img_data->wall_textures)
		free_str_exit("allocating structs", data, 3);
	data->mm = malloc(sizeof(t_minimap));
	if (!data->mm)
		free_str_exit("allocating structs", data, 3);
}

void	init_img_data(t_data *data)
{
	data->mlx
		= mlx_init(data->screen_width, data->screen_height, "cub3d", false);
	if (!data->mlx)
		free_str_exit("initializing MLX", data, 4);
	mlx_set_window_pos(data->mlx, WINDOW_X_POS, WINDOW_Y_POS);
	data->img_data->ceiling->red = 0;
	data->img_data->ceiling->green = 0;
	data->img_data->ceiling->blue = 255;
	data->img_data->ceiling->a = 255;
	data->img_data->ceiling->rgba = 0;
	data->img_data->floor->red = 0;
	data->img_data->floor->green = 255;
	data->img_data->floor->blue = 0;
	data->img_data->floor->a = 255;
	data->img_data->floor->rgba = 0;
}

void	init_check_data(t_data *data)
{
	data->check_data->start_pos = 0;
	data->check_data->valid_char = "01NESW ";
	data->check_data->start_char = "NESW";
	data->check_data->textures_loaded = 0;
	data->check_data->colors_loaded = 0;
}

void	init_main_data(t_data *data)
{
	data->screen_width = SCREEN_WIDTH;
	data->screen_height = SCREEN_HEIGHT;
	data->move_increment = MOVE_INCREMENT;
	data->last_pixelate = 0;
	data->update_rate = UPDATE_RATE;
	data->turn_increment = TURN_INCREMENT;
	data->mouse_sensitivity = MOUSE_SENSITIVITY;
	data->grid_width = 0;
	data->grid_height = 0;
	data->p_xpos = 0;
	data->p_ypos = 0;
	data->mouse_xpos = data->screen_width / 2;
	data->mouse_ypos = data->screen_height / 2;
	data->p_viewdir = 0;
	data->previous_mouse_x = 0;
	data->toggle_mouse = 1;
}

/* set scale and rgb colors for minimap below.
RGBA with A for transparancy
Scale is the division of the screen size*/
void	init_minimap(t_data *data)
{
	data->mm->toggle_mm = 1;
	data->mm->scale = 4;
	data->mm->w_col = get_rgba(0, 0, 0, 255);
	data->mm->p_col = get_rgba(150, 150, 250, 255);
	data->mm->o_col = get_rgba(0, 100, 100, 255);
	data->mm->width = data->screen_width / data->mm->scale;
	data->mm->height = data->screen_height / data->mm->scale;
	data->mm->xpos = data->screen_width - data->mm->width;
	data->mm->ypos = data->screen_height - data->mm->height;
	data->img_data->mini_map
		= mlx_new_image(data->mlx, data->mm->width, data->mm->height);
}
