/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:10:39 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/05 16:28:24 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_lst;

	if (lst == NULL || del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		del_lst = *lst;
		(*del)((*lst)->content);
		(*lst) = (*lst)->next;
		free(del_lst);
	}
}
