/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:37:59 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/19 18:23:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static size_t	ft_wordcnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
			cnt++;
		while (*s && !is_sep(*s, c))
			s++;
	}
	return (cnt);
}

static char	*ft_splitdup(const char *s, char c)
{
	char		*word;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	while (!is_sep(*(s + len), c) && *(s + len))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		*(word + i) = *(s + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static void	ft_frees(char **strings, size_t	idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(*(strings + i));
		i++;
	}
	free(strings);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	**strings;

	i = 0;
	word = ft_wordcnt(s, c);
	strings = malloc(sizeof(char *) * (word + 1));
	if (!strings)
		return (NULL);
	while (s && i < word)
	{
		while (*s && is_sep(*s, c))
			s++;
		*(strings + i) = ft_splitdup(s, c);
		if (!*(strings + i))
		{
			ft_frees(strings, i);
			return (NULL);
		}
		while (*s && !is_sep(*s, c))
			s++;
		i++;
	}
	*(strings + i) = NULL;
	return (strings);
}
