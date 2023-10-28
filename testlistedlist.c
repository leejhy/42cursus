/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:28:48 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/28 14:46:46 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	insert_node(t_list *head, int data)
{
	t_list	*nextnode;

	nextnode = (t_list *)malloc(sizeof(t_list));
	nextnode->content = data;
	nextnode->next = NULL;
	if (head->next == NULL)
		head->next = nextnode;
	else
		head = head->next;
		head = nextnode;
}

int	main(void)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	head->content = 0;
	head->next = NULL;
	insert_node(head, 111);
	printf("%d\n",head->content);
	head = head->next;
	printf("%d\n",head->content);
	insert_node(head, 222);
	head = head->next;
	printf("%d\n",head->content);
	insert_node(head, 333);
	head = head->next;
	printf("%d\n",head->content);
}

