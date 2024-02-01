/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:05:06 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/31 20:44:01 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - (s1_len + s2_len));
}

t_list	*make_list(void)
{
	t_list	*head;
	t_list	*temp;
	t_list	*newnode;
	int	i = 0;

	head = NULL;
	while (i < 16)
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
		if (*cnt > 16)
			exit(1);//here_doc 12개 이상이면 error
		temp = temp->next;
	}
	return (head);
}

char	*run_heredoc(int heredoc_cnt)
{
	pid_t	pid;
	char	*doc_name;
	char	*input;
	int		fd;
	int		i;

	i = 0;
	while (i < heredoc_cnt)
	{//name 만드는 부분 함수로 빼자
		printf("=1111\n");
		doc_name = make_doc_name(i);
		pid = fork_pid();
		if (pid == 0)
		{
			printf("=222\n");
			fd = open(doc_name, O_TRUNC | O_CREAT | O_RDWR, 0666);
			dup2(fd, 1);//input을 fd로
			while (1)
			{
				printf("=222\n");
				input = readline("> ");
				// if (strncmp(input, "limiter", ft_strlen(limiter)) == 0)//limiter 확이인
				if (strncmp(input, "lim", 4) == 0)//limiter 확이인
					break ;
				write(fd, input, ft_strlen(input));
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, 0, 0);
			if (i != heredoc_cnt - 1)
			{
				close(fd);
				unlink(doc_name);
				free(doc_name);
			}
			// else// i == heredoc_cnt -1 (마지막 )
				//doc_name, fd 리턴시켜야함
		}
		i++;
	}
	return (doc_name);
}

int	main(void)
{
	t_list	*head;
	char	*str;
	int		cnt;
	int		i;

	i = 0;
	head = set_list(&cnt);//테스트 리스트 만들기
	str = run_heredoc(cnt);
	clear_list(head);
}
