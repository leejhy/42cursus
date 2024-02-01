#include "minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	clear_list(t_list *head)
{
	t_list *del_lst;

	while (head)
	{
		del_lst = head;
		head = head->next;
		free(del_lst);
	}
}

char	*make_doc_name(int nb)
{
	char	*doc_name;
	char	*doc_nb;
	int		fd;

	if (nb < 10)
	{
		doc_nb = malloc(sizeof(char) * 2);//숫자 1개, 널
		doc_nb[0] = nb + '0';
		doc_nb[1] = '\0';
	}
	else
	{
		doc_nb = malloc(sizeof(char) * 3);
		doc_nb[0] = '1';
		doc_nb[1] = (nb % 10) + '0';
		doc_nb[2] = '\0';
	}
	// doc_name[i] = ft_strjoin("/tmp/here_doc", temp_name);//i번째에 이름넣기
	doc_name = ft_strjoin("./here_doc/", doc_nb);//tmp로 바꾸기
	free(doc_nb);
	return (doc_name);
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}