/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:16:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 18:16:27 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_make_case_arr(t_pos *pos_a, t_pos *pos_b, int *arr)
{
	t_stack	*temp_b;
	int		i;
	int		a_min;
	int		a_max;

	i = 0;
	temp_b = pos_b->front;
	while (temp_b != NULL)
	{
		a_min = find_a_min(arr, i, temp_b->nb, pos_a);
		a_max = find_a_max(arr, i, temp_b->nb, pos_a);
		//min, max perfect
		if (a_min < temp_b->nb && temp_b->nb < a_max)
			ft_cnt_mid(arr, i, temp_b->nb, pos_a);
		i += 1; // rb하는 수
		temp_b = temp_b->next;
	}
	return (arr);
}

int	ft_rb_cnt(int i, int *arr, int arr_size, int a_size)
{
	int	rb_cnt;
	int	arr_rb_cnt;
	int	arr_i;

	rb_cnt = 0;
	while (i <= arr_size / 2) // rb판단
	{
		arr_rb_cnt = arr[rb_cnt];
		arr_i = arr[i];
		if (arr[rb_cnt] < 0)
			arr_rb_cnt = a_size + arr[rb_cnt];
		if (arr[i] < 0)
			arr_i = a_size + arr[i];
		if (rb_cnt + arr_rb_cnt > i + arr_i)
			rb_cnt = i;
		i += 1;
	}
	return (rb_cnt);
}

int	ft_rrb_cnt(int i, int *arr, int arr_size, int a_size)
{
	int	rrb_cnt;
	int	arr_rrb_cnt;
	int	arr_i;

	rrb_cnt = i;
	while (i < arr_size) // rb판단
	{
		arr_rrb_cnt = arr[rrb_cnt];
		arr_i = arr[i];
		if (arr[rrb_cnt] < 0)
			arr_rrb_cnt = a_size + arr[rrb_cnt];
		if (arr[i] < 0)
			arr_i = a_size + arr[i];
		if ((arr_size - rrb_cnt) + arr_rrb_cnt > (arr_size - i) + arr_i)
			rrb_cnt = i;
		i += 1;
	}
	return (rrb_cnt);
}

int	ft_min_b(int *arr, int arr_size, int a_size)
{
	int	i;
	int	a_cnt_rb;
	int	a_cnt_rrb;
	int	rb_cnt;
	int	rrb_cnt;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] > a_size / 2)
			arr[i] = arr[i] * -1;
		i++;
	}//ok
	rb_cnt = ft_rb_cnt(0, arr, arr_size, a_size);
	rrb_cnt = ft_rrb_cnt(arr_size / 2, arr, arr_size, a_size);
	a_cnt_rb = arr[rb_cnt];
	a_cnt_rrb = arr[rrb_cnt];
	if (arr[rb_cnt] < 0)
		a_cnt_rb = a_size + arr[rb_cnt];
	if (arr[rrb_cnt] < 0)
		a_cnt_rrb = a_size + arr[rrb_cnt];
	if (rb_cnt + a_cnt_rb < (arr_size - rrb_cnt) + a_cnt_rrb)
		return (rb_cnt);
	return (rrb_cnt);
}
void	ft_last_sort(t_pos *pos_a)
{
	t_stack	*head;
	int		a_cnt;
	int		i;
	
	i = 0;
	head = pos_a->front;
	a_cnt = find_zero(head);
	if (head->nb == 0)
		return ;
	if (a_cnt > pos_a->size / 2)//0의 위치가 절반이 넘으면 rra
	{
		while (i < pos_a->size - a_cnt)
		{
			rra(pos_a);
			i += 1;
		}
	}
	else// 절반 안넘으면 ra
	{
		while (i < a_cnt)
		{
			ra(pos_a);
			i += 1;
		}
	}
}
