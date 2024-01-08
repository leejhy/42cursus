/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:16:00 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 20:17:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	failed_malloc(void)
{
	exit(1);
}

void	ft_frees(int *nb_arr, char *str, t_pos *pos_a, t_pos *pos_b)
{
	free(nb_arr);
	free(str);
	ft_lstclear(&(pos_a->front));
	free(pos_a);
	free(pos_b);
}
