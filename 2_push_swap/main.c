/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:27:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_swap(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size == 0)
		return ;
	if (is_sorted(pos_a->front))
		return ;
	if (pos_a->size <= 3)
		ft_hard_sort(pos_a);
	else
		greedy(pos_a, pos_b);
}

int	main(int argc, char **argv)
{
	int			*nb_arr;
	char		*str;
	size_t		nb_cnt;
	t_pos		*pos_a;
	t_pos		*pos_b;

	init_pos(&pos_a, &pos_b);
	if (argc <= 1)
		ft_error();
	str = parsing(argc, argv);
	nb_cnt = ft_nb_cnt(str, ' ');
	nb_arr = str_to_nbarr(str, nb_cnt);
	ft_makestack(&(pos_a->front), nb_arr, nb_cnt);
	set_pos_a(&pos_a);
	int_to_idx(&(pos_a->front), nb_arr, nb_cnt);
	push_swap(pos_a, pos_b);
	ft_frees(nb_arr, str, pos_a, pos_b);
	return (0);
}
