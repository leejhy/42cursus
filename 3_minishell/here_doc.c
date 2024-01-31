/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/30 21:40:57 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*make_list(void)
{
	t_list	*head;
	t_list	*temp;
	t_list	*newnode;
	int	i = 0;

	head = NULL;
	while (i < 12)
	{
		newnode = malloc(sizeof(t_list));
		if (!newnode)
			exit(1);
		newnode->here_doc = 1;
		newnode->next = NULL;
		if (head == NULL)
			head = newnode;
		else
		{
			temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = newnode;
		}
		i++;
	}
	temp->here_doc = 0;
	return (head);
}

t_list	*set_list(int *cnt)
{
	t_list	*head;
	t_list	*temp;

	*cnt = 0;
	head = make_list();
	temp = head;
	while (temp)
	{
		if (temp->here_doc == 1)
			*cnt += 1;
		if (cnt > 12)
			exit(1);//here_doc 12개 이상이면 error
		temp = temp->next;
	}
	return (head);
}

int	main(void)
{
	t_list	*head;
	int		cnt;
	
	head = set_list(&cnt);//테스트 리스트 만들기
	set_
}