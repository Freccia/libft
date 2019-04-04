/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:00:27 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:00:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isnbr(char *str)
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

int 	ft_ishex(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'a' && str[i] <= 'f')
			&& !(str[i] >= 'A' && str[i] <= 'F'))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}