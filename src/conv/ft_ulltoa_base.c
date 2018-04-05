/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:34:51 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 17:11:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ulltoa_get_size(long long value, int base)
{
	int			size;

	size = 0;
	while (value)
	{
		value /= base;
		++size;
	}
	return (size);
}

static char		*ulltoa_return_zero(void)
{
	char		*num;

	if ((num = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char		*ulltoa_base_return(long long value, int base, char set)
{
	int			size;
	char		*num;

	size = ulltoa_get_size(value, base);
	if ((num = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	num[size] = '\0';
	while (value)
	{
		if (value % base < 10)
			num[--size] = "0123456789"[value % base];
		else
			num[--size] = set + ((value % base) - 10);
		value /= base;
	}
	return (num);
}

char			*ft_ulltoa_base(long long value, int base, char set)
{
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return (ulltoa_return_zero());
	return (ulltoa_base_return(value, base, set));
}
