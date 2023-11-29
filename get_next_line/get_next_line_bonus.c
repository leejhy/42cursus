/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:49:33 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/26 10:56:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_makenode(t_list **head, int fd)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = *head;
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	newnode->fd = fd;
	newnode->backup = NULL;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		while (last_node->fd != fd && last_node->next != NULL)
			last_node = last_node->next;
		if (last_node->fd == fd)
			free(newnode);
		else
			last_node->next = newnode;
	}
	return (1);
}

void	ft_delnode(t_list **head, int fd)
{
	t_list	*del_lst;
	t_list	*temp;

	del_lst = *head;
	if (head == NULL || *head == NULL)
		return ;
	if (del_lst->fd == fd)
	{
		*head = del_lst->next;
		free(del_lst->backup);
		del_lst->backup = NULL;
		free(del_lst);
		del_lst = NULL;
		return ;
	}
	while (del_lst->next != NULL && del_lst->fd != fd)
	{
		temp = del_lst;
		del_lst = del_lst->next;
	}
	if (del_lst == NULL || del_lst->fd != fd)
		return ;
	temp->next = del_lst->next;
	free(del_lst->backup);
	free(del_lst);
}

char	*ft_read_line(int fd, char *buf, char **backup)
{
	char	*str;
	ssize_t	read_size;

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
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		str = ft_strjoin(str, buf, read_size);
		if (!str || is_nl(str))
			break ;
	}
	free(buf);
	if (str && is_nl(str))
		*backup = ft_strdup(ft_strchr(str));
	return (str);
}

char	*ft_get_oneline(char *read_line)
{
	char	*rt_str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!read_line)
		return (NULL);
	while (read_line[len] != '\n')
		len++;
	len++;
	rt_str = malloc(sizeof(char) * (len + 1));
	if (!rt_str)
	{
		free(read_line);
		return (NULL);
	}
	while (i < len)
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
	static t_list	*head;
	char			*buf;
	t_list			*temp_head;

	if (ft_error(fd, &head) == 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (ft_makenode(&head, fd) == 0)
		return (NULL);
	temp_head = head;
	while (temp_head && temp_head->fd != fd)
		temp_head = temp_head->next;
	read_line = ft_read_line(temp_head->fd, buf, &(temp_head->backup));
	if (!read_line || !is_nl(read_line))
	{
		ft_delnode(&head, fd);
		return (read_line);
	}
	rt_str = ft_get_oneline(read_line);
	return (rt_str);
}
