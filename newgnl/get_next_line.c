/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:32:16 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/19 18:28:38 by junhylee         ###   ########.fr       */
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

char	*ft_read_line(int fd, char *buf, char **backup)
{
	char	*str;
	size_t	read_size;

	str = NULL;
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
		str = ft_freejoin(str, buf);
		if (is_nl(str) || read_size < BUFFER_SIZE)
			break ;
	}
	if (is_nl(str))
		*backup = ft_strdup(ft_strchr(str));
	return (str);
}

char	*ft_get_oneline(char *read_line)
{
	char	*rt_str;
	int		len;
	int		i;

	i = 0; 
	len = 0;
	if (!read_line)//여기서 막힘
		return (NULL);
	while (read_line[len] != '\0' && read_line[len] != '\n')
		len++;
	if (read_line[len] == '\n')
		len++;
	rt_str = malloc(sizeof(char) * (len + 1));
	if (!rt_str)
		return (NULL);
	while (read_line[i] != '\0' && i < len)
	{
		rt_str[i] = read_line[i];
		i++;
	}
	rt_str[i] = '\0';
	free(read_line);
	return (rt_str);
}

char	*get_next_line(int fd)
{
	char			*rt_str;
	char			*read_line;
	char			buf[BUFFER_SIZE + 1];
	static t_list	*head;
	//t_list			*temp_head;

	//temp_head = head;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	ft_makenode(&head, fd);
	while (head->fd != fd)
		head = head->next;
	read_line = ft_read_line(fd, buf, &(head->backup));
	if (!is_nl(read_line))//개행이 존재하지 않으면 바로리턴
		return (read_line);
	rt_str = ft_get_oneline(read_line);
	return (rt_str);
}
