/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isinteger.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 23:05:10 by carlo         #+#    #+#                 */
/*   Updated: 2023/03/07 23:06:53 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_integer(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}
