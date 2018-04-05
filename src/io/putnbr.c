/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:22:07 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 16:59:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putptr(void *p)
{
	ft_putstr("0x");
	ft_puthexa((unsigned long)p);
}

void		ft_puthexa(unsigned long x)
{
	const char *hex = "0123456789abcdef";

	if (x >= 16)
	{
		ft_puthexa(x / 16);
		ft_puthexa(x % 16);
	}
	else
		ft_putchar(hex[x]);
}

void		ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				len;

	nb = n;
	len = 0;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		len += ft_putchar_fd(nb + '0', fd);
	return (len);
}
