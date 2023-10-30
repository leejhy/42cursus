/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:21:42 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/30 16:33:44 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	*lst = new;
	if ((*lst)->next != NULL)
		new->next = (*lst)->next;
}
