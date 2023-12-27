/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:22 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 20:28:32 by junhylee         ###   ########.fr       */
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
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

void	ft_delFirstNode(t_stack **head, t_pos **pos)
{
	t_stack	*temp;
	
	temp = *head;
	*head = (*head)->next;//temp에 첫째 값 저장하고 head 밀기
	(*pos)->front = *head;
	(*head)->prev = NULL;
	temp->next = NULL;
	free(temp);
}

void	ft_makeNodeB(t_stack **head_B, t_pos **pos_B, int nb)
{
	t_stack	*newnode;
	t_stack	*last_node;
	int		cnt;

	cnt = 1;
	last_node = *head_B;
	newnode = ft_makeNewNode(nb);
	if (!newnode)
		return ;
	ft_lstadd_front(head_B, newnode);
	*pos_B = malloc(sizeof(t_pos));
	if (!(*pos_B))
		return ;
	while (last_node != NULL)
	{
		cnt += 1;
		(*pos_B)->rear = last_node;
		last_node = last_node->next;
	}
	(*pos_B)->front = *head_B;
	(*pos_B)->size = cnt;
}
