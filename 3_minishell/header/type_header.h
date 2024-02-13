/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 14:20:59 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HEADER_H
# define TYPE_HEADER_H
# include "include_header.h"

int	g_last_exitcode;

typedef enum e_token_type
{
	ERROR = 0,
	INREDIRECTION,
	OUTREDIRECTION,
	HEREDOC,
	APPEND,
	PIPE,
	SIMPLECMD
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	char			*exp_value;
	int				is_ambiguous;
}	t_token;

typedef struct s_cmd
{
	t_list			*redirect;
	t_list			*simple_cmd;
	int				next_pipe;
}	t_cmd;

typedef struct s_env
{
	char	*key;
	char	*value;
	int		value_null;
}	t_env;

typedef struct s_info
{
	t_list	*cmd;
	t_list	*env;
	int		pipe_fd[2];
	int		input_fd;
}	t_info;

#endif
