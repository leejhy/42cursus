/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:48 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:30:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *head, t_pos *pos)
{
	t_stack	*node;
	int		temp_nb;

	if (pos->size == 0 || pos->size == 1)
		return ;
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

void	rra(t_pos *pos_a)
{
	if (pos_a->size < 1)
		return ;
	r_rotate(pos_a->front, pos_a);
	write(1, "rra\n", 4);
}

void	rrb(t_pos *pos_b)
{
	if (pos_b->size < 1)
		return ;
	r_rotate(pos_b->front, pos_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size < 1 || pos_b->size < 1)
		return ;
	r_rotate(pos_a->front, pos_a);
	r_rotate(pos_b->front, pos_b);
	write(1, "rrr\n", 4);
}
