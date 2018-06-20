/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:02:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:02:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_getchar_fd(int fd)
{
	char	c;

	if (1 != read(fd, &c, 1))
		return (-1);
	return ((int)c);
}

int		ft_getchar(void)
{
	return (ft_getchar_fd(0));
}

int		ft_getnbr(const char *str)
{
	int		ret;

	ret = 0;
	if (str)
	{
		if (*str == '-')
			return (-ft_getnbr(&str[1]));
		while (*str >= '0' && *str <= '9')
		{
			ret = ret * 10 + (*str - '0');
			++str;
		}
	}
	return (ret);
}
