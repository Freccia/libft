/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:21:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 16:59:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_putstr(char const *s)
{
	if (s)
		return (write(1, s, (int)ft_strlen(s)));
	return (0);
}

int		ft_putstr_fd(char const *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		return (len);
	}
	return (0);
}

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}

int		ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	if (s)
	{
		len += ft_putstr_fd(s, fd);
		len += ft_putchar_fd('\n', fd);
	}
	return (len);
}

void			ft_puttab(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			ft_putendl(tab[i]);
			++i;
		}
	}
}
