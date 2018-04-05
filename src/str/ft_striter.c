/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:06:10 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 15:49:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** DESCRIPTION:
**     Applies the function f to each character of the string passed
**     as argument. Each character is passed by address to f to be
**     modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		if (*s)
		{
			while (*s)
			{
				f(s);
				++s;
			}
		}
	}
}
