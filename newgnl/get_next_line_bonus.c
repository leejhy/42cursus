/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:49:33 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/20 22:31:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		*head = newnode;
	else//노드가 1개이상 존재하는 상황
	{
		while (last_node->next != NULL)
		{
			if (last_node->fd == fd) //이전 fd와 현재 fd가 다를때는 새 노드 추가
			{
				free(newnode);
				return ;//들어온 fd와 같은 fd의 노드가 존재하면 free 후 종료
			}
			last_node = last_node->next;
		}
		last_node->next = newnode;//중복노드 존재 안하면 그냥 마지막 노드로 밀린거니까 연결
	}
}

void	ft_delnode(t_list **head, int fd)
{
	t_list	*del_lst;
	t_list	*temp;

	temp = *head;
	del_lst = *head;
	if (head == NULL || *head == NULL)
		return ;
	if (del_lst->fd == fd)
	{
		*head = del_lst->next;
		free(del_lst->backup);
		// del_lst->backup = NULL;
		free(del_lst);
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
	// del_lst->backup = NULL;
	free(del_lst);
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
		if (!str)
			return (NULL);
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

	len = 0; 
	i = 0; 
	if (!read_line)//여기서 막힘
		return (NULL);
	while (read_line[len] != '\n')
		len++;
	len++;
	rt_str = malloc(sizeof(char) * (len + 1));
	if (!rt_str)
		return (NULL);
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
	char			buf[BUFFER_SIZE + 1];
	static t_list	*head;
	t_list			*temp_head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)//close된 fd들어오면 노드지우기
	{
		ft_delnode(&head, fd);
		return (NULL);
	}
	ft_makenode(&head, fd);
	temp_head = head;
	while (temp_head->fd != fd)
		temp_head = temp_head->next;
	read_line = ft_read_line(temp_head->fd, buf, &(temp_head->backup));
	if (!read_line || !is_nl(read_line))
		ft_delnode(&head, fd);
	if (!is_nl(read_line))//개행이 존재하지 않으면 바로리턴
	{
		ft_delnode(&head, fd);
		return (read_line);
	}
	rt_str = ft_get_oneline(read_line);
	return (rt_str);
}
