/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:21:20 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 16:07:38 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcnt(char const *s, char c)
{
	size_t	iter;
	size_t	str_cnt;

	iter = 0;
	str_cnt = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		str_cnt++;
	while (s[iter + 1])
	{
		if (s[iter] == c && s[iter + 1] != c)
			str_cnt++;
		iter++;
	}
	return (str_cnt);
}

static void	ft_strchr_not(char **str_pointer, char c)
{
	char	*temp;

	temp = *str_pointer;
	while (*temp == c && *temp)
		temp++;
	*str_pointer = temp;
}

static char	*ft_get_split_str(char **str_pointer, char c)
{
	char	*temp;
	char	*res;
	size_t	size;

	size = 0;
	temp = *str_pointer;
	while (*temp != c && *temp)
	{
		size++;
		temp++;
	}
	while (*temp == c && *temp)
		temp++;
	res = ft_substr(*str_pointer, 0, size);
	*str_pointer = temp;
	return (res);
}

static char	**ft_free_all(char **strl, size_t size)
{
	size_t	iter;

	iter = 0;
	while (iter < size)
	{
		free(strl[iter]);
		iter++;
	}
	free(strl);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	iter;
	size_t	str_cnt;
	char	*temp;
	char	**res;

	if (!s)
		return (0);
	str_cnt = ft_strcnt(s, c);
	iter = 0;
	temp = (char *)s;
	res = (char **)ft_calloc(str_cnt + 1, sizeof(char *));
	if (!res)
		return (0);
	ft_strchr_not(&temp, c);
	while (iter < str_cnt)
	{
		res[iter] = ft_get_split_str(&temp, c);
		if (res[iter++] == 0)
			return (ft_free_all(res, str_cnt + 1));
	}
	return (res);
}
