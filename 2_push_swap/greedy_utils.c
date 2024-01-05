/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:16:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/04 22:12:39 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_case_arr(t_pos *pos_a, t_pos *pos_b, int *arr)
{
	t_stack	*b;
	t_stack	*a;
	int		cnt_a;
	int		i;

	i = 0;
	b = pos_b->front;
	while (b != NULL)
	{//인덱스가 b에서 연산하는 값, 배열 안의 값이 a에서 연산할 값	
		cnt_a = 0;
		a = pos_a->front->next;
		if (b->nb < pos_a->front->nb)//pos_a->front->nb가 아니라 a의 최소값의 인덱스를 구하고, 그만큼 ra/ rra 해야함 즉, a의 최소원소보다 b의 nb가 작으면
			arr[i] = 0;//top보다 작으면 최소값이니까 인덱스 수만큼 rb만하고 pa가능
		else if (b->nb > pos_a->rear->nb)//pos_a->rear->nb가 아니라 a의 최대값의 인덱스를 구하고 그만큼 ra /rra해야함 즉, a의 최대 원소보다 b의 nb가 크면
			arr[i] = 1;//b의 top이 A의 바텀보다 크면 최대값이니가 pa ra(a의 연산 1번 따라서 1)
		else
		{
			// while (A != NULL && !(A->prev->nb < B->nb && B->nb < A->nb))
			while (a != NULL && a->prev->nb < b->nb)
			{
				// cnt_A += 1;
				// arr[i] = i + cnt_A;//ra하는 수(a의 인덱스) 이거 i+cnt_A가아니라 cnt_A아닌가
				arr[i] = ++cnt_a;//a의 인덱스
				a = a->next;
			}
		}
		i += 1; // rb하는 수
		b = b->next;
	}// 이거 rra rrb / ra rb 구분 해야함..
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

int	ft_rrb_cnt(int *i, int *arr, int arr_size)
{
	int	rrb_cnt;

	rrb_cnt = 0;
	while (i <= arr_size) // rb판단
	{
		if (arr[rrb_cnt] < 0 && arr[*i] < 0)
		{	
			if (rrb_cnt != i && (rrb_cnt + (arr[rrb_cnt] * -1) > i + (arr[*i] * -1)))//비교할땐 ra, rra구분해서 비교하고 return 할때는 인덱스 그대로 넘겨줘야함
				rrb_cnt = *i;
		}
		else if (arr[rrb_cnt] < 0)
		{
			if (rrb_cnt != *i && (rrb_cnt + (arr[rrb_cnt] * -1) > *i + arr[*i]))//비교할땐 ra, rra구분해서 비교하고 return 할때는 인덱스 그대로 넘겨줘야함
				rrb_cnt = *i;
		}
		else if (arr[*i] < 0)
		{
			if (rrb_cnt + arr[rrb_cnt] > *i + (arr[*i] * -1))
				rrb_cnt = *i;
		}
		*i += 1;
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
	}
	rb_cnt = ft_rb_cnt(0, arr, arr_size);
	rrb_cnt = ft_rrb_cnt(arr_size / 2 + 1, arr, arr_size);
	if (arr[rb_cnt] < 0)
		rb_a = arr[rb_cnt] * -1;
	if (arr[rrb_cnt] < 0)
		rrb_a = arr[rrb_cnt] * -1;
	if (rb_cnt + rb_a < rrb_cnt / 2 + rrb_a)
		return (rb_cnt);
	else
		return (rrb_cnt);
	// min_dix(b의 연산 수) + min_value(a의 연산 수)
}

int	ft_get_idx_b(t_stack *head, int idx)
{
	int	i;
	t_stack	*node;

	node = head;
	i = 0;
	while (i < idx)
	{
		node = node->next;
		i++;
	}
	return (node->nb);
}

/*int	ft_min_a(int *arr, int arr_size)
{
	int	i;
	int	rb_idx;
	int	rrb_idx;

	i = 0;
	rb_idx = 0;
	rrb_idx = 0;
	while (i <= arr_size / 2) // rb판단
	{
		if (rb_idx + arr[rb_idx] > i + arr[i])
			rb_idx = i;
		i++;
	}
	while (i < arr_size) //rrb연산
	{
		if (rrb_idx + arr[rrb_idx] > i + arr[i])
			rrb_idx = i;
		i++;
	}
	if (rb_idx + arr[rb_idx] < rrb_idx / 2 + arr[rrb_idx])
		return (rb_idx);
	else
		return (rrb_idx);
}*/