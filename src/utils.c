/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:40:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 15:51:34 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all_return(int ret, t_data * data)
{
	free (data);
	return (ret);
}