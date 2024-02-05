#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>//directory
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <term.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>

typedef struct s_list
{
	int				here_doc;
	struct s_list	*next;
}	t_list;

typedef struct s_token
{
	int		type;
	char	*value;
	char	*exp_value;
	int		is_ambiguous;
}	t_token;

typedef struct s_cmd
{
	t_list			*redirect;// 얘의 content가 t_token구조체를 가지고있음
	t_list			*simple_cmd;
	int				next_pipe;
}	t_cmd;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

//here_doc.c
char	*ft_strjoin(const char *s1, const char *s2);
t_list	*make_list(void);
t_list	*set_list(int *cnt);
char	**run_heredoc(int heredoc_cnt);

//here_doc_utils.c
void	clear_list(t_list *head);
char	*make_doc_name(int nb);
pid_t	fork_pid(void);
size_t	ft_strlen(char *str);
#endif