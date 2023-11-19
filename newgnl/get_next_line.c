/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:32:16 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/19 17:07:28 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_makenode(t_list **head, int fd)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = *head;
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return ;
	newnode->fd = fd;
	newnode->backup = NULL;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else//노드가 1개이상 존재하는 상황
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		if (last_node->fd != fd) //이전 fd와 현재 fd가 다를때는 새 노드 추가
			last_node->next = newnode;
		else //이전fd와 현재 fd가 같으면 그냥 free
			free(newnode);
	}
}
void	ft_delnode(t_list **head, int fd)
{
	t_list	*del_lst;

	del_lst = *head;
	if (head == NULL || *head == NULL)
		return ;
	if (del_lst->next)
	{
		while (del_lst->next->fd != fd)
			del_lst = del_lst->next;
		free(del_lst->next->backup);
		del_lst->next->fd = 0;
		if (del_lst->next->next)
			del_lst->next = del_lst->next->next;
		free(del_lst->next);
	}
	else
	{
		del_lst->fd = 0;
		free(del_lst->backup);
		free(del_lst);
		*head = NULL;
	}
}
char	*ft_readline(int fd, char *buf, char **backup)
{
	char	*str;
	size_t	read_size;

	// read_size = BUFFER_SIZE + 1;
	if (*backup)
	{
		str = ft_strdup(*backup);
		free(*backup);
	}
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size == 0)
			break ;
		str = ft_strjoin(str, buf);
		if (is_nl(str))
			break ;
	}
	if (is_nl(str))
		*backup = ft_strdup(ft_strchr(str));
	return (str);
}

char	*get_next_line(int fd)
{
	char			*rt_str;
	char			buf[BUFFER_SIZE + 1];
	static t_list	*head;

	ft_makenode(&head, fd);
	rt_str = ft_read_line(fd, buf, &(head->backup));
	
	return (rt_str);
}
