/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/04 22:21:10 by junhylee         ###   ########.fr       */
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

	flag_rra = 0;
	flag_rrb = 0;
	arr = malloc(sizeof(int) * (pos_b->size));
	if (!arr)
		exit(0);
	arr = ft_case_arr(pos_a, pos_b, arr);//수정해야함
	//---------------------------------------------------------------------------------------//
	min_b = ft_min_b(arr, pos_b->size, pos_a->size / 2);//여기 진짜 최적해를 찾아야함 rb rrb포함
	if (min_b > pos_b->size / 2) // rrb, 여기서 Floating point exception나옴
	{
		flag_rrb = 1;//이거 함수로 할까 ft_flag_on
		rrb_cnt = pos_b->size - min_b;//rrb 실행횟수
	}
	if (arr[min_b] < 0)//이거 음수로 나오는거 확인
	{
		flag_rra = 1;
		rra_cnt = (pos_a->size) + arr[min_b]; //rra실행 횟수
		//얘는 그러면 arr[min_b] * 2 + 1번 실행됨
	}
	if (arr[min_b] == 1)//얘부터 함수화
	{
		b_idx_nb = ft_get_idx_b(pos_b->front, min_b);
		// if ((B의 i 인덱스 원소의 nb가) > pos_a->rear->nb) //예외, 최대값
		if (b_idx_nb > pos_a->rear->nb) //예외, 최대값
		{
			pa(pos_a, pos_b);
			ra(pos_a);
			return ;
		}
	}
	else if (arr[min_b] == 0) // 예외, 최소값 min_b만큼 rb or rrb 만하고 pa
	{
		if (flag_rrb == 1)
			ft_ra_pa(pos_a, pos_b, rrb_cnt, flag_rrb);
		else
			ft_ra_pa(pos_a, pos_b, min_b, flag_rrb);
		return ;
	}
	if (flag_rrb == 0 && flag_rra == 0)//rb, ra
	{
		ft_rb_ra(pos_a, pos_b, min_b, arr[min_b]);
		return ;
	}
	if (flag_rrb == 1 && flag_rra == 0)//rb, ra
	{
		ft_rrb_ra(pos_a, pos_b, rrb_cnt, arr[min_b]);//segmentaion
		printf("============================\n");
		return ;
	}
	if (flag_rrb == 0 && flag_rra == 1)//rb, ra
	{
		ft_rb_rra(pos_a, pos_b, min_b, rra_cnt);
		return ;
	}
	if (flag_rrb == 1 && flag_rra == 1)//rb, ra
	{
		ft_rrb_rra(pos_a, pos_b, rrb_cnt, rra_cnt);
		return ;
	}
	//optimal 찾고 그 최적해의 값을 알아내야함
}

void	greedy(t_pos *pos_a, t_pos *pos_b)
{
	set_pivot(pos_a, pos_b);//OK
	sort_three_args(pos_a);//ok
	// printf("a %d\n", pos_a->front->nb);
	// printf("a %d\n", pos_a->front->next->nb);
	// printf("a %d\n", pos_a->front->next->next->nb);;
	while (pos_b->size != 0)
	{
		if (pos_b->size == 1)
			printf("last pb %d\n",pos_b->front->nb);
		ft_find_optimal(pos_a ,pos_b);//얘만 완성하면됨
	}
}
