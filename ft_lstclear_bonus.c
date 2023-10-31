/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:10:39 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/28 17:20:45 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	head = *lst;
	if (*lst == NULL)
		return ;
	// else//move last node
	while((*lst) != NULL)
	{
		(*del)(*lst->content);
		(*lst) = (*lst)->next;
		free(head);
		head = *lst;
	}
}
