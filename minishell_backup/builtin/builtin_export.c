/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 19:01:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static t_env	*get_env(char *key, t_list *env)
{
	int	equal_idx;

	equal_idx = ft_strlen(key);
	if (ft_strchr(key, '='))
		equal_idx = (int)(ft_strchr(key, '=') - key);
	while (env != NULL)
	{
		if (ft_strlen(((t_env *)env->content)->key) == (size_t)equal_idx && \
			ft_strncmp(((t_env *)env->content)->key, key, equal_idx) == 0)
		{
			return (env->content);
		}
		env = env->next;
	}
	return (NULL);
}

static void	*add_env(char *str, t_list *env)
{
	int		equal_idx;
	t_env	*new_env;
	t_list	*new_node;

	equal_idx = ft_strlen(str);
	new_env = ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		return (NULL);
	new_env->key = FALSE;
	if (ft_strchr(str, '='))
		equal_idx = (int)(ft_strchr(str, '=') - str);
	new_env->key = ft_substr(str, 0, equal_idx);
	if (str[equal_idx] == '=')
		new_env->value = ft_strdup(&str[equal_idx + 1]);
	else
		new_env->value = ft_strdup("");
	if (str[equal_idx] != '=')
		new_env->value_null = TRUE;
	if (new_env->value == NULL)
		return (NULL);
	new_node = ft_lstnew(new_env);
	if (new_node == NULL)
		return (NULL);
	ft_lstadd_back(&env, new_node);
	return (env);
}

static void	*edit_env(char *str, t_list *env)
{
	int		equal_idx;
	t_env	*value;
	char	*new_value;
	int		value_null;

	value_null = FALSE;
	equal_idx = ft_strlen(str);
	if (ft_strchr(str, '='))
		equal_idx = (int)(ft_strchr(str, '=') - str);
	if (str[equal_idx] == '=')
		new_value = ft_strdup(&str[equal_idx + 1]);
	else
		new_value = ft_strdup("");
	if (str[equal_idx] != '=')
		value_null = TRUE;
	if (new_value == NULL)
		return (NULL);
	value = get_env(str, env);
	free(value->value);
	value->value = new_value;
	value->value_null = value_null;
	return (env);
}

static int	builtin_export_print(t_list *env)
{
	env = env->next;
	while (env != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(((t_env *)env->content)->key, 1);
		if (((t_env *)env->content)->value_null == FALSE)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(((t_env *)env->content)->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (0);
}

int	builtin_export(int argc, char **argv, t_list *env, char *prompt)
{
	int	idx;
	int	exitcode;

	idx = 1;
	exitcode = 0;
	if (argc == 1)
		return (builtin_export_print(env));
	while (idx < argc)
	{
		if (is_valid_identifier(argv[idx]))
		{
			if (get_env(argv[idx], env) == NULL)
				env = add_env(argv[idx], env);
			else
				env = edit_env(argv[idx], env);
		}
		else
		{
			builtin_env_error_message(prompt, argv[0], \
					argv[idx], "not a valid identifier");
			exitcode = 1;
		}
		idx++;
	}
	return (exitcode);
}
