/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_extention.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 12:30:39 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/08/21 14:58:54 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_extention(const char *file, const char *extention)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
		i++;
	while (extention[j])
		j++;
	while (j > -1)
	{
		if (file[i--] != extention[j--])
			return (1);
	}
	return (0);
}
