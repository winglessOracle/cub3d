/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bounce_point.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/04 10:41:59 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/09/04 15:06:07 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(int x, int y, t_data *data)
{
	if (x < 0 || y < 0)
		return (false);
	if (x >= data->grid_width || y >= data->grid_height)
		return (false);
	if (data->grid[y][x] == '1')
		return (true);
	else
		return (false);
}

t_bounce *get_horizontal_bounce(t_data *data, double viewdir)
{
	t_bounce	*bounce;
	double		hor_growth;
	double		vert_growth;
	double		temp_f;

	bounce = malloc(sizeof(t_bounce));
	if (bounce == NULL)
		return (NULL);

	hor_growth = cos(viewdir);
	vert_growth = sin(viewdir);

	if (hor_growth > -0.001 && hor_growth < 0.001)
	{
		puts("no horizontal growth");
		return (NULL);  // no horizontal bounce, because view is vertically
	}
	
	bounce->y = (int)(data->p_ypos) - 1;  // assumption: looking up
	while (bounce->y >= 0 && bounce->y < data->grid_height)
	{
		printf("loop\n");
		// assumption: looking up
		bounce->bounce_position = modf(data->p_xpos, &temp_f) + tan(viewdir) * (data->p_ypos - (bounce->y + 1)); // assumption: looking up
		printf("modf(data->p_xpos, &temp_f): %lf\n", modf(data->p_xpos, &temp_f)); // 0.3
		printf("temp_f: %lf\n", temp_f);					// 1.0000
		printf("tan(viewdir): %lf\n", tan(viewdir));		// 1
		printf("data->p_ypos: %lf\n", data->p_ypos);		// 1.2
		printf("bounce->y: %d\n", bounce->y);				// 0

		bounce->x =(int)temp_f;
		if (is_wall(bounce->x, bounce->y, data))
		{
			bounce->distance = (data->p_ypos - (bounce->y + 1)) / cos(viewdir); // assumption: looking up
			break;
		}
		bounce->y -= 1;  // assumption: looking up
	}
	return (bounce);
}
