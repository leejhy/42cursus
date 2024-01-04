/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 22:15:02 by junhylee         ###   ########.fr       */
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
	while (pos_a->size > 3 && (pos_a->size != size))// 6개일때 오류나서 수정
	{
		printf("a top %d\n", pos_a->front->nb);
		if (pos_a->front->nb < pivot2)
		{
			pb(pos_a, pos_b);
			if (pos_b->front != NULL && pos_b->front->nb < pivot1)
			{
				if (pos_b->size > 1)
					rb(pos_b);//원소 1개일때 rb 오류
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
	int	b_idx_nb;
	int	*arr;
	int	flag_rrb;
	int	flag_rra;
	int	rrb_cnt;
	int	rra_cnt;
	int	min_b;
	int	min_a;//
	int	middle_b;//
	int	middle_a;//

	flag_rrb = 0;
	middle_b = pos_b->size / 2;
	middle_a = pos_a->size;
	arr = malloc(sizeof(int) * pos_b->size);
	if (!arr)
		exit(0);
	arr = ft_case_arr(pos_a, pos_b, arr);//여기까지 매우퍼펙트
	min_b = ft_min_b(arr, pos_b->size);//여기 진짜 최적해를 찾아야함 rb rrb포함
	if (min_b > middle_b) // rrb
	{
		flag_rrb = 1;//이거 함수로 할까 ft_flag_on
		rrb_cnt = min_b % middle_b;//rrb 실행횟수
	}
	if (arr[min_b] > middle_a)
	{
		flag_rra = 1;
		rra_cnt = (pos_a->size) - arr[min_b]; //rra실행 횟수
		//얘는 그러면 arr[min_b] * 2 + 1번 실행됨
	}
	if (arr[min_b] == 1)
	{
		b_idx_nb = ft_get_idx_b(pos_b->front, min_b);
		// if ((B의 i 인덱스 원소의 nb가) > pos_a->rear->nb) //예외, 최대값
		if (b_idx_nb > pos_a->rear->nb) //예외, 최대값
		{
			pa;
			ra;
			return ;
		}
	}
	else if (arr[min_b] == 0) // 예외, 최소값 min_b만큼 rb or rrb 만하고 pa
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
	printf("b top %d\n", pos_b->front->nb);
	printf("b bottom %d\n", pos_b->rear->nb);
	// for (int i = 0; i < 13; i++)
	// 	printf("arr[%d] = %d\n", i, arr[i]);
	// if (min_idx > (*pos_B)->size / 2)//이때
	// 	operation_cnt = min_idx / 2;
}

void	greedy(t_pos *pos_a, t_pos *pos_b)
{
	set_pivot(pos_a, pos_b);//OK
	sort_three_args(pos_a);//ok
	// while ((*pos_B)->size != 0)
	// {
	ft_find_optimal(pos_a, pos_b);//얘만 완성하면됨
	// }
}
