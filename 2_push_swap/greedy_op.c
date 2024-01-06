/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:50:34 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 15:46:09 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a)
{
	int	i;
	int	j;
	int k;

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
