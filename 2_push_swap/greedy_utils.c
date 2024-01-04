/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:16:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:58:03 by junhylee         ###   ########.fr       */
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
		printf("Bnumber %d\n", b->nb);
		a = pos_a->front->next;
		if (b->nb < pos_a->front->nb)
			arr[i] = 0;//top보다 작으면 최소값이니까 인덱스 수만큼 rb만하고 pa가능
		else if (b->nb > pos_a->rear->nb)
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
int	ft_min_b(int *arr, int arr_size)
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