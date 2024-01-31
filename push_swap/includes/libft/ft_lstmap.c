/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:44:23 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/08 18:47:35 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*ptn;

	if (!lst || !f || !del)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (NULL);
	ptn = list;
	lst = lst->next;
	while (lst)
	{
		ptn->next = ft_lstnew(f(lst->content));
		if (!ptn->next)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ptn = ptn->next;
		lst = lst->next;
	}
	ptn->next = NULL;
	return (list);
}
