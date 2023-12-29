/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:07:40 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/23 13:08:18 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hard_sort(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_A)->size == 2)
		sort_two_args(*head_A, *pos_A);
}

void	sort_two_args(t_stack **head_A, t_pos **pos_A)
{
	t_stack *temp_head;

	temp_head = *head_A;
	if (temp_head->nb > (temp_head->next->nb))
		sa(head_A, pos_A);
}

void	sort_three_args(t_stack **head_A, t_pos **pos_A)
{
	t_stack *node;
	int	max;

	node = *head_A;
	max = (*head_A)->nb;
	while (node != NULL)//max 구하기
	{
		if (max < node->nb)
			max = node->nb;
		node = node->next;
	}
	if (max == (*head_A)->nb)
		ra(head_A, pos_A);
	if (max == (*head_A)->next->nb)
		rra(head_A, pos_A);
	sort_two_args(head_A, pos_A);
}

void	sort_four_args(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	int	cnt;

	cnt = ft_nbcnt(*head_A, *head_B);
	pb(head_A, pos_A, head_B, pos_B);
	sort_three_args(head_A, pos_A);
	if (cnt == 0)
	{
		pa(head_A, pos_A, head_B, pos_B);
		rra(head_A, pos_A);
	}
	if (cnt == 1)
	{
		rra(head_A, pos_A);
		pa(head_A, pos_A, head_B, pos_B);
		ra(head_A, pos_A);
		ra(head_A, pos_A);
	}
	if (cnt == 2)
	{
		ra(head_A, pos_A);
		pa(head_A, pos_A, head_B, pos_B);
		rra(head_A, pos_A);
	}
	else
		pa(head_A, pos_A, head_B, pos_B);
}

void	sort_five_args(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	
}
