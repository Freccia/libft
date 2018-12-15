/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:14:38 by lfabbro           #+#    #+#             */
/*   Updated: 2018/12/15 11:53:53 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** DESCRIPTION:
**     Allocates (with malloc(3)) and returns a “fresh” string ending
**     with ’\0’, result of the concatenation of s1 and s2. If
**     the allocation fails the function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	ls1 = (s1) ? ft_strlen(s1) : 0;
	ls2 = (s2) ? ft_strlen(s2) : 0;
	if (!s1 && s2)
	{
		str = ft_strnew(ls2 + 1);
		return (str ? ft_strcpy(str, s2) : NULL);
	}
	if (!s2 && s1)
	{
		str = ft_strnew(ls1 + 1);
		return (str ? ft_strcpy(str, s1) : NULL);
	}
	if (s1 && s2)
	{
		str = ft_strnew(ls1 + ls2 + 1);
		return (str ? ft_strcat(ft_strcpy(str, s1), s2) : NULL);
	}
	return (NULL);
}
