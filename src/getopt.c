/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:50:14 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/16 18:07:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getopt.h"

char		*g_optarg = 0;
int			g_optind = 1;
int			g_optopt = 0;
int			g_opterr = 1;
static int	g_optreset = 0;
static char	*g_place = EMSG;

static int	ft_getopt3(int ac, char **av, const char *optstr)
{
	/* Option-argument is either the rest of this argument or the
	   entire next argument. */
	if (*g_place)
		g_optarg = g_place;
	else if (ac > ++g_optind)
		g_optarg = av[g_optind];
	else
	{
		/* option-argument absent */
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

static int	ft_getopt2(int ac, char **av, const char *optstr)
{
	char	*oli;

	oli = NULL;
	/* See if option letter is one the caller wanted... */
	if (g_optopt == ':' || (oli = ft_strchr(optstr, g_optopt)) == NULL)
	{
		if (*g_place == 0)
			++g_optind;
		if (g_opterr && *optstr != ':')
			ft_printfd(2, "%s: illegal option -- %c\n", av[0], g_optopt);
		return (BADCH);
	}
	/* Does this option need an argument? */
	if (oli[1] != ':')
	{
		/* don't need argument */
		g_optarg = NULL;
		if (*g_place == 0)
			++g_optind;
	}
	else
		ft_getopt3(ac, av, optstr);
	/* return option letter */
	return (g_optopt);
}

int			ft_getopt(int ac, char **av, const char *optstr)
{
	g_place = EMSG;
	if (g_optreset || *g_place == 0)
	{
		g_optreset = 0;
		g_place = av[g_optind];
		if (g_optind >= ac || *g_place++ != '-')
		{
			/* Argument is absent or is not an option */
			g_place = EMSG;
			return (-1);
		}
		g_optopt = *g_place++;
		if (g_optopt == '-' && *g_place == 0)
		{
			/* "--" => end of options */
			++g_optind;
			g_place = EMSG;
			return (-1);
		}
		if (g_optopt == 0)
		{
			/* Solitary '-', treat as a '-' option
			   if the program (eg su) is looking for it. */
			g_place = EMSG;
			if (ft_strchr(optstr, '-') == NULL)
				return (-1);
			g_optopt = '-';
		}
	}
	else
		g_optopt = *g_place++;
	return (ft_getopt2(ac, av, optstr));
}
