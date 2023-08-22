/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:10 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/22 15:53:49 by carlowessel   ########   odam.nl         */
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
}	t_color;

typedef struct s_mlx_data
{
	mlx_t	*mlx;
	char	*north_texure;
	char	*east_texture;
	char	*south_texture;
	char	*west_texture;
	t_color	*floor;
	t_color	*ceiling;
}	t_mlx_data;

typedef struct s_check_data
{
	int		start_pos;
	char	*valid_char;
	char	*start_char;
}	t_check_data;

typedef struct s_data
{
	t_check_data	*check_data;
	t_mlx_data		*mlx_data;
	char			**grid;
	int				grid_width;
	int				grid_height;
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
int		free_exit(t_data *data);
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

//testing
void	print_grid(t_data *data);
void	print_file_data(t_data *data);

#endif
