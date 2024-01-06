/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:50:34 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:50:36 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_greedy_op(int *arr, int min_b, t_pos *pos_a, t_pos *pos_b)
{
	int	flag_rra;
	int	flag_rrb;
	int	rrb_cnt;
	int	rra_cnt;

	flag_rra = 0;
	flag_rrb = 0;
	if (arr[min_b] < 0)
		rra_cnt = ft_op_rra_count(arr, min_b, pos_a->size, &flag_rra);
	if (min_b > pos_b->size / 2)
		rrb_cnt = ft_op_rrb_count(min_b, pos_b->size, &flag_rrb);
	if (flag_rrb == 0 && flag_rra == 0)
		ft_rb_ra(pos_a, pos_b, min_b, arr[min_b]);
	if (flag_rrb == 1 && flag_rra == 0)
		ft_rrb_ra(pos_a, pos_b, rrb_cnt, arr[min_b]);
	if (flag_rrb == 0 && flag_rra == 1)
		ft_rb_rra(pos_a, pos_b, min_b, rra_cnt);
	if (flag_rrb == 1 && flag_rra == 1)
		ft_rrb_rra(pos_a, pos_b, rrb_cnt, rra_cnt);
	free(arr);
}

void	ft_rb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < ro_a && k < ro_b)
	{
		rr(pos_a, pos_b);
		k++;
	}
	i = k;
	j = k;
	while (ro_b > 0 && i < ro_b)
	{
		rb(pos_b);
		i++;
	}
	while (ro_a > 0 && j < ro_a)
	{
		ra(pos_a);
		j++;
	}
	pa(pos_a, pos_b);
}

void	ft_rrb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ro_b)
	{
		rrb(pos_b);
		i++;
	}
	while (j < ro_a)
	{
		ra(pos_a);
		j++;
	}
	pa(pos_a, pos_b);
}

void	ft_rb_rra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ro_b)
	{
		rb(pos_b);
		i++;
	}
	while (j < ro_a)
	{
		rra(pos_a);
		j++;
	}
	pa(pos_a, pos_b);
}

void	ft_rrb_rra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < ro_a && k < ro_b)
	{
		rrr(pos_a, pos_b);
		k++;
	}
	i = k;
	j = k;
	while (i < ro_b)
	{
		rrb(pos_b);
		i++;
	}
	while (j < ro_a)
	{
		rra(pos_a);
		j++;
	}
	pa(pos_a, pos_b);
}
