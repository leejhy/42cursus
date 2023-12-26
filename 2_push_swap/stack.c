/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:49:30 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/23 16:49:07 by junhylee         ###   ########.fr       */
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

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;
	t_stack	*prev_node;
	// if (lst == NULL)
	// 	return ;
	last_node = *lst;
	prev_node = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new;
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
{
	t_stack	*newnode;
	int		nb; //argv to int 한 값
	int		i;

	i = 0;
	while (i < arr_cnt)
	{
		newnode = ft_makeNewNode(nb_arr[i]);
		if (!newnode)
		{
			ft_lstclear(head_A);
			*head_A = NULL;
			return ;
		}
		ft_lstadd_back(head_A, newnode);
		i++;
	}
}

// void	pa(t_stack *A_stack, int nb)
// {
// 	if (A_stack == NULL)
// 		A_stack->nb = nb;
// 	else
// 	{
// 		//마지막노드 이동
// 		A_stack->nb = nb;
// 	}
// }