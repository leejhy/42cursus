/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:26:13 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/24 11:29:37 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstlast(t_list *lst)
{
	int		cnt;
	t_list	*lst_node;

	lst_node = lst;
	while (lst_node->next != NULL)//lst->n
		lst_node = lst_node->next;
	return (lst_node);
}
