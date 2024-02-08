/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/07 20:50:19 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
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
