/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:15 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/31 21:57:24 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*head;

	head = lst;
	newlst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst != NULL)
	{
		newnode = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	ft_lstclear(head, &del);
	return (newlst);
}
