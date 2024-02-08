/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/08 13:38:11 by junhylee         ###   ########.fr       */
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
	if (temp_cmd != 0)
	{
		free(((t_token *)(cmd->content))->exp_value);
		((t_token *)(cmd->content))->exp_value = temp_cmd;
	}
	while (temp)
	{
		exe_argv[i] = ((t_token *)(temp->content))->exp_value;
		i++;
		temp = temp->next;
	}
	exe_argv[i] = NULL;
	return (exe_argv);
}

void	cat_keyvalue(t_env *env, char *temp_envp)
{
	char	*key;
	char	*value;

	key = env->key;
	value = env->value;
	while (*key)
	{
		*temp_envp = *key;//PWD
		temp_envp++;
		key++;
	}//3번
	*temp_envp = '=';
	temp_envp++;//4번
	while (*value)
	{
		*temp_envp = *value;
		temp_envp++;
		value++;//
	}
	*temp_envp = '\0';
}

char	**make_exe_envp(t_list *env)
{
	t_env	*one_env;
	int		i;
	int		cnt;
	char	*temp_envp;
	char	**exe_envp;

	i = 0;
	cnt = ft_lstsize(env);
	exe_envp = malloc(sizeof(char *) * (cnt + 1));
	while (env)
	{
		one_env = (t_env *)(env->content);
		temp_envp = malloc(sizeof(char) * (ft_strlen(one_env->key) + ft_strlen(one_env->value) + 2));
		cat_keyvalue(one_env, temp_envp);
		exe_envp[i] = temp_envp;
		i++;
		env = env->next;
	}
	exe_envp[i] = NULL;
	return (exe_envp);//얘는 싹 free해야함
}

void	wait_prc(int prc_cnt)
{
	int i;
	int	stat;

	i = 0;
	stat = 0;
	while (i < prc_cnt)
	{
		if (wait(&stat) == -1)
			break ;//?
		g_last_exitcode = WEXITSTATUS(stat);
		i++;
	}
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}
