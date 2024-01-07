/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 16:03:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_pos *pos_a, t_pos *pos_b)
{
	int	pivot1;
	int	pivot2;
	int	size;

	pivot1 = (pos_a->size) / 3;
	pivot2 = (pos_a->size / 3) * 2;
	size = (pos_a->size) - pivot2;
	while (pos_a->size > 3 && (pos_a->size != size))
	{
		if (pos_a->front->nb < pivot2)
		{
			pb(pos_a, pos_b);
			if (pos_b->front != NULL && pos_b->front->nb < pivot1)
			{
				if (pos_b->size > 1)
					rb(pos_b);
			}
			continue ;
		}
		ra(pos_a);
	}
	while (pos_a->size != 3)
		pb(pos_a, pos_b);
}

void	ft_find_optimal(t_pos *pos_a, t_pos *pos_b)
{
	int	*arr;
	int	min_b;

	arr = malloc(sizeof(int) * (pos_b->size));
	if (!arr)
		failed_malloc();
	arr = ft_make_case_arr(pos_a, pos_b, arr);
	min_b = ft_min_b(arr, pos_b->size, pos_a->size);
	do_greedy_op(arr, min_b, pos_a, pos_b);
}

void	greedy(t_pos *pos_a, t_pos *pos_b)
{
	set_pivot(pos_a, pos_b);
	sort_three_args(pos_a);
	while (pos_b->size != 0)
		ft_find_optimal(pos_a, pos_b);
	ft_last_sort(pos_a);
}
