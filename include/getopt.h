/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:54:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 17:56:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_H
# define GETOPT_H

# include <libft.h>

# define BADCH '?'
# define BADARG ':'
# define EMSG ""
# define ERR0 "%s: %c: illegal option\n"
# define ERR1 "%s: %c: option requires an argument\n"

extern int		g_optind;
extern char		*g_optarg;
extern int		g_opterr;
extern int		g_optopt;

int				ft_getopt(int ac, char **av, const char *optstr);

#endif
