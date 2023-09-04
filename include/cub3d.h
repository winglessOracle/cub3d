/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:10 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/09/04 11:34:45 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct minimap
{
	int			scale;
	int			w_col;
	int			p_col;
	int			o_col;
	int			width;
	int			height;
	int			xpos;
	int			ypos;
	mlx_image_t	*mini_map;

}	t_minimap;

typedef struct s_color
{
	char			*color;
	int				red;
	int				green;
	int				blue;
	int				a;
	int				argb;
}	t_color;

typedef struct s_img_data
{
	char			**wall_texture_paths;
	mlx_texture_t	**wall_textures;
	mlx_image_t		*main_screen;
	mlx_image_t		*mini_map;
	t_color			*floor;
	t_color			*ceiling;
}	t_img_data;

typedef struct s_check_data
{
	int				start_pos;
	char			*valid_char;
	char			*start_char;
}	t_check_data;

typedef struct s_data
{
	t_check_data	*check_data;
	t_img_data		*img_data;
	t_minimap		*mm;
	mlx_t			*mlx;
	char			**grid;
	int				grid_width;
	int				grid_height;
	int				screen_width;
	int				screen_height;
	double			p_xpos;
	double			p_ypos;
	double			p_viewdir;
	int				floor_height;
	int				ceiling_height;	
	int				view_plane_dist;
	int				toggle_mm;
	double			move_increment;
	double			turn_increment;
}	t_data;

//init
void	malloc_structs(t_data *data);
void	init_data(char *input_file, t_data *data);

//utils
void	free_all(t_data *data);
int		free_exit(t_data *data, int n);
void	free_str_exit(char *str, t_data *data, int error);
void	flood_fill(int x, int y, char **grid, t_data *data);
int		pixel_from_texure(mlx_texture_t *texture, double x, double y);
void	toggle_mm(t_data *data);

//grid_functions
char	**generate_grid(char *input_file);
void	analyze_grid(t_data *data);
void	square_grid(t_data *data);

//set_paths / set_colors
void	parse_file_paths(char *file, t_data *data);
void	set_ceiling_color(char *line, t_data *data);
void	set_floor_color(char *line, t_data *data);
int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a);

//building
void	build_image(t_data *data);
void	build_minimap(t_data *data);

//movement
void	move_player(double rad, t_data *data);
void	turn_player(char c, t_data *data);

//hooks
void	set_hooks(t_data *data);

//checks
int		check_params(int argc, char **argv);
void	check_textures(t_data *data);

//raycasting
bool	is_wall(int x, int y, t_data *data);

//testing
void	test_print_grid(t_data *data);
void	test_print_data(t_data *data);
void	test_print_images(t_data *data);
void	test_print_movement(char *str, t_data *data);
void	test_get_pixel(double x_i, double y_i, t_data *data);

#endif

/*
mlx_load_png: 			load a png texture to the buffer
mlx_texture_to_image:	Converts a given texture to an image.
mlx_draw_texture: 		Draws the texture on an already existing image.
mlx_image_to_window: 	Draws a new instance of an image, 
						it will then share the same pixel buffer as the image.
*/
