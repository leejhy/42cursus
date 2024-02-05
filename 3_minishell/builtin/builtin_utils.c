/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:47:19 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_perror_manager(\
		char *_prompt, char *_cmd, char *_argument, char *_strerror)
{
	if (_prompt)
		ft_putstr_fd(_prompt, 2);
	if (_cmd)
		ft_putstr_fd(_cmd, 2);
	ft_putstr_fd(": ", 2);
	if (_argument)
		ft_putstr_fd(_argument, 2);
	if (_strerror)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(_strerror, 2);
	}
	ft_putendl_fd("", 2);
}

void	builtin_env_error_message(\
		char *_prompt, char *_cmd, char *_argument, char *_strerror)
{
	if (_prompt)
		ft_putstr_fd(_prompt, 2);
	if (_cmd)
		ft_putstr_fd(_cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putchar_fd('`', 2);
	if (_argument)
		ft_putstr_fd(_argument, 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(": ", 2);
	if (_strerror)
		ft_putstr_fd(_strerror, 2);
	ft_putendl_fd("", 2);
}

int	is_valid_identifier(char *str)
{
	int	idx;

	if (('0' <= str[0] && str[0] <= '9') || \
		str[0] == '\0' || !(ft_isalpha(str[0]) || str[0] == '_'))
		return (FALSE);
	idx = 0;
	while (str[idx] && str[idx] != '=')
	{
		if (!(ft_isalnum(str[idx]) || str[idx] == '_'))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

t_list	*get_list_env(char *key, t_list *env)
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
			return (env);
		}
		env = env->next;
	}
	return (NULL);
}

char	**make_argv(char *key, char *argv1)
{
	char	**res;

	res = ft_calloc(2, sizeof(char *));
	res[0] = ft_strdup("export");
	res[1] = ft_strjoin(key, argv1);
	return (res);
}
