/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:30:10 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 20:16:24 by junhylee         ###   ########.fr       */
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

typedef struct	s_pos
{
	int	size;
	t_stack	*front;
	t_stack	*rear;
}	t_pos;
void	sa(t_stack *head_A, t_pos *pos_A);
void	ra(t_stack *head_A, t_pos *pos_A);
void	rra(t_stack *head_A, t_pos *pos_A);
void	set_pos(t_pos **pos, t_stack **head);
int		ft_lstsize(t_stack *head);
int	*ft_parsing(int argc, char **argv);
long long	ft_atoi(const char *str);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_makeNewNode(int nb);
void	ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt);
int	isDuplicate(int *arr, int arr_cnt);
void	sort(int *arr, int arr_cnt);
void	intToidx(t_stack **head_A, int *arr, int arr_cnt);
void	ft_pushB(t_stack **head_B, t_pos **pos_B, int nb);
void	ft_delFirstNode(t_stack **head, t_pos **pos);
void	ft_lstadd_front(t_stack	**head, t_stack *new);
void	pb(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B);
void	ft_pushA(t_stack **head_A, t_pos **pos_A, int nb);
void	pa(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B);

#endif