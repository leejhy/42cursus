/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:30 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 22:03:53 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_b->size == 0)
		return ;
	pos_b->size -= 1;
	ft_push_a((pos_a->front), pos_a, pos_b->front->nb);
	if (pos_a == NULL)
		exit(0);
	ft_del_first_node(&(pos_b->front), &pos_b);
	printf("pa\n");
}

void	pb(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size == 0)
		return ;
	pos_a->size -= 1;
	ft_push_b(pos_b->front, pos_b, pos_a->front->nb);
	if (pos_b->front == NULL)
		exit(0);//?
	ft_del_first_node(&(pos_a->front), &pos_a);
	printf("pb\n");
}

void	ft_push_a(t_stack *a, t_pos *pos_a, int nb)
{
	t_stack	*newnode;
	t_stack	*last_node;
	int		cnt;

	cnt = 1;
	newnode = ft_make_newnode(nb);
	if (!newnode)
		return ;
	ft_lstadd_front(&a, newnode);
	last_node = a;
	// if (*pos_a == NULL)
	// 	*pos_a = malloc(sizeof(t_pos));
	// if (!(*pos_a))
	// 	return ;
	while (last_node->next != NULL)
	{
		cnt += 1;
		last_node = last_node->next;
	}
	pos_a->rear = last_node;
	pos_a->front = a;
	pos_a->size = cnt;
}

void	ft_push_b(t_stack *b, t_pos *pos_b, int nb)
{
	t_stack	*newnode;
	t_stack	*last_node;
	int		cnt;

	cnt = 1;
	newnode = ft_make_newnode(nb);
	if (!newnode)
		return ;
	ft_lstadd_front(&b, newnode);
	last_node = b;
	// if (*pos_b == NULL)
	// 	*pos_b = malloc(sizeof(t_pos));
	// if (!(*pos_b))
	// 	return ;
	while (last_node->next != NULL)
	{
		cnt += 1;
		last_node = last_node->next;
	}
	pos_b->rear = last_node;
	pos_b->front = b;
	pos_b->size = cnt;
}
