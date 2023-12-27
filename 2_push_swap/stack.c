/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:49:30 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 18:37:08 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_makeNewNode(int nb)
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
	t_stack	*prev_temp;
	
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

	// if (lst == NULL)
	// 	return ;
	while ((*lst) != NULL)
	{
		del_lst = *lst;
		del_lst = del_lst->next;
		free(del_lst);
	}
}

void	ft_makestack(t_stack **head_A, int *nb_arr, int arr_cnt)
{//only for a
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < arr_cnt)
	{
		new_node = ft_makeNewNode(nb_arr[i]);
		if (!new_node)
		{
			ft_lstclear(head_A);
			*head_A = NULL;
			return ;
		}
		ft_lstadd_back(head_A, new_node);
		i++;
	}
	sort(nb_arr, arr_cnt);
}

void	set_pos(t_pos **pos, t_stack **head)
{
	t_stack *temp_node;

	*pos = malloc(sizeof(t_pos));
	if (!*pos)
		return ;
	temp_node = *head;
	(*pos)->front = *head;
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	(*pos)->rear = temp_node;
	(*pos)->size = ft_lstsize(*head);
}
