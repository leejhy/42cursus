/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:50:34 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/04 20:12:34 by junhylee         ###   ########.fr       */
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
	j = 0;
	while (j < ro_a)
	{
		rra(pos_a);// ra한만큼 rra;
		j++;
	}
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
	j = 0;
	while (j < ro_a)
	{
		rra(pos_a);// ra한만큼 rra;
		j++;
	}
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
	j = 0;
	while (j < ro_a + 1)
	{
		ra(pos_a);// rra + 1 만큼 ra;
		j++;
	}
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
	j = 0;
	while (j < ro_a + 1)
	{
		ra(pos_a);// rra + 1 만큼 ra;
		j++;
	}
}

void	ft_ra_pa(t_pos *pos_a, t_pos *pos_b, int ro_b, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < ro_b)
		{
			rrb(pos_b);
			i++;
		}
	}
	else
	{
		while (i < ro_b)
		{
			rb(pos_b);
			i++;
		}
	}
	pa(pos_a, pos_b);
}
