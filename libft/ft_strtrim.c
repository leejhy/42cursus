/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:05 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/02 20:47:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_front_set(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (*(s1 + cnt) && is_set(*(s1 + cnt), set))
		cnt++;
	return (cnt);
}

static size_t	ft_rear_set(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	cnt = 0;
	while (cnt < s1_len && is_set(*(s1 + (s1_len - 1 - cnt)), set))
		cnt++;
	return (cnt);
}

static char	*ft_error(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_len;
	size_t	front;
	size_t	rear;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	front = ft_front_set(s1, set);
	rear = ft_rear_set(s1, set);
	if (s1_len == front || s1_len == rear)
	{
		str = ft_error();
		return (str);
	}
	str = malloc(sizeof(char) * (s1_len - front - rear + 1));
	if (!str)
		return (NULL);
	while (*(s1 + front + i) && i < s1_len - rear - front)
	{
		*(str + i) = *(s1 + front + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
