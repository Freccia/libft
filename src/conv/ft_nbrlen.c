/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:52:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 17:03:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_nbrlen_base(int nbr, int base)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		++len;
	}
	while (nbr)
	{
		nbr /= base;
		++len;
	}
	return (len);
}

int			ft_nbrlen(int nbr)
{
	return (ft_nbrlen_base(nbr, 10));
}
