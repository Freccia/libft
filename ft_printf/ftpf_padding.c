/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 21:56:13 by lfabbro           #+#    #+#             */
/*   Updated: 2017/12/12 14:20:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		padding_left(t_struct *st, int limit)
{
	if (!(st->flags.pad & PAD_RIGHT))
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar_fd(st->flags.padchar, FD);
}

void		padding_right(t_struct *st, int limit)
{
	if (st->flags.pad & PAD_RIGHT)
		while (st->flags.width >= 0 && st->flags.width-- > limit)
			st->pc += ft_putchar_fd(st->flags.padchar, FD);
}
