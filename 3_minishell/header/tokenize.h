/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:15:01 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

enum e_token_type
{
	ERROR = 0,
	INREDIRECTION,
	OUTREDIRECTION,
	HEREDOC,
	APPEND,
	PIPE,
	SIMPLECMD
};

typedef struct s_token
{
	int		type;
	char	*value;
	char	*exp_value;
	int		is_ambiguous;
}	t_token;

typedef struct s_cmd
{
	t_list			*redirect;
	t_list			*simple_cmd;
	int				next_pipe;
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
}	t_env;

typedef struct s_info
{
	t_list	*cmd;
	t_list	*env;
	int		exitcode;
}	t_info;

/* find_ambigous.c  */
void	check_ambigious(t_list *tokens, t_list *env);

/* remove_oper.c */
t_list	*merge_oper_simplecmd(t_list *tokens);

/* error_manager.c */
void	*error_manager(char *prompt, char *str, int exitcode);
void	*print_error(char *prompt, char *str);


/* check_valid_syntax.c */
int		is_valid_syntax(t_list *tokens);

/* re_tokenize.c */
t_list	*re_tokenize(t_list *tokens);
void	remove_quote_in_tokens(t_list *tokens);

/* expansion.c */
int		expansion(t_list *tokens, t_list *env);
char	*get_env_str(char *str, t_list *env, int key_start, int key_end);
int		get_last_name_idx(char *str, int end);

/* parsing.c */
t_list	*parsing(char *str, t_list *env, char *prompt);

/* tokenize.c */
t_list	*tokenize(char *str, int re_token);

/* utils.c */
void	print_node(t_list *tokens);
int		ft_isspace(char c);
int		get_last_simplecmd_idx(char *str, int *idx, int re_token);
int		get_close_quote_idx(char *str, int last_idx, char c);
void	token_free(void	*ptr);
t_list	*ft_tokenlistdup(t_list *node);

//executing
void	start_execute(t_list *parsed, char **envp);
//execute_utils.c
pid_t	fork_pid(void);
//heredoc.c
void	handle_heredoc(t_list *parsed);
void	run_heredoc(t_list *redirect, int doc_nb);
void	read_heredoc(char *doc_name, t_list *parsed);
int		cnt_heredoc(t_list *parsed);
char	*make_heredoc_name(int nb);
//redirect.c
void	handle_redirection(t_list *cmds, int *pipe_fd);
void	handle_inredirection(t_token *token);
void	handle_outredirection(t_token *token);
void	handle_append(t_token *token);
//
void	ft_test(t_list *cmds);
#endif
