/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:37:24 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 15:37:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_isnbr(char *str)
{
	int	is_nbr;

	is_nbr = 0;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
					*str == '\r' || *str == '\f' || *str == '\v'))
			++str;
		if (*str && (*str == '+' || *str == '-'))
			++str;
		if (*str >= '0' && *str <= '9')
			is_nbr = 1;
	}
	return (is_nbr);
}