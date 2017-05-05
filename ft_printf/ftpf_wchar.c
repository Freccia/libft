/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:26:29 by lfabbro           #+#    #+#             */
/*   Updated: 2017/05/05 17:02:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				a_wchar(t_struct *st)
{
	int			ret;

	ret = 0;
	st->stargs.wchar = (wchar_t)va_arg(st->args, wchar_t);
	st->flags.padchar = (st->flags.zero) ? '0' : ' ';
	padding_left(st, 1);
	if ((ret = handle_wchar(FD, st->stargs.wchar)) < 0)
		return ((st->pc = -1));
	st->pc += ret;
	padding_right(st, 1);
	return (0);
}
