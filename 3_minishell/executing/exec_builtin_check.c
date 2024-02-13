/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:51:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 18:35:50 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	exec_check_builtin(t_list *curr_cmd)
{
	t_token	*cmd_name;
	t_list	*cmd;

	cmd = curr_cmd;
	if (get_simple_cmd_cnt(\
		(t_list *)((t_cmd *)cmd->content)->simple_cmd) == 0)
		return (FALSE);
	cmd_name = ((t_list *)((t_cmd *)cmd->content)->simple_cmd)->content;
	if (ft_strncmp(cmd_name->exp_value, "cd", 3) == 0 || \
		ft_strncmp(cmd_name->exp_value, "echo", 5) == 0 || \
		ft_strncmp(cmd_name->exp_value, "env", 4) == 0 || \
		ft_strncmp(cmd_name->exp_value, "exit", 5) == 0 || \
		ft_strncmp(cmd_name->exp_value, "export", 7) == 0 || \
		ft_strncmp(cmd_name->exp_value, "pwd", 4) == 0 || \
		ft_strncmp(cmd_name->exp_value, "unset", 6) == 0)
		return (TRUE);
	return (FALSE);
}

void	exec_run_built_in(t_cmd *cmd, t_list *env, char *cmd_name)
{
	char	**argv;
	int		argc;

	argc = get_simple_cmd_cnt(cmd->simple_cmd);
	argv = get_argv(cmd->simple_cmd);
	if (ft_strncmp(cmd_name, "cd", 3) == 0)
		g_last_exitcode = builtin_cd(argc, argv, env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "echo", 5) == 0)
		g_last_exitcode = builtin_echo(argc, argv);
	else if (ft_strncmp(cmd_name, "env", 4) == 0)
		g_last_exitcode = builtin_env(argc, argv, env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "exit", 5) == 0)
		g_last_exitcode = exec_builtin_exit(argc, argv, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "export", 7) == 0)
		g_last_exitcode = builtin_export(argc, argv, env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "pwd", 4) == 0)
		g_last_exitcode = builtin_pwd(env);
	else if (ft_strncmp(cmd_name, "unset", 6) == 0)
		g_last_exitcode = builtin_unset(argc, argv, env, PROMPT_ERROR);
	if (ft_strncmp(cmd_name, "exit", 5) == 0 && g_last_exitcode == -1)
		g_last_exitcode = 1;
	else if (ft_strncmp(cmd_name, "exit", 5) == 0 && g_last_exitcode != -1)
		exit((unsigned char)g_last_exitcode);
	exit((unsigned char)g_last_exitcode);
}
