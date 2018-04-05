/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:57:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 17:00:48 by lfabbro          ###   ########.fr       */
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

int			ft_getnbr(const char *str)
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
