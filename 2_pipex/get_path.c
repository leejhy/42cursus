/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:15:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/16 22:42:14 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_bonus.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] && s2[i]) && i + 1 < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_get_path(char **envp)
{
	char	*str_path;
	size_t	i;

	i = 0;
	str_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			str_path = envp[i];
			break ;
		}
		i++;
	}
	while (*str_path != '=')
		str_path++;
	str_path++;
	return (str_path);
}

char	*ft_path_cmd(char *find_path, char *path, char *cmd)
{
	if (*path == '\0')
		return (NULL);
	while (*path && *path != ':')
	{
		*find_path = *path;
		path++;
		find_path++;
	}
	if (*path == ':')
		path++;
	*find_path = '/';
	find_path++;
	while (*cmd)
	{
		*find_path = *cmd;
		find_path++;
		cmd++;
	}
	*find_path = '\0';
	return (path);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	*path;
	char	*find_path;
	size_t	path_len;

	path = ft_get_path(envp);
	while (*path)
	{
		path_len = 0;
		while (path[path_len] && path[path_len] != ':')
			path_len++;
		find_path = malloc(sizeof(char) * (path_len + ft_strlen(cmd) + 2));
		if (!find_path)
			malloc_failed();
		path = ft_path_cmd(find_path, path, cmd);
		if (access(find_path, F_OK | X_OK) == 0)
		{
			free(cmd);
			return (find_path);
		}
		else
			free(find_path);
	}
	ft_error(errno);
	return (0);
}

char	**get_cmd(char *cmd, char **envp)
{
	char	**split_str;
	size_t	i;

	i = 0;
	if (cmd == NULL || *cmd == '\0')
		return (NULL);
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
		return (NULL);
	split_str = ft_split(cmd);
	if (access(split_str[0], F_OK & X_OK) == 0)
		return (split_str);
	split_str[0] = ft_find_path(split_str[0], envp);
	return (split_str);
}
