/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_vars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:27:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/10 18:03:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

char	*cat_keyvalue(t_env *env)
{
	char	*temp;
	char	*envp;

	temp = ft_strjoin(env->key, "=");
	envp = ft_strjoin(temp, env->value);
	free(temp);
	return (envp);
}

void	slash_check(char *cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			fd = open(cmd, O_RDWR);
			if (fd < 0 && errno == 21)
				exec_error_manager(PROMPT_ERROR, cmd, 126);
			if (access(cmd, F_OK) == -1)
				exec_error_manager(PROMPT_ERROR, cmd, 127);
			if (access(cmd, X_OK) == -1)
				exec_error_manager(PROMPT_ERROR, cmd, 126);
		}
		i++;
	}
}

char	*cat_path(char **path, char *cmd, size_t path_len)
{
	char	*rt_str;
	size_t	cmd_len;
	size_t	i;

	i = 0;
	cmd_len = ft_strlen(cmd);
	rt_str = malloc(sizeof(char) * (path_len + cmd_len + 2));//path 길이 + cmd길이 + / + '\0' 
	while (i < path_len)
	{
		rt_str[i] = **path;
		(*path)++;
		i++;
	}
	rt_str[i] = '/';
	i++;
	while (i < path_len + cmd_len + 1)
	{
		rt_str[i] = *cmd;
		cmd++;
		i++;
	}
	rt_str[i] = '\0';//수정
	return (rt_str);
}

int	env_cnt(t_list *env)
{
	int	cnt;

	cnt = 0;
	env = env->next;
	while (env)
	{
		if (((t_env *)(env->content))->value_null != TRUE)
			cnt++;
		env = env->next;
	}
	return (cnt);
}

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
