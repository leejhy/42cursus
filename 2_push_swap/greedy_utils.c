/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:16:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/01 18:41:35 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_case_arr(t_pos **pos_A, t_pos **pos_B, int *arr)
{
	t_stack	*B;
	t_stack	*A;
	int		cnt_A;
	int		i;
	
	i = 0;
	cnt_A = 1;
	B = (*pos_B)->front;
	while (B != NULL)
	{//인덱스가 b에서 연산하는 값, 배열 안의 값이 a에서 연산할 값
		A = (*pos_A)->front->next;
		if (B->nb < (*pos_A)->front->nb)
			arr[i] = 0;//top보다 작으면 최소값이니까 rb만하고 pa가능
		else if (B->nb > (*pos_A)->rear->nb)
			arr[i] = 1;//b가 A의 바텀보다 크면 최대값이니가 rra 해야햐니까 1추가
		while (A != NULL && (A->prev->nb < B->nb && B->nb < A->nb))
		{
			cnt_A += 1;
			arr[i] = i + cnt_A;//ra하는 수
			A = A->next;
		}
		i += 1; // rb하는 수
		B = B->next;
	}// 이거 rra rrb / ra rb 구분 해야함..
	return (arr);
}
int	ft_find_minidx(int *arr, int arr_size)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < arr_size)
	{
		if (arr[min] > arr[i])
			min = i;
		i++;
	}
	return (i);
}