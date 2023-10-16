/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:38:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 18:35:52 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_length;
	size_t	i;

	i = 0;
	s_length = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (s_length <= start)
		return (NULL);
	while (s && i < len && *(s + start + i))
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	// if (!*str)
	// 	return (NULL);
	return (str);
}
