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

char	**make_heredoc(int heredoc_cnt, int *heredoc_fd)
{
	char	*temp_name;
	char	**doc_name;
	int	i;

	i = 0;
	doc_name = malloc(sizeof(char *) * (heredoc_cnt + 1));
	while (i < heredoc_cnt)
	{//name 만드는 부분 함수로 빼자
		if (i < 10)
		{
			temp_name = malloc(sizeof(char) * 2);//숫자 1개, 널
			temp_name[0] = i + '0';
			temp_name[1] = '\0';
		}
		else
		{
			temp_name = malloc(sizeof(char) * 3);
			temp_name[0] = '1';
			temp_name[1] = (i % 10) + '0';
			temp_name[2] = '\0';
		}
		doc_name[i] = ft_strjoin("/tmp/here_doc", temp_name);//i번째에 이름넣기
		free(temp_name);
		heredoc_fd[i] = open(doc_name[i], O_TRUNC | O_CREAT | O_RDWR, 0666);
		i++;
	}
	doc_name[i] = NULL;
	return (doc_name);
}

int	main(void)
{
	t_list	*head;
	int		*heredoc_fd;
	char	**doc_name;
	int		cnt;
	
	head = set_list(&cnt);//테스트 리스트 만들기
	heredoc_fd = malloc(sizeof(int) * cnt);//heredoc 개수만큼 말록
	doc_name = make_heredoc(cnt, heredoc_fd);
}
