/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:59:48 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/31 15:59:48 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	r_rotate(t_stack *head, t_pos *pos)
{//The last elements becomes the first one
	t_stack	*node;
	int	temp_nb;
	
	if (head == NULL)
		return ;
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

void	rra(t_stack **head_A, t_pos **pos_A)
{
	r_rotate(*head_A, *pos_A);
	printf("rra\n");
}

void	rrb(t_stack **head_B, t_pos **pos_B)
{
	r_rotate(*head_B, *pos_B);
	printf("rrb\n");
}

void rrr(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	r_rotate(*head_A, *pos_A);
	r_rotate(*head_B, *pos_B);
	printf("rrr\n");
}