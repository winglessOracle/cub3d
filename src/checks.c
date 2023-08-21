/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/21 14:54:04 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 15:51:59 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_params(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%sinvallid number of arguments. required: 1\n", RED);
		return (1);
	}
	if (ft_check_extention(argv[1], "cub"))
	{
		printf("%sinvallid extention. required: '.cub'\n", RED);
		return (1);
	}
	return (0);
}

