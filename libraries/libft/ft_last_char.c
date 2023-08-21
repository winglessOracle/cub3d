/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_last_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:58:50 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/02/27 09:58:57 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_last_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == c)
		return (1);
	return (0);
}
