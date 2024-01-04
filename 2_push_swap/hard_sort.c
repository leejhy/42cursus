/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:07:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:56:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hard_sort(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size == 2)
		sort_two_args(pos_a);
	if (pos_a->size == 3)
		sort_three_args(pos_a);
	if (pos_a->size == 4)
		sort_four_args(pos_a, pos_b);
	if (pos_a->size == 5)
		sort_five_args(pos_a, pos_b);
}

void	sort_two_args(t_pos *pos_a)
{
	t_stack	*temp_head;

	temp_head = pos_a->front;
	if (temp_head->nb > (temp_head->next->nb))
		sa(pos_a);
}

void	sort_three_args(t_pos *pos_a)
{
	t_stack	*head;
	t_stack	*node;
	int		max;

	head = pos_a->front;
	node = head;
	max = head->nb;
	while (node != NULL)//max 구하기
	{
		if (max < node->nb)
			max = node->nb;
		node = node->next;
	}
	if (max == head->nb)
		ra(pos_a);
	if (max == head->next->nb)
		rra(pos_a);
	sort_two_args(pos_a);
}

void	sort_four_args(t_pos *pos_a, t_pos *pos_b)
{
	int	cnt;

	pb(pos_a, pos_b);
	cnt = ft_nbcnt(pos_a->front, pos_b->front);
	sort_three_args(pos_a);
	if(cnt == 0)//가장 큼
	{
		pa(pos_a, pos_b);
		ra(pos_a);
	}
	if (cnt == 1)
	{
		rra(pos_a);
		pa(pos_a, pos_b);
		ra(pos_a);
		ra(pos_a);
	}
	if (cnt == 2)
	{
		ra(pos_a);
		pa(pos_a, pos_b);
		rra(pos_a);
	}
	if (cnt == 3)
		pa(pos_a, pos_b);
}

void	sort_five_args(t_pos *pos_a, t_pos *pos_b)
{
	ft_select_pb(pos_a, pos_b);
	sort_three_args(pos_a);
	if (pos_b->front->nb < pos_b->front->next->nb)
		sb(pos_b);
	pa(pos_a, pos_b);
	pa(pos_a, pos_b);
}
