/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:22 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:28:09 by junhylee         ###   ########.fr       */
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
	t_stack	*temp;

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

void	ft_del_first_node(t_stack **head, t_pos **pos)
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
		*head = (*head)->next;
		(*pos)->front = *head;
		(*head)->prev = NULL;
		temp->next = NULL;
	}
	free(temp);
}

void	sort(int *arr, int arr_cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_cnt)
	{
		j = i;
		while (j < arr_cnt)
		{
			if (i != j && arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_pos(t_pos **pos_a, t_pos **pos_b)
{
	t_pos	*temp_a;
	t_pos	*temp_b;

	*pos_a = malloc(sizeof(t_pos));
	if (!(*pos_a))
		failed_malloc();
	*pos_b = malloc(sizeof(t_pos));
	if (!(*pos_b))
		failed_malloc();
	temp_a = *pos_a;
	temp_b = *pos_b;
	temp_a->front = NULL;
	temp_b->front = NULL;
	temp_a->rear = NULL;
	temp_b->rear = NULL;
	temp_a->size = 0;
	temp_b->size = 0;
}
