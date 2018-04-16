/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:23:49 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 17:27:43 by lfabbro          ###   ########.fr       */
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
