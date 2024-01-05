/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/05 22:10:22 by junhylee         ###   ########.fr       */
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
	// t_stack *temp;
	// temp = pos_b->front;
	// printf("stack a %d\n", pos_a->front->nb);
	// printf("stack a %d\n", pos_a->front->next->nb);
	// printf("stack a %d\n", pos_a->front->next->next->nb);
	// while (temp != NULL)
	// {
	// 	printf("stack b : %d\n", temp->nb);
	// 	temp = temp->next;
	// }
	// printf("push done\n");
}

void	ft_find_optimal(t_pos *pos_a, t_pos *pos_b)
{
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
	arr = ft_make_case_arr(pos_a, pos_b, arr);//수정해야함
	min_b = ft_min_b(arr, pos_b->size, pos_a->size / 2);
	//그냥 이 이후로, min_b 만큼 rb or rrb
	//arr[min_b] 만큼 ra, rra 하면됨
	// if (pos_b->size == 1)
	// {
	// 	printf("main arr %d\n", arr[0]);
	// 	printf("main min_b %d\n", min_b);
	// }
	if (min_b > pos_b->size / 2)
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
	if (flag_rrb == 0 && flag_rra == 0)//rb, ra
		ft_rb_ra(pos_a, pos_b, min_b, arr[min_b]);
	if (flag_rrb == 1 && flag_rra == 0)//rb, ra
		ft_rrb_ra(pos_a, pos_b, rrb_cnt, arr[min_b]);
	if (flag_rrb == 0 && flag_rra == 1)//rb, ra
		ft_rb_rra(pos_a, pos_b, min_b, rra_cnt);
	if (flag_rrb == 1 && flag_rra == 1)//rb, ra
		ft_rrb_rra(pos_a, pos_b, rrb_cnt, rra_cnt);
	//optimal 찾고 그 최적해의 값을 알아내야함
}

void	greedy(t_pos *pos_a, t_pos *pos_b)
{
	set_pivot(pos_a, pos_b);//OK
	sort_three_args(pos_a);//ok
	// printf("stack a %d\n", pos_a->front->nb);
	// printf("stack a %d\n", pos_a->front->next->nb);
	// printf("stack a %d\n", pos_a->front->next->next->nb);
	while (pos_b->size != 0)
		ft_find_optimal(pos_a ,pos_b);//얘만 완성하면됨
	// printf ("last_sort\n");
	ft_last_sort(pos_a);//ok
}
