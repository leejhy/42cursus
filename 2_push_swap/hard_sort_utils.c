/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:34 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 22:02:45 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbcnt(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	int		cnt;

	cnt = 0;
	temp_a = a;
	while (temp_a != NULL)
	{
		if (b->nb < temp_a->nb)
			cnt += 1;
		temp_a = temp_a->next;
	}
	return (cnt);
}

int	find_zero(t_stack *a)
{
	int		loc;
	t_stack	*temp_a;

	temp_a = a;
	loc = 0;
	while (temp_a != NULL && temp_a->nb != 0)
	{
		// printf("find_zero\n");
		loc += 1;
		temp_a = temp_a->next;
	}
	if (temp_a != NULL)
		return (loc);
	return (-1);
}

int	find_one(t_stack *a)
{
	int		loc;
	t_stack	*temp_a;

	temp_a = a;
	loc = 0;
	while (temp_a != NULL && temp_a->nb != 1)
	{
		// printf("find_one\n");
		loc += 1;
		temp_a = temp_a->next;
	}
	if (temp_a != NULL)
		return (loc);
	return (-1);
}

void	ft_select_pb(t_pos *pos_a, t_pos *pos_b)
{
	int	loc_one;
	int	loc_zero;

	while (find_zero(pos_a->front) >= 0 || find_one(pos_a->front) >= 0)
	{
		loc_zero = find_zero(pos_a->front);
		loc_one = find_one(pos_a->front);
		if (loc_one == 0 || loc_zero == 0)
			pb(pos_a, pos_b);
		else if (loc_one == 1 || loc_zero == 1)
			ra(pos_a);
		else if (loc_one == pos_a->rear->nb
			|| loc_zero == pos_a->rear->nb)
			rra(pos_a);
		else if (loc_one == 2 || loc_zero == 2)
		{
			ra(pos_a);
			ra(pos_a);
		}
		else if (loc_one == 3 || loc_zero == 3)
		{
			rra(pos_a);
			rra(pos_a);
		}
	}
}

int	is_sorted(t_stack *head_a)
{
	t_stack	*temp;
	int		cnt;
	int		size;

	cnt = 0;
	size = 0;
	temp = head_a;
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