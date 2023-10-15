/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:02 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 18:37:57 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;

	i = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	while (i < src_length)
	{
		*(dest + dest_length + i) = *(src + i);
		i++;
	}
	*(dest + dest_length + i) = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	*str = '\0';
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}
