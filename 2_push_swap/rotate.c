/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:50 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:29:57 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *head, t_pos *pos)
{
	t_stack	*node;
	int		temp_nb;

	if (pos->size == 0 || pos->size == 1)
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

void	ra(t_pos *pos_a)
{
	if (pos_a->size < 1)
		return ;
	rotate(pos_a->front, pos_a);
	write(1, "ra\n", 3);
}

void	rb(t_pos *pos_b)
{
	if (pos_b->size < 1)
		return ;
	rotate(pos_b->front, pos_b);
	write(1, "rb\n", 3);
}

void	rr(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size < 1 || pos_b->size < 1)
		return ;
	rotate(pos_a->front, pos_a);
	rotate(pos_b->front, pos_b);
	write(1, "rr\n", 3);
}
