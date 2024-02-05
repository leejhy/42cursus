/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 20:00:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	f(void){system("leaks minishell");}

/**
 * change form by envp
 * char **envp -> t_list *env
 * env->content = t_env *
*/
t_env	*get_env_1(char *envp)
{
	t_env	*env;
	int		equal_idx;

	env = ft_calloc(1, sizeof(t_env));
	if (env == NULL)
		return (NULL);
	equal_idx = (size_t)(ft_strchr(envp, '=') - envp);
	env->key = ft_substr(envp, 0, equal_idx);
	if (env->key == NULL)
		return (NULL);
	env->value = ft_substr(envp, equal_idx + 1, ft_strlen(envp));
	env->value_null = FALSE;
	if (env->value == NULL)
		return (NULL);
	return (env);
}

/**
 * add front {key : "?", value : "0"} to env
*/
t_list	*add_env_manual(t_list *env, char *key, char *value, int value_null)
{
	t_env	*tmp_env;
	t_list	*node;

	tmp_env = ft_calloc(1, sizeof(t_env));
	if (tmp_env == NULL)
		return (NULL);
	tmp_env->key = ft_strdup(key);
	if (tmp_env->key == NULL)
		return (NULL);
	tmp_env->value = ft_strdup(value);
	if (tmp_env->value == NULL)
		return (NULL);
	tmp_env->value_null = value_null;
	node = ft_lstnew(tmp_env);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(&node, env);
	return (node);
}

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


int	main(int argc, char *argv[], char *envp[])
{
	t_list	*parsed;
	t_list	*env;
	char	*str;
	char	*prompt;

	// for (int i = 0; envp[i]; i++)
	// 	printf("envp[%d] : [%s]\n", i, envp[i]);
	// atexit(f);
	prompt = ft_strjoin(&argv[0][2], " : ");
	env = get_env_list(envp);
	// char	*argvv[] = {"export", "OLDPWD=123", NULL};
	// builtin_export(2, argvv, env, prompt);
	// builtin_unset(argc, argv, env, prompt);
	// builtin_env(argc, argv, env, prompt);
	// builtin_export(1, argv, env, prompt);
	// builtin_cd(argc, argv, env, prompt);
	str = NULL;
	argc = 0;
	envp = 0;
	while (1 && 0)
	{
		str = readline(prompt);
		parsed = parsing(str, env, prompt);
		if (!str)
			break ;
		if (ft_strlen(str) > 0)
			add_history(str);
		start_execute(parsed, env);
		free(str);
	}
	free(prompt);
	exit(0);
	return (0);
}
