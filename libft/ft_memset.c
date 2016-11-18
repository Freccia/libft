/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:11:22 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/18 02:17:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (len == 0)
		return (b);
	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr = (unsigned char)c;
		if (len)
			++ptr;
	}
	return (b);
}
