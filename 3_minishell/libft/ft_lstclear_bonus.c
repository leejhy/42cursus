/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:16:42 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/09 15:28:01 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*free_elem;

	while (*lst != NULL)
	{
		free_elem = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(free_elem, del);
	}
}
