/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:12:53 by junhylee         ###   ########.fr       */
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
	int	flag_rrb;
	int	flag_rra;
	int	min_b;
	int	min_a;
	int	middle_b;
	int	middle_a;

	flag_rrb = 0;
	middle_b = (*pos_B)->size / 2;
	middle_a = (*pos_A)->size;
	arr = malloc(sizeof(int) * (*pos_B)->size);
	if (!arr)
		return ;
	arr = ft_case_arr(pos_A, pos_B, arr);//여기까지 매우퍼펙트
	min_b = ft_min_b(arr, (*pos_B)->size);//여기 진짜 최적해를 찾아야함 rb rrb포함
	if (min_b > middle_b) // rrb
	{
		flag_rrb = 1;//이거 함수로 할까 ft_flag_on
		min_b = min_b % middle_b;//rrb 실행횟수
	}
	if (arr[min_b] > middle_a)
	{
		flag_rra = 1;
		arr[min_b] = ((*pos_A)->size) - arr[min_b]; //rra실행 횟수
		//얘는 그러면 arr[min_b] * 2 + 1번 실행됨
	}
	//b operation 먼저 실행 후 a operation실행
	if (arr[min_b] == 1)
	{
		if ((B의 i 인덱스 원소의 nb가) > (*pos_A)->rear->nb) //예외, 최대값
		{
			pa;
			ra;
			return ;
		}
	}
	else if (arr[min_b] == 0) // 예외, 최소값
	{
		pa;
		return ;
	}
	if (flag_rrb == 0 && flag_rra == 0)//rb, ra
	{//min_b만큼 rb하고, pa, arr[min_b]만큼 ra한다.
		ft_rb_ra;
	}
	if (flag_rrb == 1 && flag_rra == 0)//rb, ra
	{//min_b만큼 rrb하고, pa, arr[min_b]만큼 ra한다.
		ft_rrb_ra;
	}
	if (flag_rrb == 0 && flag_rra == 1)//rb, ra
	{//min_b만큼 rb하고, pa, arr[min_b]만큼 rra한다.
		ft_rb_rra;
	}
	if (flag_rrb == 1 && flag_rra == 1)//rb, ra
	{//min_b만큼 rrb하고, pa, arr[min_b]만큼 rra한다.
		ft_rrb_rra;
	}
	
	//optimal 찾고 그 최적해의 값을 알아내야함
	printf("b top %d\n", (*pos_B)->front->nb);
	printf("b bottom %d\n", (*pos_B)->rear->nb);
	// for (int i = 0; i < 13; i++)
	// 	printf("arr[%d] = %d\n", i, arr[i]);
	// if (min_idx > (*pos_B)->size / 2)//이때
	// 	operation_cnt = min_idx / 2;
}

void	greedy(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	set_pivot(head_A, pos_A, head_B, pos_B);
	sort_three_args(head_A, pos_A);
	// while ((*pos_B)->size != 0)
	// {
	ft_find_optimal(pos_A, pos_B);
	// }
}
