/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:03:35 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:30:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getopt.h"

char		*g_optarg = 0;
int			g_optind = 1;
int			g_optopt = 0;
int			g_opterr = 1;
static int	g_optreset = 0;
static char	*g_place = EMSG;

/*
** Option-argument is either the rest of this argument or the
** entire next argument.
** 36. option-argument absent
*/

static int	ft_getopt3(int ac, char **av, const char *optstr)
{
	if (*g_place)
		g_optarg = g_place;
	else if (ac > ++g_optind)
		g_optarg = av[g_optind];
	else
	{
		g_place = EMSG;
		if (*optstr == ':')
			return (BADARG);
		if (g_opterr)
			ft_printfd(2, "%s: option requires an argument -- %c\n",
				av[0], g_optopt);
		return (BADCH);
	}
	g_place = EMSG;
	++g_optind;
	return (0);
}

/*
** 58. See if option letter is one the caller wanted...
** 66. Does this option need an argument?
** 68. don't need argument
** 74. return option letter
*/

static int	ft_getopt2(int ac, char **av, const char *optstr)
{
	char	*oli;

	oli = NULL;
	if (g_optopt == ':' || (oli = ft_strchr(optstr, g_optopt)) == NULL)
	{
		if (*g_place == 0)
			++g_optind;
		if (g_opterr && *optstr != ':')
			ft_printfd(2, "%s: illegal option -- %c\n", av[0], g_optopt);
		return (BADCH);
	}
	if (oli[1] != ':')
	{
		g_optarg = NULL;
		if (*g_place == 0)
			++g_optind;
	}
	else
		ft_getopt3(ac, av, optstr);
	return (g_optopt);
}

/*
** 88. "--" => end of options
** 95. Argument is absent or is not an option
** 103. Solitary '-', treat as a '-' option
**     if the program (eg su) is looking for it.
*/

static int	ft_getopt1(int ac, const char *optstr)
{
	if (g_optind >= ac || *g_place++ != '-')
	{
		g_place = EMSG;
		return (-1);
	}
	g_optopt = *g_place++;
	if ((g_optopt = *g_place++) && g_optopt == '-' && *g_place == 0)
	{
		++g_optind;
		g_place = EMSG;
		return (-1);
	}
	if (g_optopt == 0)
	{
		g_place = EMSG;
		if (ft_strchr(optstr, '-') == NULL)
			return (-1);
		g_optopt = '-';
	}
	return (0);
}

int			ft_getopt(int ac, char **av, const char *optstr)
{
	g_place = EMSG;
	if (g_optreset || *g_place == 0)
	{
		g_optreset = 0;
		g_place = av[g_optind];
		if (ft_getopt1(ac, optstr) == -1)
			return (-1);
	}
	else
		g_optopt = *g_place++;
	return (ft_getopt2(ac, av, optstr));
}
