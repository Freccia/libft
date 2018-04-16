/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:18:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 15:40:41 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			a_char(t_struct *st, va_list args, int va)
{
	if (va)
	{
		if (st->lmod.h || st->lmod.hh || st->lmod.l || st->lmod.ll ||
				st->lmod.j || st->lmod.z)
			return ((st->pc = -1));
		else
			st->stargs.ch = (unsigned char)va_arg(args, int);
	}
	else
		st->stargs.ch = *st->format;
	st->flags.padchar = (st->flags.zero == 1) ? '0' : ' ';
	padding_left(st, 1);
	ft_putchar_fd(st->stargs.ch, FD);
	padding_right(st, 1);
	return (1);
}
