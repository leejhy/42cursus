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

char	*cat_path(char *cmd, t_list *env)
{
	t_env	*temp_env;
	char	*path;
	char	*temp_path;
	size_t	len;

	path = NULL;
	cmd = NULL;
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
	while (path)
	{
		len = 0;
		while (path && path[len] != ':')
			len++;
		temp_path = ft_substr(path, 0, len);
		path++;
	}
	return (cmd);
}
