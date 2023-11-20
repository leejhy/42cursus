/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:49:24 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/20 16:49:52 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_nl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strchr(char *str)
{
	while (str && *str)//NULL 처리
	{
		if (*str == '\n')
		{
			str++;
			return (str);
		}
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	i = 0;
	s1_len = 0;
	if (!s1 || !*s1)//첫 인덱스가 NULL 이거나, 널문자이면
		return (NULL);
	while (s1[s1_len])
		s1_len++;
	str = malloc(sizeof(char) * (s1_len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
//	if (s1)
//		free(s1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	i = 0;
	while (s1 && s1[i])
		i++;
	s1_len = i;
	i = 0;
	while (s2 && s2[i])
		i++;
	s2_len = i;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - (s1_len + s2_len));
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (str);
}
