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
		*backup = NULL;
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

char	*ft_get_oneline(char *read_line, int idx)
{
	char	*rt_str;
	int		i;

	i = 0; 
	if (!read_line)//여기서 막힘
		return (NULL);
	if (read_line[idx] == '\n')
		idx++;
	rt_str = malloc(sizeof(char) * (idx + 1));
	if (!rt_str)
		return (NULL);
	while (i < idx)
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
	int				idx;
	t_list			*temp_head;

	idx = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)//close된 fd들어오면 노드지우기
	{
		if (read(fd, NULL, 0) == -1)
			ft_delnode(&head, fd);
		return (NULL);
	}
	ft_makenode(&head, fd);
	temp_head = head;
	while (head->fd != fd)
		head = head->next;
	read_line = ft_read_line(head->fd, buf, &(head->backup));
	if (!is_nl(read_line))//개행이 존재하지 않으면 바로리턴
		return (read_line);
	while (read_line[idx] != '\n')//이거 지우고 get_oneline에서 알아서 길이재
		idx++;
	rt_str = ft_get_oneline(read_line, idx);
	head = temp_head;
	return (rt_str);
}
