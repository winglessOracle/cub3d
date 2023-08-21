/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:25:10 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 18:52:59 by carlowessel   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libraries/MLX42/include/MLX42/MLX42.h"
#include "../libraries/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data
{
	mlx_t	*mlx;
	char	**grid;
	int		grid_width;
	int		grid_height;
	int		p_xpos;
	int		p_ypos;
	int		p_viewdir;
	int		floor_height;
	int		ceiling_height;	
	int		view_plane_dist;
}	t_data;

//init
int		init_data(char *input_file, t_data *data);

//utils
int		free_all_return(int ret, t_data * data);

//checks
int		check_params(int argc, char **argv);

//testing
void	print_grid(t_data *data);


#endif
