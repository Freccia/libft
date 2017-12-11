/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 18:40:14 by lfabbro           #+#    #+#             */
/*   Updated: 2017/12/11 16:07:24 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_mem_realloc(void *ptr, size_t size)
{
	void		*dup;

	dup = ft_memalloc(size);
	if (ptr)
	{
		if (dup)
			ft_memcpy(dup, ptr, size);
		ft_memdel(&ptr);
	}
	return (dup);
}
