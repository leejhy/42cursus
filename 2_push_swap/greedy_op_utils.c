/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_op_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:35:32 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:50:26 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_op_rra_count(int *arr, int idx, int a_size, int *flag_rra)
{
	*flag_rra = 1;
	return (a_size + arr[idx]);
}

int	ft_op_rrb_count(int min_b, int b_size, int *flag_rrb)
{
	*flag_rrb = 1;
	return (b_size - min_b);
}
