/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:18:21 by lfabbro           #+#    #+#             */
/*   Updated: 2016/09/22 14:06:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		a;

	a = 0;
	if (s1 && s2)
	{
		while (s1[a] == s2[a])
		{
			if (s1[a] == '\0' && s2[a] == '\0')
				return (0);
			a++;
		}
		return ((((unsigned char*)s1)[a] - (((unsigned char*)s2)[a])));
	}
	return (0);
}
