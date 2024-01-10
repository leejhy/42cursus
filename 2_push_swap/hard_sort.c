/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:07:40 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:21:44 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hard_sort(t_pos *pos_a)
{
	if (pos_a->size == 2)
		sort_two_args(pos_a);
	if (pos_a->size == 3)
		sort_three_args(pos_a);
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
	while (node != NULL)
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

int	find_zero(t_stack *a)
{
	int		loc;
	t_stack	*temp_a;

	temp_a = a;
	loc = 0;
	while (temp_a != NULL && temp_a->nb != 0)
	{
		loc += 1;
		temp_a = temp_a->next;
	}
	if (temp_a != NULL)
		return (loc);
	return (-1);
}

int	is_sorted(t_stack *head_a)
{
	t_stack	*temp;
	int		cnt;
	int		size;

	cnt = 0;
	size = 0;
	temp = head_a;
	if (head_a == 0)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->nb < temp->next->nb)
			cnt += 1;
		size += 1;
		temp = temp->next;
	}
	if (cnt == size)
		return (1);
	return (0);
}
