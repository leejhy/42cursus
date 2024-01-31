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

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

// void	execute_cmd(t_cmd *pa, pipe_fd);

#endif