/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 21:56:51 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 15:50:36 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_width(int width, int lenght, int precision)
{
	if ((precision - lenght) > 0)
		width -= (precision - lenght);
	return (width);
}

static int		precision_uint(t_struct *st, int lenght)
{
	int			pcp;

	pcp = st->flags.precision;
	if (pcp > 0)
		while (pcp > 0 && pcp-- > lenght)
			st->pc += ft_putchar_fd('0', FD);
	else if (st->flags.precision < 0 && st->stargs.u_nbr == 0)
		return (-1);
	return (1);
}

static int		left_uint(t_struct *st)
{
	int			lenght;

	lenght = unbr_lenght(st->stargs.u_nbr, 10);
	st->flags.width = get_width(st->flags.width, lenght, st->flags.precision);
	st->flags.padchar = (st->flags.pad & PAD_ZERO) ? '0' : ' ';
	padding_left(st, lenght);
	return (lenght);
}

static int		right_uint(t_struct *st, int lenght)
{
	padding_right(st, lenght);
	return (1);
}

int				a_uint(t_struct *st, va_list args)
{
	int		lenght;
	char	*unbr;

	lenght = 0;
	if (*st->format == 'U')
		st->lmod.l = 1;
	conversion_oux(st, args);
	lenght = left_uint(st);
	if (precision_uint(st, lenght) < 0)
		return (0);
	unbr = ft_ulltoa_base(st->stargs.u_nbr, 10, 'a');
	st->pc += ft_putstr_fd(unbr, FD);
	right_uint(st, lenght);
	free(unbr);
	return (1);
}
