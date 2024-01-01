/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/01 18:59:05 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	int	pivot1;
	int	pivot2;
	int	size;
	
	pivot1 = ((*pos_A)->size) / 3;
	pivot2 = ((*pos_A)->size / 3) * 2;
	size = (*pos_A)->size - pivot2;
	while ((*pos_A)->size != size)
	{
		if ((*head_A)->nb < pivot2)
		{
			pb(head_A, pos_A, head_B, pos_B);
			if (*head_B != NULL && (*head_B)->nb < pivot1)
			{
				if ((*pos_B)->size > 1)
					rb(head_B, pos_B);//원소 1개일때 rb 오류
			}
			continue ;
		}
		ra(head_A, pos_A);
	}
	while ((*pos_A)->size != 3)
		pb(head_A, pos_A, head_B, pos_B);
}

void	ft_find_optimal(t_pos **pos_A, t_pos **pos_B)
{
	int	*arr;
	int	operation_cnt;
	int	min_idx;
	
	arr = malloc(sizeof(int) * (*pos_B)->size);
	if (!arr)
		return (-1);
	arr = ft_case_arr(pos_A, pos_B, arr);
	min_idx = ft_find_minidx(arr, (*pos_B)->size);//얘 rb인지 rrb인지 확인해야함
	if (min_idx > (*pos_B)->size / 2)
		operation_cnt = min_idx / 2;
	if (operation_cnt < min_idx);
		//reverse 연산;
	//여기서 operation 작동
}

void	greedy(t_stack **head_A, t_pos **pos_A, t_stack **head_B,t_pos **pos_B)
{
	int	optimal;

	set_pivot(head_A, pos_A, head_B, pos_B);
	sort_three_args(head_A, pos_A);
	while ((*pos_B)->size != 0)
	{
		optimal = ft_find_optimal(head_B, pos_B);
	}
}
