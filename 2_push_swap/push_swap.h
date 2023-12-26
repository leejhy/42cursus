/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:30:10 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/23 14:56:53 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct	s_stack
{
	int				nb;
	struct	s_stack *prev;
	struct	s_stack *next;
}	t_stack;

int	*ft_parsing(int argc, char **argv);
long long	ft_atoi(const char *str);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_makeNewNode(int nb);
void	ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt);
#endif