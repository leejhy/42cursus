/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:07:46 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/19 13:36:34 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	if (size == 0 || count == 0)
		return (0);
	i = 0;
	temp = malloc(size * count);
	if (temp == NULL)
		return (0);
	while (i < count * size)
	{
		temp[i++] = '\0';
	}
	return (temp);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	if (src == NULL)
		return (0);
	i = gnl_strlen(dst);
	j = 0;
	while (src[j] != '\0' && i + j + 1 < destsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (i > destsize)
		return (destsize + gnl_strlen(src));
	return (i + gnl_strlen(src));
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (0);
	size = gnl_strlen(s);
	if ((size_t)start >= size)
		return (0);
	else if (len > size - (size_t)start)
		len = size - (size_t)start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char			*result;
	size_t			size;

	size = gnl_strlen(s1);
	size += gnl_strlen(s2);
	result = gnl_calloc(sizeof(char), size + 1);
	if (result == NULL)
	{
		free(s1);
		return (0);
	}
	if (s1 != NULL)
	{
		gnl_strlcat(result, s1, gnl_strlen(s1) + 1);
		if (result == NULL)
		{
			free(s1);
			return (NULL);
		}
	}
	gnl_strlcat(result, s2, size + 1);
	free(s1);
	if (result == NULL)
		return (NULL);
	return (result);
}
