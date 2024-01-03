/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:22 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 22:02:10 by junhylee         ###   ########.fr       */
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
