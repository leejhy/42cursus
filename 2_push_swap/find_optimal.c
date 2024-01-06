/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:11:41 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:25:37 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_min(int *arr, int b_idx, int b_nb, t_pos *pos_a)
{
	t_stack	*temp_a;
	int		min;
	int		min_idx;
	int		i;

	i = 0;
	min_idx = 0;
	temp_a = pos_a->front;
	min = temp_a->nb;
	while (temp_a != NULL)
	{
		if (min > temp_a->nb)
		{
			min = temp_a->nb;
			min_idx = i;
		}
		i += 1;
		temp_a = temp_a->next;
	}
	if (b_nb < min)
		arr[b_idx] = min_idx;
	return (min);
}

int	find_a_max(int *arr, int b_idx, int b_nb, t_pos *pos_a)
{
	t_stack	*temp_a;
	int		max;
	int		max_idx;
	int		i;

	i = 0;
	max_idx = 0;
	temp_a = pos_a->front;
	max = temp_a->nb;
	while (temp_a != NULL)
	{
		if (max < temp_a->nb)
		{
			max = temp_a->nb;
			max_idx = i;
		}
		i += 1;
		temp_a = temp_a->next;
	}
	if (b_nb > max)
		arr[b_idx] = max_idx + 1;
	return (max);
}

void	ft_cnt_mid(int *arr, int b_idx, int b_nb, t_pos *pos_a)
{
	t_stack	*temp_a;
	int		cnt;

	cnt = 0;
	temp_a = pos_a->front;
	while (temp_a->next != NULL)
	{
		cnt += 1;
		arr[b_idx] = cnt;
		if (temp_a->nb < b_nb && b_nb < temp_a->next->nb)
			break ;
		temp_a = temp_a->next;
	}
	if (temp_a->next == NULL)
	{
		if (temp_a->nb < b_nb && b_nb < pos_a->front->nb)
			arr[b_idx] = cnt + 1;
	}
}
