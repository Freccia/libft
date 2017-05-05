/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:57:01 by lfabbro           #+#    #+#             */
/*   Updated: 2017/05/05 17:17:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Outputs the string s to the standard output.
**     Returns the number or printed chars.
*/

int			ft_putstr(char const *s)
{
	if (s)
		return (write(1, s, (int)ft_strlen(s)));
	return (0);
}
