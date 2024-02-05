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
	char	*temp_cmd;
	t_list	*temp;
	int		cnt;
	int		i;

	i = 0;
	temp = cmd;
	cnt = cnt_simplecmd(cmd);
	exe_argv = malloc(sizeof(char *) * (cnt + 1));
	//handle malloc fail
	//
	
	temp_cmd = cat_path(((t_token *)(cmd->content))->exp_value, env);
	// if (temp != NULL)
	// 	if (access(((t_token *)(cmd->content))->exp_value, F_OK & X_OK) == 0)
			//이대로 ㄱ
	// while (temp)
	// {
	// 	if (((t_token *)(temp->content))->type == SIMPLECMD)
	// 	{
	// 		exe_argv[i] = ((t_token *)(temp->content))->exp_value;
	// 		i++;
	// 	}
	// 	temp = temp->next;
	// }
	// exe_argv[i] = NULL;
	return (exe_argv);
}

char	**make_exe_envp(t_list *env)
{
	t_env	*one_env;
	int		cnt;
	char	**exe_envp;

	cnt = ft_lstsize(env);
	exe_envp = malloc(sizeof(char *) * (cnt + 1));
	while (env)
	{
		one_env = (t_env *)(env->content);
		// if (one_env->key[0] != '?')
		// {
		// printf("%s",one_env->key);
		// printf("=");
		// printf("%s\n",one_env->value);
		// }
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