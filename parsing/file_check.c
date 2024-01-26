/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:35:57 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 18:03:56 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] && s2[i]) && i + 1 < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

size_t	ft_word_cnt(char *str, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != '\n')
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

void	filename_frees(char **ptr)
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

void	filename_check(char *str)
{
	char	**strings;
	size_t	word_cnt;
	size_t	i;

	i = 0;
	word_cnt = ft_word_cnt(str, '.');
	if (word_cnt == 0)
		file_error();
	strings = malloc(sizeof(char *) * (word_cnt + 1));
	if (!strings)
		malloc_failed();
	while (i < word_cnt)
	{
		while (*str && *str == '.')
			str++;
		if (*str)
			strings[i] = ft_strdup(str, '.');
		while (*str && *str != '.')
			str++;
		i++;
	}
	strings[i] = NULL;
	if (ft_strncmp(strings[i - 1], "fdf", 4) != 0)//무조건 1개 이상이니까 괜찮
		file_error();
	filename_frees(strings);
}
