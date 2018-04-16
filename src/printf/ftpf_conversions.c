/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:15:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 15:44:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conversion_di(t_struct *st, va_list args)
{
	if (st->lmod.j)
	{
		st->stargs.nbr = (long long)va_arg(args, long long);
	}
	else if (st->lmod.ll)
	{
		st->stargs.nbr = (long long)va_arg(args, long long);
	}
	else if (st->lmod.l || st->lmod.z)
	{
		st->stargs.nbr = (long)va_arg(args, long);
	}
	else if (st->lmod.hh)
	{
		st->stargs.nbr = (signed char)va_arg(args, int);
	}
	else if (st->lmod.h)
	{
		st->stargs.nbr = (short)va_arg(args, int);
	}
	else
	{
		st->stargs.nbr = (int)va_arg(args, int);
	}
	return (0);
}

int				conversion_oux(t_struct *st, va_list args)
{
	if (st->lmod.j)
	{
		st->stargs.u_nbr = (long long)va_arg(args, long long);
	}
	else if (st->lmod.ll || st->lmod.z)
	{
		st->stargs.u_nbr = (unsigned long long)va_arg(args,
				unsigned long long);
	}
	else if (st->lmod.l)
	{
		st->stargs.u_nbr = (unsigned long)va_arg(args,
				unsigned long);
	}
	else if (st->lmod.hh)
	{
		st->stargs.u_nbr = (unsigned char)va_arg(args, int);
	}
	else if (st->lmod.h)
	{
		st->stargs.u_nbr = (unsigned short)va_arg(args, int);
	}
	else
		st->stargs.u_nbr = (unsigned int)va_arg(args, unsigned int);
	return (0);
}
