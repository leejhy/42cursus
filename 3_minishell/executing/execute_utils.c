/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/04 15:40:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	cnt_simplecmd(t_list *lst)
{
	int	cnt;

	while (lst)
	{
		if (((t_token *)(cmd->content))->type == SIMPLECMD)
			cnt++;
		cmd = cmd->next;
	}
	return (cnt);
}

char	**make_exe_argv(t_list *cmd)
{
	char	**exe_argv;
	t_list	*temp;
	int		cnt;
	int		i;

	i = 0;
	temp = cmd;
	cnt = cnt_simplecmd(cmd);
	exe_argv = malloc(sizeof(char *) * (cnt + 1));
	//handle malloc fail
	//
	while (temp)
	{
		if (((t_token *)(temp->content))->type == SIMPLECMD)
		{
			exe_argv[i] = ((t_token *)(temp->content))->exp_value;
			i++;
		}
		temp = temp->next;
	}
	exe_argv[i] = NULL;
	return (exe_argv);
}

char	**make_exe_envp(t_list *env)
{
	t_list	*row_cnt;
	t_env	*one_env;
	int		cnt;
	int		total_len;
	int		i;
	int		j;
	char	**exe_envp;
	char	*str;

	i = 0;
	cnt = ft_lstsize(env);
	exe_envp = malloc(sizeof(char *) * (cnt + 1));
	while (env)
	{
		one_env = (t_env *)(env->content);
		total_len = ft_strlen(one_env->key) + ft_strlen(one_env->value) + 1;
		exe_envp[i] = malloc(sizeof(char) * (total_len + 1));
		str = exe_envp[i];
		while (one_env->key[j])
		{
			str[j] = one_env->key[j];
			j++;
		}
		str[j] = '=';
		j++;
		while (one_env->value[ft_strlen((one_env->key + 1) - j)])
		{
			str[j] = one_env->value[ft_strlen((one_env->key + 1) - j)];
			j++;
		}
		str[j] = '\0';
		i++;
		env = env->next;
	}
	return (exe_envp);
}

pid_t	fork_pid(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);//에러처리
	return (pid);
}