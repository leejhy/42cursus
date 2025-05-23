/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:30:10 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:28:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void		ft_only_space(char *str);
long long	ft_atoll(const char *str);
t_stack		*ft_make_newnode(int nb);
void		ft_lstadd_back(t_stack **head, t_stack *new);
void		ft_lstclear(t_stack **lst);
void		ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt);
void		set_pos_a(t_pos **pos);
int			ft_lstsize(t_stack *head);
void		ft_lstadd_front(t_stack	**head, t_stack *new);
void		ft_del_first_node(t_stack **head, t_pos **pos);
void		sort(int *arr, int arr_cnt);
void		swap(t_stack *head, t_pos *pos);
void		sa(t_pos *pos_a);
void		sb(t_pos *pos_b);
void		ss(t_pos *pos_a, t_pos *pos_b);
void		rotate(t_stack *head, t_pos *pos);
void		ra(t_pos *pos_a);
void		rb(t_pos *pos_b);
void		rr(t_pos *pos_a, t_pos *pos_b);
void		r_rotate(t_stack *head, t_pos *pos);
void		rra(t_pos *pos_a);
void		rrb(t_pos *pos_b);
void		rrr(t_pos *pos_a, t_pos *pos_b);
void		pa(t_pos *pos_a, t_pos *pos_b);
void		pb(t_pos *pos_a, t_pos *pos_b);
void		ft_push_a(t_stack *a, t_pos *pos_a, int nb);
void		ft_push_b(t_stack *b, t_pos *pos_b, int nb);
void		is_duplicate(int *arr, size_t arr_max);
char		*parsing(int argc, char **argv);
char		*ft_strjoin(char **argv, size_t sep, size_t arg_cnt, size_t len);
int			*str_to_nbarr(char *str, size_t nb_cnt);
size_t		ft_nb_cnt(char *str, char sep);
size_t		ft_arg_len(char **argv, size_t arg_cnt);
void		ft_strcat(char *dest, char *str_arg, size_t *idx);
void		ft_hard_sort(t_pos *pos_a);
void		sort_two_args(t_pos *pos_a);
void		sort_three_args(t_pos *pos_a);
int			find_zero(t_stack *a);
int			is_sorted(t_stack *head_a);
void		int_to_idx(t_stack **head_a, int *arr, int arr_cnt);
void		push_swap(t_pos *pos_a, t_pos *pos_b);
void		init_pos(t_pos **pos_a, t_pos **pos_b);
int			main(int argc, char **argv);
void		greedy(t_pos *pos_a, t_pos *pos_b);
void		ft_find_optimal(t_pos *pos_A, t_pos *pos_B);
void		set_pivot(t_pos *pos_a, t_pos *pos_b);
void		do_greedy_op(int *arr, int min_b, t_pos *pos_a, t_pos *pos_b);
void		ft_rb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a);
void		ft_rrb_ra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a);
void		ft_rb_rra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a);
void		ft_rrb_rra(t_pos *pos_a, t_pos *pos_b, int ro_b, int ro_a);
int			ft_op_rra_count(int *arr, int idx, int a_size, int *flag_rra);
int			ft_op_rrb_count(int min_b, int b_size, int *flag_rrb);
int			*ft_make_case_arr(t_pos *pos_a, t_pos *pos_b, int *arr);
int			ft_min_b(int *arr, int arr_size, int middle_a);
int			ft_rrb_cnt(int i, int *arr, int arr_size, int a_size);
int			ft_rrb_cnt(int i, int *arr, int arr_size, int a_size);
void		ft_last_sort(t_pos *pos_a);
int			find_a_min(int *arr, int b_idx, int b_nb, t_pos *pos_a);
int			find_a_max(int *arr, int b_idx, int b_nb, t_pos *pos_a);
void		ft_cnt_mid(int *arr, int idx, int b_nb, t_pos *pos_a);
void		ft_error(void);
void		failed_malloc(void);
void		ft_frees(int *nb_arr, char *str, t_pos *pos_a, t_pos *pos_b);

#endif