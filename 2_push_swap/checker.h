/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:11:48 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:52:00 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

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

void	ft_only_space(char *str);
void	init_pos(t_pos **pos_a, t_pos **pos_b);
char	*parsing(int argc, char **argv);
size_t	ft_nb_cnt(char *str, char sep);
int		*str_to_nbarr(char *str, size_t nb_cnt);
void	set_pos_a(t_pos **pos);
void	int_to_idx(t_stack **head_a, int *arr, int arr_cnt);
void	ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt);
void	ft_lstclear(t_stack **lst);
void	ft_frees(int *nb_arr, char *str, t_pos *pos_a, t_pos *pos_b);
int		ft_check_op(t_pos *pos_a, t_pos *pos_b, char *str);
int		ft_read_op(t_pos *pos_a, t_pos *pos_b);
int		is_nl(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_rotate(t_pos *pos_a, t_pos *pos_b, char *str);
int		ft_check_r_rotate(t_pos *pos_a, t_pos *pos_b, char *str);
int		ft_check_swap(t_pos *pos_a, t_pos *pos_b, char *str);
int		ft_check_push(t_pos *pos_a, t_pos *pos_b, char *str);
void	ft_error(void);
void	check_sorted(t_stack *head_a, t_pos *pos_b);
int		is_sorted(t_stack *head_a);
void	swap(t_stack *head, t_pos *pos);
void	sa(t_pos *pos_a);
void	sb(t_pos *pos_b);
void	ss(t_pos *pos_a, t_pos *pos_b);
void	rotate(t_stack *head, t_pos *pos);
void	ra(t_pos *pos_a);
void	rb(t_pos *pos_b);
void	rr(t_pos *pos_a, t_pos *pos_b);
void	r_rotate(t_stack *head, t_pos *pos);
void	rra(t_pos *pos_a);
void	rrb(t_pos *pos_b);
void	rrr(t_pos *pos_a, t_pos *pos_b);
void	pa(t_pos *pos_a, t_pos *pos_b);
void	pb(t_pos *pos_a, t_pos *pos_b);
void	ft_push_a(t_stack *a, t_pos *pos_a, int nb);
void	ft_push_b(t_stack *b, t_pos *pos_b, int nb);

#endif