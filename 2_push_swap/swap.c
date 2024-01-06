/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:59 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:30:49 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head, t_pos *pos)
{
	int	temp_nb;

	if (pos->size <= 1)
		return ;
	temp_nb = head->nb;
	head->nb = head->next->nb;
	head->next->nb = temp_nb;
}

void	sa(t_pos *pos_a)
{
	if (pos_a->size <= 1)
		return ;
	swap(pos_a->front, pos_a);
	write(1, "sa\n", 3);
}

void	sb(t_pos *pos_b)
{
	if (pos_b->size <= 1)
		return ;
	swap(pos_b->front, pos_b);
	write(1, "sa\n", 3);
}

void	ss(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size <= 1 || pos_b->size <= 1)
		return ;
	swap(pos_a->front, pos_a);
	swap(pos_b->front, pos_b);
	write(1, "ss\n", 3);
}
