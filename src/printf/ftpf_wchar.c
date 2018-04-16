/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 21:56:58 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 15:41:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				a_wchar(t_struct *st, va_list args)
{
	int			ret;

	ret = 0;
	st->stargs.wchar = (wchar_t)va_arg(args, wchar_t);
	st->flags.padchar = (st->flags.zero) ? '0' : ' ';
	padding_left(st, 1);
	if ((ret = handle_wchar(FD, st->stargs.wchar)) < 0)
		return ((st->pc = -1));
	st->pc += ret;
	padding_right(st, 1);
	return (0);
}
