/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/03 18:41:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

// void	f(void){system("leaks minishell");}

/**
 * change form by envp
 * char **envp -> t_list *env
 * env->content = t_env *
*/
t_list	*get_env(char **envp)
{
	t_list	*res;
	t_list	*node;
	t_env	*env;
	int		equal_idx;

	res = NULL;
	while (*envp)
	{
		env = ft_calloc(1, sizeof(t_env));
		if (env == NULL)
			return (NULL);
		equal_idx = (size_t)(ft_strchr(*envp, '=') - *envp);
		env->key = ft_substr(*envp, 0, equal_idx);
		if (env->key == NULL)
			return (NULL);
		env->value = ft_substr(*envp, equal_idx + 1, ft_strlen(*envp));
		if (env->value == NULL)
			return (NULL);
		node = ft_lstnew(env);
		if (node == NULL)
			return (NULL);
		ft_lstadd_back(&res, node);
		envp++;
	}
	return (res);
}

/**
 * add front {key : "?", value : "0"} to env
*/
t_list	*add_exitcode(t_list *env)
{
	t_env	*exitcode;
	t_list	*node;

	exitcode = ft_calloc(1, sizeof(t_env));
	if (exitcode == NULL)
		return (NULL);
	exitcode->key = ft_strdup("?");
	if (exitcode->key == NULL)
		return (NULL);
	exitcode->value = ft_strdup("0");
	if (exitcode->value == NULL)
		return (NULL);
	node = ft_lstnew(exitcode);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(&node, env);
	return (node);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*parsed;
	t_list	*env;
	char	*str;
	char	*prompt;

	// atexit(f);
	env = get_env(envp);
	env = add_exitcode(env);
	prompt = ft_strjoin(&argv[0][2], " : ");
	str = NULL;
	argc = 0;
	envp = 0;
	while (1)
	{
		str = readline(prompt);
		parsed = parsing(str, env, prompt);
		if (!str)
			break ;
		if (ft_strlen(str) > 0)
			add_history(str);
		start_execute(parsed);
		free(str);
	}
	free(prompt);
	exit(0);
	return (0);
}
