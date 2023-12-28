/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:30 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 21:07:03 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_B)->size == 0)
		return ;
	(*pos_B)->size -= 1;
	ft_pushA(head_A, pos_A, (*pos_B)->front->nb);
	if (head_A == NULL)
		exit(0);
	ft_delFirstNode(head_B, pos_B);
	printf("pa\n");
}

void	pb(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_A)->size == 0)
		return ;
	(*pos_A)->size -= 1;
	ft_pushB(head_B, pos_B, (*pos_A)->front->nb);
	if (head_B == NULL)
		exit(0);//?
	ft_delFirstNode(head_A, pos_A);
	printf("pb\n");
}
void	ft_pushA(t_stack **head_A, t_pos **pos_A, int nb)
{
	t_stack	*newnode;
	t_stack	*last_node;
	int		cnt;

	cnt = 1;
	newnode = ft_makeNewNode(nb);
	if (!newnode)
		return ;
	ft_lstadd_front(head_A, newnode);
	last_node = *head_A;
	if (*pos_A == NULL)
		*pos_A = malloc(sizeof(t_pos));
	if (!(*pos_A))
		return ;
	while (last_node->next != NULL)
	{
		cnt += 1;
		last_node = last_node->next;
	}
	(*pos_A)->rear = last_node;
	(*pos_A)->front = *head_A;
	(*pos_A)->size = cnt;
}

void	ft_pushB(t_stack **head_B, t_pos **pos_B, int nb)
{
	t_stack	*newnode;
	t_stack	*last_node;
	int		cnt;

	cnt = 1;
	newnode = ft_makeNewNode(nb);
	if (!newnode)
		return ;
	ft_lstadd_front(head_B, newnode);
	last_node = *head_B;
	if (*pos_B == NULL)
		*pos_B = malloc(sizeof(t_pos));
	if (!(*pos_B))
		return ;
	while (last_node->next != NULL)
	{
		cnt += 1;
		last_node = last_node->next;
	}
	(*pos_B)->rear = last_node;
	(*pos_B)->front = *head_B;
	(*pos_B)->size = cnt;
}
