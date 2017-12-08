/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:53:35 by lfabbro           #+#    #+#             */
/*   Updated: 2017/12/08 21:00:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
