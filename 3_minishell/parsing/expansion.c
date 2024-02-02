/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/01 21:50:47 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	get_last_name_idx(char *str, int end)
{
	end++;
	while (str[end])
	{
		if (!(ft_isalnum(str[end]) || str[end] == '_'))
			break ;
		end++;
	}
	return (end);
}

char	*get_env_str(char *str, t_list *env, int key_start, int key_end)
{
	char	*key;

	while (env != NULL)
	{
		key = ((t_env *)env->content)->key;
		if ((int)ft_strlen(key) == (key_end - key_start - 1) && \
			ft_strncmp(&str[key_start + 1], key, ft_strlen(key)) == 0)
			return (((t_env *)env->content)->value);
		env = env->next;
	}
	return ("");
}

int	get_expansion_size(char *str, t_list *env)
{
	int		idx;
	int		end;
	int		size;

	size = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '$' && str[idx + 1] != '$' && \
			(ft_isalnum(str[idx + 1]) || str[idx + 1] == '_'))
		{
			end = get_last_name_idx(str, idx);
			size += ft_strlen(get_env_str(str, env, idx, end));
			idx = end;
		}
		else
		{
			size++;
			idx++;
		}
	}
	return (size);
}

void	expansion_simplecmd(char *str, char *res, int size, t_list *env)
{
	int	str_idx;
	int	res_idx;
	int	end;
	int	flag;

	str_idx = 0;
	res_idx = 0;
	flag = 0;
	while (res_idx < size + 1)
	{
		if (flag == 0 && (str[str_idx] == '\'' || str[str_idx] == '\"'))
			flag = str[str_idx];
		else if (flag != 0 && (str[str_idx] == flag))
			flag = 0;
		if (flag != '\'' && str[str_idx] == '$' && \
			(str[str_idx + 1] == '\'' || str[str_idx + 1] == '\"' || \
			ft_isalnum(str[str_idx + 1]) || str[str_idx + 1] == '_'))
		{
			end = get_last_name_idx(str, str_idx);
			ft_strlcat(res, get_env_str(str, env, str_idx, end), size + 1);
			res_idx += ft_strlen(get_env_str(str, env, str_idx, end));
			str_idx = end;
		}
		else
			res[res_idx++] = str[str_idx++];
	}
}

int	expansion(t_list *tokens, t_list *env)
{
	t_token	*tok;
	int		size;
	char	*expansion_res;

	while (tokens != NULL)
	{
		tok = ((t_token *)tokens->content);
		if (tok->type != HEREDOC && tok->value != NULL)
		{
			size = get_expansion_size(tok->value, env);
			expansion_res = ft_calloc(size + 1, sizeof(char));
			if (expansion_res == NULL)
				return (FALSE);
			expansion_simplecmd(tok->value, expansion_res, size, env);
			tok->exp_value = expansion_res;
		}
		else
		{
			tok->exp_value = tok->value;
			tok->value = NULL;
		}
		tokens = tokens->next;
	}
	return (TRUE);
}
