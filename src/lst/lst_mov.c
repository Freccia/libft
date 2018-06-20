/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:03:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/20 18:03:16 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** DESCRIPTION:
**     Adds the element new at the beginnning of the list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

/*
** DESCRIPTION:
**    Iterates the list lst and applies the function f to each link.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*ret;

	ret = NULL;
	ret = lst;
	while (ret)
	{
		tmp = ret;
		ret = ret->next;
		if (tmp)
			f(tmp);
	}
}

/*
** DESCRIPTION:
**     Iterates a list lst and applies the function f to each link to
**     create a “fresh” list (using malloc(3)) resulting from the successive
**     applications of f. If the allocation fails, the function
**     returns NULL
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new_list)
		{
			new_list = tmp;
			ret = new_list;
			new_list->next = NULL;
		}
		else
		{
			new_list->next = tmp;
			new_list = new_list->next;
			tmp->next = NULL;
		}
		lst = lst->next;
	}
	return (ret);
}
