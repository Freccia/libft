/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:54:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/15 18:56:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_H
# define GETOPT_H

# include <libft.h>

extern int		g_optind;
extern char		*g_optarg;
extern int		g_opterr;
extern int		g_optopt;

int				ft_getopt(int ac, char **av, const char *optstr);

#endif
