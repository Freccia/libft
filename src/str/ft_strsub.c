/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:01:10 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 15:49:41 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trun;
	size_t	i;

	i = 0;
	if (s && len)
	{
		if ((trun = ft_strnew(len)) == NULL)
			return (NULL);
		while (i < len)
		{
			trun[i] = s[start + i];
			++i;
		}
		return (trun);
	}
	return (NULL);
}
