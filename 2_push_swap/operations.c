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

void	pb(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_A)->size == 0)
		return ;
	(*pos_A)->size -= 1;
	ft_makeNodeB(head_B, pos_B, (*pos_A)->front->nb);
	if (head_B == NULL)
		exit(0);//?
	ft_delFirstNode(head_A, pos_A);
}

void	pa(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	
}

void	sa(t_stack *head_A, t_pos *pos)
{
	int	temp_nb;
	if (pos->size <= 1)
		return ;
	temp_nb = head_A->nb;
	head_A->nb = head_A->next->nb;
	head_A->next->nb = temp_nb;
}
void	ra(t_stack *head_A, t_pos *pos)
{//first becomes the last one
	t_stack *node;
	int	temp_nb;

	temp_nb = head_A->nb;
	node = head_A->next;
	while (node->next != NULL)
	{
		node->prev->nb = node->nb;
		node = node->next;
	}
	node->prev->nb = node->nb;
	node->nb = temp_nb;
}

void	rra(t_stack *head_A, t_pos *pos)
{//The last elements becomes the first one
	t_stack	*node;
	int	temp_nb;

	temp_nb = pos->rear->nb;
	node = pos->rear->prev;
	while (node->prev != NULL)
	{
		node->next->nb = node->nb;
		node = node->prev;
	}
	node->next->nb = node->nb;
	node->nb = temp_nb;
}
