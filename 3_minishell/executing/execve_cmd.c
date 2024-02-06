/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:34:21 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/05 22:14:34 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

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
		rt_str[i] = (*path)++;
		(*path)++;
		i++;
	}
	rt_str[i] = '/';
	i++;
	while (i < path_len + cmd_len + 2)
	{
		rt_str[i] = *cmd;
		cmd++;
		i++;
	}
	rt_str[i] = '\0';//수정
	return (rt_str);
}

char	*get_path(t_list *env)
{
	t_env	*temp_env;
	char	*path;

	while (env)
	{
		temp_env = (t_env *)(env->content);
		if (ft_strncmp(temp_env->key, "PATH", 5) == 0)
		{
			path = temp_env->value;
			break ;
		}
		env = env->next;
	}
	return (path);
}

char	*find_path(char *cmd, t_list *env)
{
	char	*path;
	char	*path_cmd;
	size_t	len;

	path = NULL;
	path = get_path(env);
	if (access(cmd, F_OK & X_OK) == 0)
		return (cmd);
	while (*path)
	{
		len = 0;
		while (path[len] && path[len] != ':')
			len++;
		path_cmd = cat_path(&path, cmd, len);
		if (access(path_cmd, F_OK & X_OK) == 0)
			return (path_cmd);
		if (*path != '\0')
			path++;
	}
	return (0);
}
