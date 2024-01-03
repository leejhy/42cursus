/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:48 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:55:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	r_rotate(t_stack *head, t_pos *pos)
{//The last elements becomes the first one
	t_stack	*node;
	int		temp_nb;

	if (head == NULL)
		return ;
	temp_nb = pos->rear->nb;
	node = pos->rear->prev;
	while (node->prev != NULL)
	{
		node->next->nb = node->nb;
		node = node->prev;
	}
	node->next->nb = node->nb;
	node->nb = temp_nb;
}

void	rra(t_pos **pos_a)
{
	r_rotate((*pos_a)->front, *pos_a);
	printf("rra\n");
}

void	rrb(t_pos **pos_b)
{
	r_rotate((*pos_b)->front, *pos_b);
	printf("rrb\n");
}

void	rrr(t_pos **pos_a, t_pos **pos_b)
{
	r_rotate((*pos_a)->front, *pos_a);
	r_rotate((*pos_b)->front, *pos_b);
	printf("rrr\n");
}