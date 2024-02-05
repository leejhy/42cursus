/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:15:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	test(int a)
{
	a = 0;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	f(void){system("leaks minishell");}

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

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*parsed;
	t_list	*env;
	char	*str;
	char	*prompt;

	atexit(f);
	env = get_env(envp);
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
		handle_heredoc(parsed);//HEREDOC -> INREDIRECT
		handle_redirection(parsed, envp);
		free(str);
	}
	free(prompt);
	exit(0);
	return (0);
}
