/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:49:30 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/31 21:34:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_make_newnode(int nb)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->nb = nb;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	ft_lstadd_back(t_stack **head, t_stack *new)
{
	t_stack	*last_node;

	last_node = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last_node->next != NULL)
		{
			last_node->next->prev = last_node;
			last_node = last_node->next;
		}
		last_node->next = new;
		last_node->next->prev = last_node;
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*del_lst;
	t_stack	*head;

	head = *lst;
	while (head != NULL)
	{
		del_lst = head;
		head = head->next;
		free(del_lst);
	}
}

void	ft_makestack(t_stack **head_a, int *nb_arr, int arr_cnt)
{
	t_stack	*new_node;
	int		i;

	if (nb_arr == NULL)
		return ;
	i = 0;
	while (i < arr_cnt)
	{
		new_node = ft_make_newnode(nb_arr[i]);
		if (!new_node)
		{
			ft_lstclear(head_a);
			failed_malloc();
		}
		ft_lstadd_back(head_a, new_node);
		i++;
	}
	sort(nb_arr, arr_cnt);
}

void	set_pos_a(t_pos **pos)
{
	t_stack	*temp_node;

	temp_node = (*pos)->front;
	if (temp_node == NULL)
		return ;
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	(*pos)->rear = temp_node;
	(*pos)->size = ft_lstsize((*pos)->front);
}
