/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:57:11 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/02/27 10:00:16 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pop(char **arr, int index)
{
	int	i;

	i = index;
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = NULL;
}
