/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/14 21:37:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fd_lst(t_list **head, int fd)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = *head;
	printf("last %p *head %p head %p\n", last_node, *head, head);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return ;
	newnode->fd = fd;
	newnode->idx = 0;
	newnode->buf = NULL;
	newnode->next = NULL;
	printf("%d %d %s\n",newnode->fd, newnode->idx, newnode->buf);
	if (*head == NULL)
	{
		*head = newnode;
		printf("%d %d %s\n",(*head)->fd, (*head)->idx, (*head)->buf);
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
	printf("work\n");
}

char	*ft_read_line(int fd)
{
	char			*buf;
	static char		*str;
	size_t			read_size;
	int				flag;

	flag = 0;
	str = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (flag == 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		while (read_size <= BUFFER_SIZE)
			buf[read_size++] = '\0';
		read_size = ft_withlf(buf, &flag);
		str = get_str(str, buf, read_size);
		if (!str)
			break ;
		if (read_size < BUFFER_SIZE) //이거 위에 if랑 합쳐도 되지않을까
			break ;
	}
	free(buf);
	return (str);
}

char	*ft_getoneline(char *str, int *idx)
{
	int		i;
	int		len;
	char	*oneline;

	i = 0;
	len = *idx;
	while (str[len])//널처ㅣㄹ
		len++;
	oneline = malloc(sizeof(char) * len + 1);
	if (!oneline)
		return (NULL);
	while (str[*idx])//널처리
	{
		oneline[i] = str[*idx];
		i++;
		if (str[*idx] == '\n')
			break;
		(*idx)++;
	}
	oneline[i] = '\0';
	return (oneline);
}

char	*get_next_line(int fd)
{
	char			*str;
	static t_list	*head;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	head = NULL;//이게맞나
	ft_fd_lst(&head, fd);
	while (head->fd != fd)
		head = head->next;
	if (head->buf)//head->buf안에 아무것도 없으면 readline
		head->buf = ft_read_line(fd);
	str = ft_getoneline(head->buf, &(head->idx));//readline을 하건 안하건 호출했으면 한줄 리턴해야함 없으면 NULL
	if (!str)
		return (NULL);
	return (str);
}
