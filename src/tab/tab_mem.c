/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:24:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:24:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		**ft_tabnew(size_t size)
{
	char	**new;
	size_t	i;

	i = -1;
	if (size == 0 || (new = malloc(sizeof(new) * (size + 1))) == NULL)
		return (NULL);
	while (++i <= size)
		new[i] = NULL;
	return (new);
}

size_t		ft_tablen(char **tab)
{
	size_t		len;

	len = 0;
	if (tab)
	{
		while (*tab)
		{
			++tab;
			++len;
		}
	}
	return (len);
}

char		**ft_tabpop(char **tab, size_t pop)
{
	char	**new;
	size_t	len;
	size_t	i;

	new = NULL;
	len = ft_tablen(tab);
	len += (len == 1) ? 1 : 0;
	i = -1;
	if (tab && len && pop < len)
	{
		new = ft_tabnew(len - 1);
		while (++i < pop && tab[i])
		{
			new[i] = ft_strdup(tab[i]);
		}
		while (tab[++i])
		{
			new[i - 1] = ft_strdup(tab[i]);
		}
		new[i - 1] = NULL;
	}
	return (new);
}

void		ft_tabfree(char **tab)
{
	ft_free_tab(tab);
}

void		ft_free_tab(char **tab)
{
	int		i;

	i = -1;
	if (tab != NULL)
	{
		while (tab[++i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		free(tab);
		tab = NULL;
	}
}
