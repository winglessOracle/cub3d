/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 10:53:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/02/26 21:45:03 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
