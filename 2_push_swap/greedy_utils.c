/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:16:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/05 22:10:04 by junhylee         ###   ########.fr       */
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
		if (a_min < temp_b->nb && temp_b->nb < a_max)
			ft_cnt_mid(arr, i, temp_b->nb, pos_a);
		i += 1; // rb하는 수
		temp_b = temp_b->next;
	}
	return (arr);
}

int	ft_rb_cnt(int i, int *arr, int arr_size)
{
	int	rb_cnt;

	rb_cnt = 0;
	// arr_size / 2 + 1
	while (i <= arr_size / 2) // rb판단
	{
		if (arr[rb_cnt] < 0 && arr[i] < 0)
		{	
			if (rb_cnt != i && (rb_cnt + (arr[rb_cnt] * -1) > i + (arr[i] * -1)))//비교할땐 ra, rra구분해서 비교하고 return 할때는 인덱스 그대로 넘겨줘야함
				rb_cnt = i;
		}
		else if (arr[rb_cnt] < 0)
		{
			if (rb_cnt != i && (rb_cnt + (arr[rb_cnt] * -1) > i + arr[i]))//비교할땐 ra, rra구분해서 비교하고 return 할때는 인덱스 그대로 넘겨줘야함
				rb_cnt = i;
		}
		else if (arr[i] < 0)
		{
			if (rb_cnt + arr[rb_cnt] > i + (arr[i] * -1))
				rb_cnt = i;
		}
		i += 1;
	}
	return (rb_cnt);
}

int	ft_rrb_cnt(int i, int *arr, int arr_size)
{
	int	rrb_cnt;

	// printf("%d\n")
	rrb_cnt = 0;
	while (i < arr_size) // rb판단
	{
		if (arr[rrb_cnt] < 0 && arr[i] < 0)
		{	
			if (rrb_cnt != i && (rrb_cnt + (arr[rrb_cnt] * -1) > i + (arr[i] * -1)))//비교할땐 ra, rra구분해서 비교하고 return 할때는 인덱스 그대로 넘겨줘야함
				rrb_cnt = i;
		}
		else if (arr[rrb_cnt] < 0)
		{
			if (rrb_cnt != i && (rrb_cnt + (arr[rrb_cnt] * -1) > i + arr[i]))//얘가 문제가 좀있네
				rrb_cnt = i;
		}
		else if (arr[i] < 0)
		{
			if (rrb_cnt + arr[rrb_cnt] > i + (arr[i] * -1))
				rrb_cnt = i;
		}
		i += 1;
	}
	return (rrb_cnt);
}

int	ft_min_b(int *arr, int arr_size, int middle_a)
{
	int	i;
	int	rb_a;
	int	rrb_a;
	int	rb_cnt;
	int	rrb_cnt;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] > middle_a)
			arr[i] = arr[i] * -1;
		i++;
	}//ok
	rb_cnt = ft_rb_cnt(0, arr, arr_size);
	rrb_cnt = ft_rrb_cnt((arr_size / 2) + 1, arr, arr_size);
	rb_a = arr[rb_cnt];
	rrb_a = arr[rrb_cnt];
	if (arr[rb_cnt] < 0)
		rb_a = arr[rb_cnt] * -1;
	if (arr[rrb_cnt] < 0)
		rrb_a = arr[rrb_cnt] * -1;
	if (rb_cnt + rb_a < rrb_cnt / 2 + rrb_a)
		return (rb_cnt);
	else
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
