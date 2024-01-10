/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:40:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:52:12 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_rotate(t_pos *pos_a, t_pos *pos_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
	{
		ra(pos_a);
		return (1);
	}
	if (ft_strcmp(str, "rb\n") == 0)
	{
		rb(pos_b);
		return (1);
	}
	if (ft_strcmp(str, "rr\n") == 0)
	{
		rr(pos_a, pos_b);
		return (1);
	}
	return (0);
}

int	ft_check_r_rotate(t_pos *pos_a, t_pos *pos_b, char *str)
{
	if (ft_strcmp(str, "rra\n") == 0)
	{
		rra(pos_a);
		return (1);
	}
	if (ft_strcmp(str, "rrb\n") == 0)
	{
		rrb(pos_b);
		return (1);
	}
	if (ft_strcmp(str, "rrr\n") == 0)
	{
		rrr(pos_a, pos_b);
		return (1);
	}
	return (0);
}

int	ft_check_swap(t_pos *pos_a, t_pos *pos_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
	{
		sa(pos_a);
		return (1);
	}
	if (ft_strcmp(str, "sb\n") == 0)
	{
		sb(pos_b);
		return (1);
	}
	if (ft_strcmp(str, "ss\n") == 0)
	{
		ss(pos_a, pos_b);
		return (1);
	}
	return (0);
}

int	ft_check_push(t_pos *pos_a, t_pos *pos_b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
	{
		pa(pos_a, pos_b);
		return (1);
	}
	if (ft_strcmp(str, "pb\n") == 0)
	{
		pb(pos_a, pos_b);
		return (1);
	}
	return (0);
}

void	check_sorted(t_stack *head_a, t_pos *pos_b)
{
	if (is_sorted(head_a) && pos_b->size == 0)
	{
		write(1, "OK\n", 3);
		return ;
	}
	write(1, "KO\n", 3);
}
