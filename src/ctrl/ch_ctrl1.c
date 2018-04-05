/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ctrl1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:37:02 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 15:37:04 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
