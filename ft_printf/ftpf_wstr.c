/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 21:57:04 by lfabbro           #+#    #+#             */
/*   Updated: 2017/12/12 14:22:12 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_putwstr_t(int fd, wchar_t *wstr, int len)
{
	int				i;
	int				ret;
	int				pc;

	i = 0;
	ret = 0;
	pc = 0;
	while (wstr[i] && ret < len)
	{
		if ((int)(ret + ft_wchar_size(wstr[i])) > len)
			break ;
		if ((pc = handle_wchar(fd, wstr[i])) < 0)
			return (-1);
		ret += pc;
		++i;
	}
	return (ret);
}

int					a_wstr(t_struct *st)
{
	int		pc;
	int		len;

	pc = 0;
	st->stargs.wstr = (wchar_t*)va_arg(st->args, wchar_t *);
	st->stargs.wstr = (st->stargs.wstr) ? st->stargs.wstr : L"(null)";
	len = wstr_lenght(st);
	st->flags.padchar = (st->flags.zero) ? '0' : ' ';
	padding_left(st, len);
	if ((pc = ft_putwstr_t(FD, st->stargs.wstr, len)) < 0)
		return ((st->pc = -1));
	padding_right(st, len);
	st->pc += pc;
	return (0);
}
