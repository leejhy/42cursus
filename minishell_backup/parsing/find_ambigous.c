/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ambigous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 15:34:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	get_word_cnt(char *str)
{
	int	idx;
	int	cnt;

	idx = 1;
	cnt = 0;
	if (!ft_isspace(str[0]))
		cnt++;
	while (str && str[0] && str[idx])
	{
		if (ft_isspace(str[idx - 1]) && !ft_isspace(str[idx]))
			cnt++;
		idx++;
	}
	return (cnt);
}


int	is_ambiguous(char *str, t_list *env)
{
	int	str_idx;
	int	flag;
	int	res;

	str_idx = 0;
	flag = 0;
	while (str && str[str_idx])
	{
		if (flag == 0 && (str[str_idx] == '\'' || str[str_idx] == '\"'))
			flag = str[str_idx];
		else if (flag != 0 && (str[str_idx] == flag))
			flag = 0;
		if (flag != '\'' && flag != '\"' && str[str_idx] == '$' && \
		(ft_isalnum(str[str_idx + 1]) || ft_strchr("\'\"_", str[str_idx + 1])))
		{
			res = get_word_cnt(get_env_str(str, env, str_idx, \
							get_last_name_idx(str, str_idx)));
			if (res != 1)
				return (TRUE);
			str_idx = get_last_name_idx(str, str_idx);
		}
		else
			str_idx++;
	}
	return (FALSE);
}

void	check_ambigious(t_list *tokens, t_list *env)
{

	while (tokens != NULL)
	{
		((t_token *)tokens->content)->is_ambiguous = \
			is_ambiguous(((t_token *)tokens->content)->value, env);
		tokens = tokens->next;
	}
}
