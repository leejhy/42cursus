/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:32:15 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/02 20:50:31 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
