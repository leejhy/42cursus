/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/05 22:09:52 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

t_list	*get_env_list(char **envp)
{
	t_list	*res;
	t_list	*node;
	t_env	*env;

	res = NULL;
	res = add_env_manual(res, "OLDPWD", "", TRUE);
	res = add_env_manual(res, "?", "0", FALSE);
	while (*envp)
	{
		env = get_env_1(*envp);
		if (env == NULL)
			return (NULL);
		node = ft_lstnew(env);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&res, node);
		envp++;
	}
	return (res);
}

char	*cat_path(char *cmd, t_list *env)
{
	t_env	*temp_env;
	char	*path;
	char	*temp_path;
	size_t	len;
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
		while (path[len] != ':')
			len++;
		temp_path = ft_substr(path, 0, len);
		printf("%s\n", temp_path);
		path += len;
	}
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
	t_list *env;
	char	*temp;
	if (argc > 1000)
		return 0;
	if (argv == NULL)
		return (0);
	env = get_env_list(envp);
	temp = cat_path("ls", env);
}
