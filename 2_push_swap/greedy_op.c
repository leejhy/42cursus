/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:50:34 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/05 22:00:26 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ro_b)//ro_b = min_b_idx
	{
		rb(pos_b);
		i++;
	}
	while (j < ro_a)//ro_b랑 ro_a겹치는 만큼 rr;
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
	while (i < ro_b)//ro_b = min_b_idx
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
	while (i < ro_b)//ro_b = min_b_idx
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

	i = 0;
	j = 0;
	while (i < ro_b)//ro_b = min_b_idx
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
