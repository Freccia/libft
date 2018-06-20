/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:00:20 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:00:22 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/stat.h>

int			ft_isexec(char *path)
{
	struct stat	buf;

	ft_bzero(&buf, sizeof(struct stat));
	lstat(path, &buf);
	if (S_ISREG(buf.st_mode) && (S_IXUSR & buf.st_mode))
		return (1);
	return (0);
}

int			ft_issticky(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
		return (0);
	if ((buf.st_mode & S_ISUID) || (buf.st_mode & S_ISGID))
		return (1);
	return (0);
}
