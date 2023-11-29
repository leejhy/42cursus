/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:49:24 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/26 11:02:38 by junhylee         ###   ########.fr       */
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
	while (str && *str)
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
	if (!s1 || !*s1)
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
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*str;
	char	*temp_s1;
	size_t	s1_len;

	temp_s1 = s1;
	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	if (temp_s1)
		free(temp_s1);
	return (str - (s1_len + s2_len));
}

int	ft_error(int fd, t_list **head)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, NULL, 0) == -1)
	{
		ft_delnode(head, fd);
		return (0);
	}
	return (1);
}
