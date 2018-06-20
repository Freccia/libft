/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:25:04 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:25:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabcpy(char **dst, char **src)
{
	int		i;

	i = -1;
	if (src && dst)
	{
		while (src[++i])
		{
			dst[i] = ft_strdup(src[i]);
		}
		dst[i] = NULL;
	}
	return (dst);
}

char		**ft_tabdup(char **tab)
{
	char	**dup;
	int		i;

	i = 0;
	if ((dup = ft_tabnew(ft_tablen(tab))) == NULL)
		return (NULL);
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		++i;
	}
	dup[i] = NULL;
	return (dup);
}

char		**ft_tabndup(char **tab, size_t b)
{
	char	**dup;
	size_t	len;
	size_t	i;

	if ((dup = ft_tabnew(b)) == NULL)
		return (NULL);
	i = 0;
	len = ft_tablen(tab);
	while (i < b && i < len)
	{
		dup[i] = ft_strdup(tab[i]);
		++i;
	}
	dup[i] = NULL;
	return (dup);
}

char		**ft_tabcat(char **tab, char *str)
{
	char	**tmp;
	size_t	len;

	tmp = NULL;
	if (tab && *tab && str)
	{
		len = ft_tablen(tab);
		if ((tmp = ft_tabnew(len + 2)) == NULL)
			return (NULL);
		if ((tmp = ft_tabcpy(tmp, tab)) == NULL)
			return (NULL);
		if ((tmp[len] = ft_strdup(str)) == NULL)
			return (NULL);
		tmp[len + 1] = NULL;
	}
	else if (str)
	{
		if ((tmp = ft_tabnew(2)) == NULL)
			return (NULL);
		if ((tmp[0] = ft_strdup(str)) == NULL)
			return (NULL);
		tmp[1] = NULL;
	}
	return (tmp);
}
