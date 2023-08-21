
#ifndef CUB3D_H
# define CUB3D_H

#include "../libraries/MLX42/include/MLX42/MLX42.h"
#include "../libraries/libft/libft.h"

#include <stdlib.h>


typedef struct s_global
{
	mlx_t			*mlx;
	mlx_image_t		*screen_img;
	int				grid_width;
	int				grid_height;
	
}	t_global;


#endif
