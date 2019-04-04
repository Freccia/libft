/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:19:00 by lfabbro           #+#    #+#             */
/*   Updated: 2019/04/04 15:20:00 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gets the substraction used to get the right number from the char
*/

static unsigned long	ft_atoul_hex_get_sub(char c)
{
	if (c >= 'A' && c <= 'F')
		return ('A' - 10);
	else if (c > 'a' && c <= 'f')
		return ('a' - 10);
	return('0');
}

unsigned long			ft_atoul_hex(const char *str)
{
	unsigned long		n;
	unsigned long		i;
	//unsigned long		sign;
	unsigned long		sub;

	n = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		++i;
	//sign = (str[i] == '-') ? -1 : 1;
	//if (str[i] == '+' || str[i] == '-')
	//	++i;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] == 'a' && str[i] <= 'f'))
	{
		sub = ft_atoul_hex_get_sub(str[i]);
		n = n * 16 + (str[i] - sub) % 16;
		++i;
	}
	//return (n * sign);
	return (n);
}
