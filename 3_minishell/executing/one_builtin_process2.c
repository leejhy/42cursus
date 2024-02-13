/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_builtin_process2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:39:38 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 18:43:18 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	check_one_builtin(t_info *info)
{
	t_token	*cmd_name;
	t_list	*cmd;

	cmd = info->cmd;
	if (cmd->next != NULL)
		return (FALSE);
	if (get_simple_cmd_cnt(\
		(t_list *)((t_cmd *)info->cmd->content)->simple_cmd) == 0)
		return (FALSE);
	cmd_name = ((t_list *)((t_cmd *)info->cmd->content)->simple_cmd)->content;
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

void	one_builtin_dup_process_sub(t_token *token)
{
	int	fd;

	if (token->type == INREDIRECTION)
	{
		fd = open(token->exp_value, O_RDONLY);
		if (fd == -1)
			exec_error_manager(PROMPT_ERROR, token->exp_value, -1);
		dup2(fd, STDIN_FILENO);
	}
	else if (token->type == OUTREDIRECTION)
	{
		fd = open(token->exp_value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			exec_error_manager(PROMPT_ERROR, token->exp_value, -1);
		dup2(fd, STDOUT_FILENO);
	}
	else if (token->type == APPEND)
	{
		fd = open(token->exp_value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			exec_error_manager(PROMPT_ERROR, token->exp_value, -1);
		dup2(fd, STDOUT_FILENO);
	}
}

void	one_builtin_dup_process(t_info *info)
{
	t_list	*redirect;

	redirect = ((t_cmd *)((t_list *)info->cmd)->content)->redirect;
	while (redirect)
	{
		if (g_last_exitcode == 0)
			one_builtin_dup_process_sub((t_token *)redirect->content);
		redirect = redirect->next;
	}
}

void	one_builtin_fd_save_load(t_info *info, int flag)
{
	if (flag == SAVE_MODE)
	{
		info->pipe_fd[0] = dup(STDIN_FILENO);
		info->pipe_fd[1] = dup(STDOUT_FILENO);
	}
	else if (flag == LOAD_MODE)
	{
		dup2(info->pipe_fd[0], STDIN_FILENO);
		dup2(info->pipe_fd[1], STDOUT_FILENO);
		close(info->pipe_fd[0]);
		close(info->pipe_fd[1]);
	}
}

void	run_one_builtin_sub(t_info *info, char *cmd_name)
{
	char	**argv;
	int		argc;

	argc = get_simple_cmd_cnt(((t_cmd *)info->cmd->content)->simple_cmd);
	argv = get_argv(((t_cmd *)info->cmd->content)->simple_cmd);
	if (ft_strncmp(cmd_name, "cd", 3) == 0)
		g_last_exitcode = builtin_cd(argc, argv, info->env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "echo", 5) == 0)
		g_last_exitcode = builtin_echo(argc, argv);
	else if (ft_strncmp(cmd_name, "env", 4) == 0)
		g_last_exitcode = builtin_env(argc, argv, info->env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "exit", 5) == 0)
		g_last_exitcode = builtin_exit(argc, argv, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "export", 7) == 0)
		g_last_exitcode = builtin_export(argc, argv, info->env, PROMPT_ERROR);
	else if (ft_strncmp(cmd_name, "pwd", 4) == 0)
		g_last_exitcode = builtin_pwd(info->env);
	else if (ft_strncmp(cmd_name, "unset", 6) == 0)
		g_last_exitcode = builtin_unset(argc, argv, info->env, PROMPT_ERROR);
	if (ft_strncmp(cmd_name, "exit", 5) == 0 && g_last_exitcode == -1)
		g_last_exitcode = 1;
	else if (ft_strncmp(cmd_name, "exit", 5) == 0 && g_last_exitcode != -1)
		exit(g_last_exitcode);
	free(argv);
}
