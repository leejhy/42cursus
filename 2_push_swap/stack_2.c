/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:22 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 21:08:51 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *head)
{
	t_stack	*node;
	int		cnt;

	node = head;
	cnt = 0;
	while (node != NULL)
	{
		cnt += 1;
		node = node->next;
	}
	return (cnt);
}

void	ft_lstadd_front(t_stack	**head, t_stack *new)
{
	t_stack *temp;

	temp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = temp;
		temp->prev = new;
		*head = new;
	}
}

void	ft_delFirstNode(t_stack **head, t_pos **pos)
{
	t_stack	*temp;
	
	temp = *head;
	if (temp->next == NULL)
	{
		(*head) = NULL;
		(*pos)->front = NULL;
		(*pos)->rear = NULL;
	}
	else
	{
		*head = (*head)->next;//temp에 첫째 값 저장하고 head 밀기
		(*pos)->front = *head;
		(*head)->prev = NULL;
		temp->next = NULL;
	}
	if ((*pos)->size == 0)
	{
		free(*pos);
		*pos = NULL;
	}
	free(temp);
}
