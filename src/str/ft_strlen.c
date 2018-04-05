/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:23:14 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 15:49:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	if (s)
		while (s[len] != '\0')
			++len;
	return (len);
}