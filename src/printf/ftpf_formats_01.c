/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_formats_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 21:55:23 by lfabbro           #+#    #+#             */
/*   Updated: 2017/12/12 14:19:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			form_precision(t_struct *st)
{
	st->flags.precision = 0;
	st->flags.pad = st->flags.pad & PAD_RIGHT;
	st->flags.padchar = ' ';
	++st->format;
	if (*st->format >= '0' && *st->format <= '9')
	{
		while (*st->format >= '0' && *st->format <= '9')
		{
			st->flags.precision = (st->flags.precision * 10) +
				(*st->format - '0');
			++st->format;
		}
		if (st->flags.precision == 0)
			st->flags.precision = -1;
	}
	else
		st->flags.precision = -10;
	parse_flags(st);
}

void			form_space(t_struct *st)
{
	st->flags.space = 1;
	++st->format;
	parse_flags(st);
}

void			form_sharp(t_struct *st)
{
	st->flags.sharp = 1;
	++st->format;
	parse_flags(st);
}
