/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:10 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/23 15:24:44 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_color
{
	char	*color;
	int		red;
	int		green;
	int		blue;
	int		a;
	int		argb;
}	t_color;

typedef struct s_img_data
{
	char			**wall_texture_paths;
	mlx_texture_t	**wall_textures;
	mlx_image_t		*main_screen;
	t_color			*floor;
	t_color			*ceiling;
}	t_img_data;

typedef struct s_check_data
{
	int		start_pos;
	char	*valid_char;
	char	*start_char;
}	t_check_data;

typedef struct s_data
{
	t_check_data	*check_data;
	t_img_data		*img_data;
	mlx_t			*mlx;
	char			**grid;
	int				grid_width;
	int				grid_height;
	int				screen_width;
	int				screen_height;
	int				p_xpos;
	int				p_ypos;
	int				p_viewdir;
	int				floor_height;
	int				ceiling_height;	
	int				view_plane_dist;
}	t_data;

//init
void	malloc_structs(t_data *data);
void	init_data(char *input_file, t_data *data);

//utils
void	free_all(t_data *data);
int		free_exit(t_data *data, int n);
void	free_str_exit(char *str, t_data *data, int error);
void	flood_fill(int x, int y, char **grid, t_data *data);
int		check_params(int argc, char **argv);

//grid_functions
char	**generate_grid(char *input_file);
void	analyze_grid(t_data *data);

//set_paths / set_colors
void	parse_file_paths(char *file, t_data *data);
void	set_ceiling_color(char *line, t_data *data);
void	set_floor_color(char *line, t_data *data);

//building
void	build_images(t_data *data);

//movement
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);

//hooks
void	set_hooks(t_data *data);

//testing
void	print_grid(t_data *data);
void	print_file_data(t_data *data);
void	test_images(t_data *data);
void	test_print_move(char *str, t_data *data);

#endif

/*
mlx_load_png: 			load a png texture to the buffer
mlx_texture_to_image:	Converts a given texture to an image.
mlx_draw_texture: 		Draws the texture on an already existing image.
mlx_image_to_window: 	Draws a new instance of an image, 
						it will then share the same pixel buffer as the image.
*/