/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/05 22:12:43 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

int	cnt_simplecmd(t_list *cmd)
{
	int	cnt;

	cnt = 0;
	while (cmd)
	{
		if (((t_token *)(cmd->content))->type == SIMPLECMD)
			cnt++;
		cmd = cmd->next;
	}
	return (cnt);
}

char	**make_exe_argv(t_list *cmd, t_list *env)
{
	char	**exe_argv;
	t_list	*temp;
	char	*temp_cmd;
	int		cnt;
	int		i;

	i = 0;
	temp = cmd;
	cnt = cnt_simplecmd(cmd);
	exe_argv = malloc(sizeof(char *) * (cnt + 1));
	//malloc
	temp_cmd = find_path(((t_token *)(cmd->content))->exp_value, env);
	if (temp_cmd == 0)
		exit(errno);//마지막으로 세팅된 errno가 access함수
	free(((t_token *)(cmd->content))->exp_value);
	((t_token *)(cmd->content))->exp_value = temp_cmd;
	temp = temp->next;
	while (temp)
	{
		exe_argv[i] = ((t_token *)(temp->content))->exp_value;
		i++;
		temp = temp->next;
	}
	exe_argv[i] = NULL;
	return (exe_argv);
}

char	**make_exe_envp(t_list *env)
{
	t_env	*one_env;
	int		i;
	int		cnt;
	char	*temp_key;
	char	*temp_value;
	char	*temp_envp;
	char	**exe_envp;

	i = 0;
	cnt = ft_lstsize(env);
	exe_envp = malloc(sizeof(char *) * (cnt + 1));
	while (env)
	{
		one_env = (t_env *)(env->content);
		temp_key = one_env->key;
		temp_value = one_env->key;
		temp_envp = malloc(sizeof(char) * (ft_strlen(temp_key) + ft_strlen(temp_value) + 2));
		while (*temp_key)
		{
			*temp_envp = *temp_key;
			temp_envp++;
			temp_key++;
		}
		*temp_envp = '=';
		temp_envp++;
		while (*temp_value)
		{
			*temp_envp = *temp_value;
			temp_envp++;
			temp_value++;
		}
		*temp_envp = '\0';
		exe_envp[i] = temp_envp - (ft_strlen(temp_key) + ft_strlen(temp_value) + 1);
		i++;
		env = env->next;
	}
	return (exe_envp);//얘는 싹 free해야함
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}