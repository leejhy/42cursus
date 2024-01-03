/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:30:10 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 22:03:41 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos
{
	int		size;
	t_stack	*front;
	t_stack	*rear;
}	t_pos;

//stack.c
t_stack	*ft_make_newnode(int nb);
void	ft_lstadd_back(t_stack **head, t_stack *new);
void	ft_lstclear(t_stack **lst);
void	ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt);
void	set_pos(t_pos **pos, t_stack **head);
//stack_utils.c
int		ft_lstsize(t_stack *head);
void	ft_lstadd_front(t_stack	**head, t_stack *new);
void	ft_del_first_node(t_stack **head, t_pos **pos);
void	sort(int *arr, int arr_cnt);
//swap.c
void	swap(t_stack *head, t_pos *pos);
void	sa(t_pos **pos_a);
void	sb(t_pos **pos_b);
void	ss(t_pos **pos_a, t_pos **pos_b);
//rotate.c
void	rotate(t_stack *head, t_pos *pos);
void	ra(t_pos **pos_a);
void	rb(t_pos **pos_b);
void	rr(t_pos **pos_a, t_pos **pos_b);
//r_rotate.c
void	r_rotate(t_stack *head, t_pos *pos);
void	rra(t_pos **pos_a);
void	rrb(t_pos **pos_b);
void	rrr(t_pos **pos_a, t_pos **pos_b);
//push.c
void	pa(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
void	pb(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
void	ft_push_a(t_stack **a, t_pos **pos_a, int nb);
void	ft_push_b(t_stack **b, t_pos **pos_b, int nb);
//parsing.c
long long	ft_atoi(const char *str);
int			is_duplicate(int *arr, int arr_cnt);
int			*ft_parsing(int argc, char **argv);
//hard_sort.c
void	ft_hard_sort(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
void	sort_two_args(t_pos **pos_A);
void	sort_three_args(t_pos **pos_A);
void	sort_four_args(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
void	sort_five_args(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
//hard_sort_utils.c
int		ft_nbcnt(t_stack *head_A, t_stack *head_B);
int		find_zero(t_stack *head_A);
int		find_one(t_stack *head_A);
int		is_sorted(t_stack **head_A);
void	ft_select_pb(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
//main.c
int		is_errors(int argc);
void	intToidx(t_stack **head_A, int *arr, int arr_cnt);
void	push_swap(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
int		main(int argc, char **argv);
//greedy.c
void	greedy(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
void	ft_find_optimal(t_pos **pos_A, t_pos **pos_B);
void	set_pivot(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b);
//greedy_utils.c
int		*ft_case_arr(t_pos **pos_a, t_pos **pos_b, int *arr);

#endif