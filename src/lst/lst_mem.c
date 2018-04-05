/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:42:03 by lfabbro           #+#    #+#             */
/*   Updated: 2018/04/05 16:43:00 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** DESCRIPTION:
**     Allocates (with malloc(3)) and returns a “fresh” link. The
**     variables content and content_size of the new link are initialized
**     by copy of the parameters of the function. If the parameter
**     content is nul, the variable content is initialized to
**     NULL and the variable content_size is initialized to 0 even
**     if the parameter content_size isn’t. The variable next is
**     initialized to NULL. If the allocation fails, the function returns
**     NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		(*new_list).content = NULL;
		(*new_list).content_size = 0;
		(*new_list).next = NULL;
		return (new_list);
	}
	(*new_list).content = (void *)malloc(content_size);
	ft_memmove((void *)(*new_list).content, content, content_size);
	(*new_list).content_size = content_size;
	(*new_list).next = NULL;
	return (new_list);
}

/*
** DESCRIPTION:
**     Takes as a parameter the adress of a pointer to a link and
**     frees the memory of this link and every successors of that link
**     using the functions del and free(3). Finally the pointer to
**     the link that was just freed must be set to NULL (quite similar
**     to the function ft_memdel from the mandatory part).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ret;

	ret = NULL;
	ret = *alst;
	while (ret)
	{
		tmp = ret;
		ret = ret->next;
		if (tmp)
			ft_lstdelone(&tmp, del);
	}
	*alst = NULL;
}

/*
** DESCRIPTION
**     Takes as a parameter a link’s pointer address and frees the
**     memory of the link’s content using the function del given as
**     a parameter, then frees the link’s memory using free(3). The
**     memory of next musnt not be freed under any circumstance.
**     Finally, the pointer to the link that was just freed must be
**     set to NULL (quite similar to the function ft_memdel in the
**     mandatory part).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->content)
	{
		del((*alst)->content, (*alst)->content_size);
		free((*alst)->content);
	}
	if ((void *)*alst)
		free((void *)*alst);
	*alst = NULL;
}
