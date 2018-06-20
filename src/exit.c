/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:01:49 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:01:50 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

int		ft_exit(int ecode, char const *fmt, ...)
{
	va_list ap;

	if (fmt)
	{
		va_start(ap, fmt);
		ft_vdprintf(STDERR_FILENO, fmt, ap);
		va_end(ap);
	}
	exit(ecode);
}
