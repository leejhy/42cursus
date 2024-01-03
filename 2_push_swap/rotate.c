/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:50 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:54:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *head, t_pos *pos)
{//first becomes the last one
	t_stack	*node;
	int		temp_nb;

	if (pos->size == 0)
		return ;
	temp_nb = head->nb;
	node = head->next;
	while (node->next != NULL)
	{
		node->prev->nb = node->nb;
		node = node->next;
	}
	node->prev->nb = node->nb;
	node->nb = temp_nb;
}

void	ra(t_pos **pos_a)
{
	rotate((*pos_a)->front, *pos_a);
	printf("ra\n");
}

void	rb(t_pos **pos_b)
{
	rotate((*pos_b)->front, *pos_b);
	printf("rb\n");
}

void	rr(t_pos **pos_a, t_pos **pos_b)
{
	rotate((*pos_a)->front, *pos_a);
	rotate((*pos_b)->front, *pos_b);
	printf("rr\n");
}