/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:40:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/13 19:59:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}


char	*ft_strdup(const char *s1, size_t read_size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (read_size + 1));
	if (!str)
		return (NULL);
	while (i < read_size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
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

int	ft_withlf(char *buf, int *flag)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			i++;
			*flag = 1;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*get_str(char *str, char *buf, int read_size)
{
	char	*temp;
	char	*tmp_str;

	tmp_str = str;
	temp = ft_strdup(buf, read_size);
	if (!temp)
		return (NULL);
	str = ft_strjoin(str, temp);
	if (!str)
		return (NULL);
	if (tmp_str)
		free(tmp_str);
	free(temp);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) <= start)
		return ("");
	if (len <= ft_strlen(s) - start)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
