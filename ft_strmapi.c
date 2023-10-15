/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:22:54 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 18:34:35 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s && *(s + len))
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(str);
	if (s || *s)
		return (NULL);
	str = malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = (*f)(i, *(s + i));
		i++;
	}
	return (str);
}
