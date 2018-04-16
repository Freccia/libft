/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:44:39 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 15:42:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print(t_struct *st, va_list args, int ret)
{
	while (*st->format)
	{
		if (*st->format == '%')
		{
			++st->format;
			reset_lmod(st);
			if (*st->format == '\0')
				break ;
			parse_flags(st);
			if (parse_lenght_modifier(st))
				++st->format;
			ret = parse_args(st, args);
			if (ret)
			{
				++st->pc;
				ret = 0;
			}
		}
		else
			st->pc += ft_putchar_fd(*st->format, FD);
		reset_flags(st);
		++st->format;
	}
}

int				ft_vdprintf(int fd, const char *format, va_list args)
{
	t_struct	*st;
	int			pc;

	if ((st = malloc(sizeof(t_struct))) == NULL)
	return (0);
	FD = fd;
	set_init_st(st, format);
	ft_print(st, args, 0);
	pc = st->pc;
	free(st);
	return (pc);
}

int				ft_printfd(int fd, const char *format, ...)
{
	va_list		args;
	t_struct	*st;
	int			pc;

	if ((st = malloc(sizeof(t_struct))) == NULL)
		return (0);
	FD = fd;
	va_start(args, format);
	set_init_st(st, format);
	ft_print(st, args, 0);
	va_end(args);
	pc = st->pc;
	free(st);
	return (pc);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	*st;
	int			pc;

	if ((st = malloc(sizeof(t_struct))) == NULL)
		return (0);
	FD = 1;
	va_start(args, format);
	set_init_st(st, format);
	ft_print(st, args, 0);
	va_end(args);
	pc = st->pc;
	free(st);
	return (pc);
}
