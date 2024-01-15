/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:26 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/12 18:23:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_word_cnt(char *str, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str)
			cnt++;
		while (*str && *str != sep)
			str++;
	}
	return (cnt);
}

char	*ft_strdup(char *str, char sep)
{
	char	*rt_str;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	rt_str = malloc(sizeof(char) * (len + 1));
	if (!rt_str)
		malloc_failed();
	while (i < len)
	{
		rt_str[i] = str[i];
		i++;
	}
	rt_str[i] = '\0';
	return (rt_str);
}

void	split_frees(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char *str, char **envp)
{
	char	**strings;
	size_t	word_cnt;
	size_t	i;

	i = 0;
	word_cnt = ft_word_cnt(str, ' ');
	strings = malloc(sizeof(char *) * (word_cnt + 1));
	if (!strings)
		malloc_failed();
	while (i < word_cnt)
	{
		while (*str && *str == ' ')
			str++;
		if (*str)
			strings[i] = ft_strdup(str, ' ');
		while (*str && *str != ' ')
			str++;
		i++;
	}
	strings[i] = NULL;
	strings[0] = ft_find_path(strings[0], envp);
	return (strings);
}
