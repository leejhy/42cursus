/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:40:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/06 21:51:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//helper functions

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!arr)
		return (NULL);
	while (i < s1_len)
	{
		*(arr + i) = *(s1 + i);
		i++;
	}
	*(arr + i) = '\0';
	return ((char *)arr);
}